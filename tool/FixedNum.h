
#ifndef FIXED_NUM_H
#define FIXED_NUM_H

#define MASK ((1 << FIXED_FBITS)-1)

#ifdef SIGNED
#if TOTAL_BITS==8
typedef int8_t TYPE;
typedef int16_t TYPE_DOUBLE_SIZE;
#define INF_POS (TYPE)0x7F
#define INF_NEG (TYPE)0x80
#elif TOTAL_BITS==16
typedef int16_t TYPE; // 16 bits
typedef int32_t TYPE_DOUBLE_SIZE;
#define INF_POS (TYPE)0x7FFF
#define INF_NEG (TYPE)0x8000
#else
typedef int32_t TYPE; // 32 bits
typedef int64_t TYPE_DOUBLE_SIZE;
#define INF_POS (TYPE)0x7FFFFFFF
#define INF_NEG (TYPE)0x80000000
#endif

#else
#if TOTAL_BITS==8
typedef uint8_t TYPE;
typedef uint16_t TYPE_DOUBLE_SIZE;
#define INF_POS (TYPE)0xFF
#define INF_NEG (TYPE)0x00
#elif TOTAL_BITS==16
typedef uint16_t TYPE; // 16 bits
typedef uint32_t TYPE_DOUBLE_SIZE;
#define INF_POS (TYPE)0xFFFF
#define INF_NEG (TYPE)0x0000
#else
typedef uint32_t TYPE; // 32 bits
typedef uint64_t TYPE_DOUBLE_SIZE;
#define INF_POS (TYPE)0xFFFFFFFF
#define INF_NEG (TYPE)0x00000000
#endif
#endif

#define abs(x) ((x) < 0 ? (-(x)) : (x))

typedef TYPE FixedNum;

float getValue(FixedNum x){
	return (x / (float)((TYPE)1 << FIXED_FBITS));
}

FixedNum setValue(float x){
	(*(uint32_t *)&x) = (*(uint32_t *)&x) + ((uint32_t)FIXED_FBITS << 23);
  return (TYPE)round(x);
}

// ARITHMETIC OPERATIONS

FixedNum fxp_sum(const FixedNum left, const FixedNum right){
	#ifdef OVERFLOW_DETECT
	if (left == INF_POS || right == INF_POS)
		return INF_POS;
	if (left == INF_NEG || right == INF_NEG)
		return INF_NEG;
	#endif

	return (left + right);
}

FixedNum fxp_diff(const FixedNum left, const FixedNum right){
	#ifdef OVERFLOW_DETECT
	if (left == INF_POS || right == INF_NEG)
		return INF_POS;
	if (left == INF_NEG || right == INF_POS)
		return INF_NEG;
	#endif

	return (left - right);
}

FixedNum fxp_mul(const FixedNum left, const FixedNum right){
	if (left == 0 || right == 0)
		return ((TYPE)0);

	TYPE_DOUBLE_SIZE aux = (((TYPE_DOUBLE_SIZE)left * (TYPE_DOUBLE_SIZE)right) >> FIXED_FBITS);

	#ifdef OVERFLOW_DETECT
	if (aux > INF_POS)
		return (INF_POS);
	if (aux < INF_NEG)
		return (INF_NEG);
	#endif

	return ((TYPE)aux);
}

FixedNum fxp_div(const FixedNum left, const FixedNum right){
	#ifdef OVERFLOW_DETECT
	if (right == 0)
		return (left > 0 ? (INF_POS) : (INF_NEG));
  if (right == INF_POS || right == INF_NEG)
    return ((TYPE)0);
	#endif

	return ((TYPE)((((TYPE_DOUBLE_SIZE)left) << FIXED_FBITS) / (TYPE_DOUBLE_SIZE)right));
}

FixedNum fxp_pow2(const FixedNum x){
  if (x == INF_POS)
    return (INF_POS);
  if (x == INF_NEG)
    return ((TYPE)0);

  FixedNum k, f, i;

  if (x < 0){
    k = -x;
    i = (k >> FIXED_FBITS);
    if (k & MASK){
      f = (1 << FIXED_FBITS) - (k & MASK);
      i++;
    }
    else
      f = 0;
  }
  else{
    k = x;
    i = (k >> FIXED_FBITS);
    f = (k & MASK);
  }

#ifdef SIGNED
  if (i + FIXED_FBITS >= TOTAL_BITS-1)
    return (x > 0 ? (INF_POS) : ((TYPE)0));
#else
  if (i + FIXED_FBITS >= TOTAL_BITS)
    return (x > 0 ? (INF_POS) : ((TYPE)0));
#endif

  FixedNum ans = ((TYPE)0x00000400);
  if (f > 0)
    ans = fxp_sum(fxp_mul(fxp_sum(fxp_mul(0x0000015f, f), 0x00000299), f), 0x00000404);

  if (x > 0)
    ans <<= i;
  else
    ans >>= i;

  return ans;
}

// NEED TO SET LIMITS FOR EACH DATA TYPE
FixedNum fxp_exp(const FixedNum x){
	if (x == INF_POS)
		return (INF_POS);
	if (x == INF_NEG)
		return ((TYPE)0);

	return fxp_pow2(fxp_mul(x, 0x000005c5));
}

// SIGNED has to be defined
FixedNum fxp_log2(FixedNum x){
	if (x <= 0)
		return ((TYPE)0);

	FixedNum n = 0;

	while (x < ((TYPE)1 << FIXED_FBITS)){
		n--;
		x <<= 1;
	}

	while (x >= ((TYPE)2 << FIXED_FBITS)){
		n++;
		x >>= 1;
	}

	FixedNum lf = fxp_sum(fxp_mul(fxp_sum(fxp_mul(0xfffffea7, x), 0x000007fb), x), 0xfffff967);

	return ((n << FIXED_FBITS) + lf);
}

FixedNum fxp_pow(FixedNum x, FixedNum y){
	return fxp_pow2(fxp_mul(y, fxp_log2(x)));
}

#endif
