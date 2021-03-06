

#include <Arduino.h>
#include <SD.h>
#include <SPI.h>

#include "fxp/pen_svm_fxp.h"
#define FP_TEST
#define FILE_NAME "pen_test.txt"
//#define LOGISTIC

#define BUFFER_SIZE 50

File test;

uint32_t acc = 0;
volatile uint32_t t = 0;
volatile uint32_t tt = 0;
volatile uint32_t mx = 0;

float readFloat(File myFile){
  char buffer[50];
  byte index = 0;

  while (myFile.available()){
    char aChar = myFile.read();

    if (aChar == ',' || aChar == '\n' || aChar == '\r' || aChar == EOF){
      buffer[index] = '\0';
      float aVal = atof(buffer);
      return aVal;
    }

    buffer[index++] = aChar;
  }
}

void setup()
{
  Serial.begin(115200);
  delay(1000);

  Serial.println("Begin");

  if (!SD.begin(47)) {
    Serial.println("initialization failed!");
    while (1);
  }

  for (int i = 0; i < 10; i++){
    Serial.println(i);
    delay(400);
  }

#ifndef LOGISTIC
	initConnections();
#endif

  uint32_t total1 = 0;

  test = SD.open(FILE_NAME);
  if (!test) {
    Serial.println("cant open file!");
    while (1);
  }

  while(true){
	   float instance_tmp[INPUT_SIZE+1];
     if (!test.available()) break;

	   for (int j = 0; j <= INPUT_SIZE; j++){
       if (!test.available()){
         Serial.println("error reading!");
         while (1);
       }
       instance_tmp[j] = readFloat(test);
     }
     int label = instance_tmp[CLASS_INDEX];
     instance_tmp[CLASS_INDEX] = 0;

     #if defined(FP_TEST)
     for (int j = 0; j <= INPUT_SIZE; j++) instance[j] = setValue(instance_tmp[j]);
     #else
     for (int j = 0; j <= INPUT_SIZE; j++) instance[j] = instance_tmp[j];
     #endif

     int result = classify();
     if (result == label) acc++;
     total1++;
     if (total1 % 1000 == 0) Serial.println(total1);
   }

   test.close();
   uint32_t total2 = 0;

   char buffer[BUFFER_SIZE+5];
   int tam_buffer = 0;

   for (int ii = 0; ii < 10; ii++){
     test = SD.open(FILE_NAME);
     if (!test) {
       Serial.println("cant open file!");
       while (1);
     }

     while(true){
	      float instance_tmp[INPUT_SIZE+1];

        if (!test.available()){
          Serial.print("finished!\n-------------------------------\ntotal: ");
          Serial.print(total1);
          Serial.print(" ");
          Serial.print(total2);
          Serial.println("\n-------------------------------");
          break;
        }

	      for (int j = 0; j <= INPUT_SIZE; j++){
          if (!test.available()){
            Serial.println("error reading!");
            while (1);
          }
          instance_tmp[j] = readFloat(test);
        }
        int label = instance_tmp[CLASS_INDEX];
        instance_tmp[CLASS_INDEX] = 0;

        #if defined(FP_TEST)
        for (int j = 0; j <= INPUT_SIZE; j++) instance[j] = setValue(instance_tmp[j]);
        #else
        for (int j = 0; j <= INPUT_SIZE; j++) instance[j] = instance_tmp[j];
        #endif

        t = micros();
        int result = classify();
        t = micros() - t;
        tt += t;
        mx = max(mx, t);

        buffer[tam_buffer++] = (result+'0');

        if (tam_buffer == BUFFER_SIZE){
          buffer[tam_buffer] = '\0';
          Serial.print(buffer);
          tam_buffer = 0;
        }
        //Serial.print(result);

        total2++;
        if (total2 % 1000 == 0) Serial.println(total2);
    }
    test.close();
  }
}

void loop(){
  //while (1){
    Serial.println(acc);
    Serial.println(mx);
    Serial.println(tt);
    Serial.println("-");
    while (1);
  //}
}
