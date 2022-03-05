#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h>
#endif

#include <OneWire.h>

int debug = 1;
int count1 = 0;
int count2 = 0;
int count3 = 0;
int count4 = 0;
int count5 = 0;

int temp1 = 0;
int temp2 = 0;
int temp3 = 0;
int temp4 = 0;
int temp5 = 0;

int max_temp = 6;

byte addr[8];

byte addr_rom1[2][8] = {{1, 119, 103, 68, 0, 122, 0, 223},
  {1, 171, 67, 69, 0, 122, 0, 14}
};
byte addr_rom2[2][8] = {{1, 23, 212, 132, 0, 49, 0, 156},
  {1, 176, 255, 120, 0, 9, 0, 245}
};
byte addr_rom3[2][8] = {{1, 241, 209, 120, 0, 9, 0, 237},
  {1, 70, 196, 243, 0, 49, 0, 215}
};
byte addr_rom4[2][8] = {{1, 119, 102, 105, 0, 9, 0, 28},
  {1, 63, 80, 244, 0, 49, 0, 247}
};
byte addr_rom5[2][8] = {{1, 170, 239, 55, 0, 122, 0, 132},
  {1, 220, 7, 121, 0, 9, 0, 92}
};

int mode = 1; //mode0 - stop
//mode 1 - matrix find
//mode 2 - matrix good
int flag_end = 0;

#define PIN1 3
#define PIN2 A4
#define PIN3 A3
#define PIN4 A2
#define PIN5 A1

OneWire ds1(6);
OneWire ds2(5);
OneWire ds3(4);
OneWire ds4(7);
OneWire ds5(8);


#define out1 13 // not used
#define out2 12 // not used
#define out3 11 // not used
#define out4 10
#define out5 9


#define NUMPIXELS1 284
#define NUMPIXELS2 71
#define NUMPIXELS3 71
#define NUMPIXELS4 71
#define NUMPIXELS5 71

Adafruit_NeoPixel strip1 = Adafruit_NeoPixel(NUMPIXELS1, PIN1, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip2 = Adafruit_NeoPixel(NUMPIXELS2, PIN2, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip3 = Adafruit_NeoPixel(NUMPIXELS3, PIN3, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip4 = Adafruit_NeoPixel(NUMPIXELS4, PIN4, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip5 = Adafruit_NeoPixel(NUMPIXELS5, PIN5, NEO_GRB + NEO_KHZ800);

int delayval = 500; // delay for half a second

void setup() {
  Serial.begin(9600);

#if defined (__AVR_ATtiny85__)
  if (F_CPU == 16000000) clock_prescale_set(clock_div_1);
#endif

  pinMode(out2, OUTPUT);
  pinMode(out3, OUTPUT);
  pinMode(out4, OUTPUT);
  pinMode(out5, OUTPUT);

  strip1.begin();
  strip2.begin();
  strip3.begin();
  strip4.begin();
  strip5.begin();

  Serial.println("loop");
}

void loop() {
  count1 = 0;
  count2 = 0;
  if (ds1.reset()) {
    ds1.write(0x33);
    for (int i = 0; i < 8; i++) addr[i] = ds1.read();
    if (debug)       Serial.print("ROM1 = ");
    for (int i = 0; i < 8; i++)
    {
      if (addr_rom1[0][i] == addr[i]) count1++;
      if (addr_rom1[1][i] == addr[i]) count2++;
      if (debug)    Serial.print(addr[i]);
      if (debug)    Serial.print(", ");
    }

    if (debug) Serial.println();
    if (debug){ Serial.print(count1); Serial.print(' '); Serial.println(count2);}
    if (count1 == 8 || count2 == 8) temp1 += 2;
    else temp1--;
    ds1.reset_search();
  }
  else temp1--;

  if (temp1 > max_temp) temp1 = max_temp;
  if (temp1 < 0) temp1 = 0;


  count1 = 0;
  count2 = 0;
  if (ds2.reset()) {
    ds2.write(0x33);
    for (int i = 0; i < 8; i++) addr[i] = ds2.read();
    if (debug)       Serial.print("ROM2 = ");
    for (int i = 0; i < 8; i++)
    {
      if (addr_rom2[0][i] == addr[i]) count1++;
      if (addr_rom2[1][i] == addr[i]) count2++;
      if (debug)    Serial.print(addr[i]);
      if (debug)    Serial.print(", ");
    }

    if (debug) Serial.println();
    if (debug){ Serial.print(count1); Serial.print(' '); Serial.println(count2);}
    if (count1 == 8 || count2 == 8) temp2 += 2;
    else temp2--;
    ds2.reset_search();
  }
  else temp2--;

  if (temp2 > max_temp) temp2 = max_temp;
  if (temp2 < 0) temp2 = 0;

  //---------------------

  count1 = 0;
  count2 = 0;
  if (ds3.reset()) {
    ds3.write(0x33);
    for (int i = 0; i < 8; i++) addr[i] = ds3.read();
    if (debug)       Serial.print("ROM3 = ");
    for (int i = 0; i < 8; i++)
    {
      if (addr_rom3[0][i] == addr[i]) count1++;
      if (addr_rom3[1][i] == addr[i]) count2++;
      if (debug)    Serial.print(addr[i]);
      if (debug)    Serial.print(", ");
    }

    if (debug) Serial.println();
    if (debug){ Serial.print(count1); Serial.print(' '); Serial.println(count2);}
    if (count1 == 8 || count2 == 8) temp3 += 2;
    else temp3--;
    ds3.reset_search();
  }
  else temp3--;

  if (temp3 > max_temp) temp3 = max_temp;
  if (temp3 < 0) temp3 = 0;

  //-------------

  count1 = 0;
  count2 = 0;
  if (ds4.reset()) {
    ds4.write(0x33);
    for (int i = 0; i < 8; i++) addr[i] = ds4.read();
    if (debug)       Serial.print("ROM4 = ");
    for (int i = 0; i < 8; i++)
    {
      if (addr_rom4[0][i] == addr[i]) count1++;
      if (addr_rom4[1][i] == addr[i]) count2++;
      if (debug)    Serial.print(addr[i]);
      if (debug)    Serial.print(", ");
    }

    if (debug) Serial.println();
    if (debug){ Serial.print(count1); Serial.print(' '); Serial.println(count2);}
    if (count1 == 8 || count2 == 8) temp4 += 2;
    else temp4--;
    ds4.reset_search();
  }
  else temp4--;

  if (temp4 > max_temp) temp4 = max_temp;
  if (temp4 < 0) temp4 = 0;



  //-------------

  count1 = 0;
  count2 = 0;
  if (ds5.reset()) {
    ds5.write(0x33);
    for (int i = 0; i < 8; i++) addr[i] = ds5.read();
    if (debug)       Serial.print("ROM5 = ");
    for (int i = 0; i < 8; i++)
    {
      if (addr_rom5[0][i] == addr[i]) count1++;
      if (addr_rom5[1][i] == addr[i]) count2++;
      if (debug)    Serial.print(addr[i]);
      if (debug)    Serial.print(", ");
    }

    if (debug) Serial.println();
    if (debug){ Serial.print(count1); Serial.print(' '); Serial.println(count2);}
    if (count1 == 8 || count2 == 8) temp5 += 2;
    else temp5--;
    ds5.reset_search();
  }
  else temp5--;

  if (temp5 > max_temp) temp5 = max_temp;
  if (temp5 < 0) temp5 = 0;

  //-----------------
  if (temp2 > 3 && temp3 > 3 && temp4 > 3 && temp5 > 3)
  {
    digitalWrite(out4, 1);
    digitalWrite(out5, 0);
  }

  if (temp2 < 2 && temp3 < 2 && temp4 < 2 && temp2 < 5)
  {
    digitalWrite(out4, 0);
    digitalWrite(out5, 1);
  }

  if (flag_end == 1) {
    if (temp2 < 2 && temp3 < 2 && temp4 < 2 && temp5 < 2) {
      flag_end = 0;
      for (int i = 0; i < NUMPIXELS1; i++) {
        strip1.setPixelColor(i, 0, 0, 100);
        strip2.setPixelColor(i, 0, 0, 100);
        strip3.setPixelColor(i, 0, 0, 100);
        strip4.setPixelColor(i, 0, 0, 100);
        strip5.setPixelColor(i, 0, 0, 100);
        strip1.show();
        strip2.show();
        strip3.show();
        strip4.show();
        strip5.show();
      }
      delay(500);
      for (int i = 0; i < NUMPIXELS1; i++) {
        strip1.setPixelColor(i, 0, 0, 0);
        strip2.setPixelColor(i, 0, 0, 0);
        strip3.setPixelColor(i, 0, 0, 0);
        strip4.setPixelColor(i, 0, 0, 0);
        strip5.setPixelColor(i, 0, 0, 0);
        strip1.show();
        strip2.show();
        strip3.show();
        strip4.show();
        strip5.show();
      }
    }
  }


  if (flag_end == 0) {
    for (int i = 0; i < 6; i++) {
      if(temp2 != 0 || temp3 != 0 || temp4 != 0 || temp5 !=0)
      {
        for (int j = 0; j < 18; j++) {
          strip1.setPixelColor(j * i, 255, 0, 0);
          strip1.setPixelColor(j * i + 1, 0, 0, 0);
          strip1.setPixelColor(j * i + 2, 0, 0, 0);
          strip1.setPixelColor(j * i + 3, 0, 0, 255);

          strip2.setPixelColor(j * i, 255, 0, 0);
          strip2.setPixelColor(j * i + 1, 0, 0, 0);
          strip2.setPixelColor(j * i + 2, 0, 0, 0);
          strip2.setPixelColor(j * i + 3, 0, 0, 255);

          strip3.setPixelColor(j * i, 255, 0, 0);
          strip3.setPixelColor(j * i + 1, 0, 0, 0);
          strip3.setPixelColor(j * i + 2, 0, 0, 0);
          strip3.setPixelColor(j * i + 3, 0, 0, 255);

          strip4.setPixelColor(j * i, 255, 0, 0);
          strip4.setPixelColor(j * i + 1, 0, 0, 0);
          strip4.setPixelColor(j * i + 2, 0, 0, 0);
          strip4.setPixelColor(j * i + 3, 0, 0, 255);

          strip5.setPixelColor(j * i, 255, 0, 0);
          strip5.setPixelColor(j * i + 1, 0, 0, 0);
          strip5.setPixelColor(j * i + 2, 0, 0, 0);
          strip5.setPixelColor(j * i + 3, 0, 0, 255);
        }
      }
      else 
      {
        for (int k = 0; k < NUMPIXELS1; k++) 
        {
          strip1.setPixelColor(k, 0, 0, 0);
          strip2.setPixelColor(k, 0, 0, 0);
          strip3.setPixelColor(k, 0, 0, 0);
          strip4.setPixelColor(k, 0, 0, 0);
          strip5.setPixelColor(k, 0, 0, 0); 
        }
      }
      strip1.show();
      strip2.show();
      strip3.show();
      strip4.show();
      strip5.show();
      delay(100);
    }
  }

  if (temp2 > 5 && temp3 > 5 && temp4 > 5 && temp5 > 5 && flag_end == 0) {
    for (int i = 0; i < NUMPIXELS1; i++) {
      strip1.setPixelColor(i, 0, 0, 0);
      strip2.setPixelColor(i, 0, 0, 0);
      strip3.setPixelColor(i, 0, 0, 0);
      strip4.setPixelColor(i, 0, 0, 0);
      strip5.setPixelColor(i, 0, 0, 0);
      strip1.show();
      strip2.show();
      strip3.show();
      strip4.show();
      strip5.show();
    }
    for (int i = 0; i < NUMPIXELS1; i++) {
      for (int j = 0; j < 255; j += 30) {
        strip1.setPixelColor(i, j, 0, 0);
        strip2.setPixelColor(i, j, 0, 0);
        strip3.setPixelColor(i, j, 0, 0);
        strip4.setPixelColor(i, j, 0, 0);
        strip5.setPixelColor(i, j, 0, 0);
        strip1.show();
        strip2.show();
        strip3.show();
        strip4.show();
        strip5.show();
      }
    }

    for (int i = 0; i < NUMPIXELS1; i++) {
      for (int j = 255; j > 30; j -= 40) {
        strip1.setPixelColor(i, j, 0, 0);
        strip2.setPixelColor(i, j, 0, 0);
        strip3.setPixelColor(i, j, 0, 0);
        strip4.setPixelColor(i, j, 0, 0);
        strip5.setPixelColor(i, j, 0, 0);

      }
      strip1.show();
      strip2.show();
      strip3.show();
      strip4.show();
      strip5.show();
    }

    for (int i = 0; i < NUMPIXELS1; i++) {
      for (int j = 30; j < 250; j += 40) {
        strip1.setPixelColor(i, j, 0, 0);
        strip2.setPixelColor(i, j, 0, 0);
        strip3.setPixelColor(i, j, 0, 0);
        strip4.setPixelColor(i, j, 0, 0);
        strip5.setPixelColor(i, j, 0, 0);

      }

      strip1.show();
      strip2.show();
      strip3.show();
      strip4.show();
      strip5.show();
    }

    for (int i = 0; i < NUMPIXELS1; i++) {
      for (int j = 255; j > 30; j -= 40) {
        strip1.setPixelColor(i, j, 0, 0);
        strip2.setPixelColor(i, j, 0, 0);
        strip3.setPixelColor(i, j, 0, 0);
        strip4.setPixelColor(i, j, 0, 0);
        strip5.setPixelColor(i, j, 0, 0);

      }

      strip1.show();
      strip2.show();
      strip3.show();
      strip4.show();
      strip5.show();
    }

    for (int i = 0; i < NUMPIXELS1; i++) {
      for (int j = 30; j < 250; j += 40) {
        strip1.setPixelColor(i, j, 0, 0);
        strip2.setPixelColor(i, j, 0, 0);
        strip3.setPixelColor(i, j, 0, 0);
        strip4.setPixelColor(i, j, 0, 0);
        strip5.setPixelColor(i, j, 0, 0);

      }

      strip1.show();
      strip2.show();
      strip3.show();
      strip4.show();
      strip5.show();
    }

    delay(4000);

    for (int i = 0; i < NUMPIXELS1; i++) {
      for (int j = 255; j > 30; j -= 40) {
        strip1.setPixelColor(i, j, 0, 0);
        strip2.setPixelColor(i, j, 0, 0);
        strip3.setPixelColor(i, j, 0, 0);
        strip4.setPixelColor(i, j, 0, 0);
        strip5.setPixelColor(i, j, 0, 0);
      }
      strip1.show();
      strip2.show();
      strip3.show();
      strip4.show();
      strip5.show();
    }

    for (int i = 0; i < NUMPIXELS1; i++) {
      for (int j = 30; j < 250; j += 40) {
        strip1.setPixelColor(i, j, 0, 0);
        strip2.setPixelColor(i, j, 0, 0);
        strip3.setPixelColor(i, j, 0, 0);
        strip4.setPixelColor(i, j, 0, 0);
        strip5.setPixelColor(i, j, 0, 0);

      }
      strip1.show();
      strip2.show();
      strip3.show();
      strip4.show();
      strip5.show();
    }
    for (int i = 0; i < NUMPIXELS1; i++) {
      for (int j = 255; j > 30; j -= 40) {
        strip1.setPixelColor(i, j, 0, 0);
        strip2.setPixelColor(i, j, 0, 0);
        strip3.setPixelColor(i, j, 0, 0);
        strip4.setPixelColor(i, j, 0, 0);
        strip5.setPixelColor(i, j, 0, 0);

      }

      strip1.show();
      strip2.show();
      strip3.show();
      strip4.show();
      strip5.show();
    }

    for (int i = 0; i < NUMPIXELS1; i++) {
      for (int j = 30; j < 250; j += 40) {
        strip1.setPixelColor(i, j, 0, 0);
        strip2.setPixelColor(i, j, 0, 0);
        strip3.setPixelColor(i, j, 0, 0);
        strip4.setPixelColor(i, j, 0, 0);
        strip5.setPixelColor(i, j, 0, 0);
      }
      strip1.show();
      strip2.show();
      strip3.show();
      strip4.show();
      strip5.show();
    }

    delay(4000);

    for (int i = 0; i < NUMPIXELS1; i++) {
      for (int j = 255; j > 30; j -= 40) {
        strip1.setPixelColor(i, j, 0, 0);
        strip2.setPixelColor(i, j, 0, 0);
        strip3.setPixelColor(i, j, 0, 0);
        strip4.setPixelColor(i, j, 0, 0);
        strip5.setPixelColor(i, j, 0, 0);

      }
      strip1.show();
      strip2.show();
      strip3.show();
      strip4.show();
      strip5.show();
    }

    for (int i = 0; i < NUMPIXELS1; i++) {
      for (int j = 30; j < 250; j += 40) {
        strip1.setPixelColor(i, j, 0, 0);
        strip2.setPixelColor(i, j, 0, 0);
        strip3.setPixelColor(i, j, 0, 0);
        strip4.setPixelColor(i, j, 0, 0);
        strip5.setPixelColor(i, j, 0, 0);
      }
      strip1.show();
      strip2.show();
      strip3.show();
      strip4.show();
      strip5.show();
    }

    for (int i = 0; i < NUMPIXELS1; i++) {
      for (int j = 255; j > 30; j -= 40) {
        strip1.setPixelColor(i, j, 0, 0);
        strip2.setPixelColor(i, j, 0, 0);
        strip3.setPixelColor(i, j, 0, 0);
        strip4.setPixelColor(i, j, 0, 0);
        strip5.setPixelColor(i, j, 0, 0);
      }
      strip1.show();
      strip2.show();
      strip3.show();
      strip4.show();
      strip5.show();
    }

    for (int i = 0; i < NUMPIXELS1; i++) {
      for (int j = 30; j < 250; j += 40) {
        strip1.setPixelColor(i, j, 0, 0);
        strip2.setPixelColor(i, j, 0, 0);
        strip3.setPixelColor(i, j, 0, 0);
        strip4.setPixelColor(i, j, 0, 0);
        strip5.setPixelColor(i, j, 0, 0);
      }
      strip1.show();
      strip2.show();
      strip3.show();
      strip4.show();
      strip5.show();
    }


    for (int i = 0; i < NUMPIXELS1; i++) {
      strip1.setPixelColor(i, 0, 0, 0);
      strip2.setPixelColor(i, 0, 0, 0);
      strip3.setPixelColor(i, 0, 0, 0);
      strip4.setPixelColor(i, 0, 0, 0);
      strip5.setPixelColor(i, 0, 0, 0);
      strip1.show();
      strip2.show();
      strip3.show();
      strip4.show();
      strip5.show();
    }
    for (int i = 0; i < NUMPIXELS1; i++) {
      for (int j = 0; j < 255; j += 15) {
        strip1.setPixelColor(i, 255 - j, 0, j);
        strip2.setPixelColor(i, 255 - j, 0, j);
        strip3.setPixelColor(i, 255 - j, 0, j);
        strip4.setPixelColor(i, 255 - j, 0, j);
        strip5.setPixelColor(i, 255 - j, 0, j);
        strip1.show();
        strip2.show();
        strip3.show();
        strip4.show();
        strip5.show();
      }
    }


    for (int i = 0; i < NUMPIXELS1; i++) {
      for (int j = 0; j < 255; j += 15) {
        strip1.setPixelColor(i, 0, 0, 255 - j);
        strip2.setPixelColor(i, 0, 0, 255 - j);
        strip3.setPixelColor(i, 0, 0, 255 - j);
        strip4.setPixelColor(i, 0, 0, 255 - j);
        strip5.setPixelColor(i, 0, 0, 255 - j);
        strip1.show();
        strip2.show();
        strip3.show();
        strip4.show();
        strip5.show();
      }
    }

    flag_end = 1;



  }

  return;

  for (int i = 0; i < NUMPIXELS3 - 1; i++) {
    if (temp1 > 5)   strip1.setPixelColor(i, 255, 0, 0);
    if (temp1 > 5)   strip1.setPixelColor(i - 1, 0, 0, 255);
    if (temp1 > 5)   strip1.show();
    if (temp2 > 5)   strip2.setPixelColor(i, 255, 0, 0);
    if (temp2 > 5)   strip2.setPixelColor(i - 1, 0, 0, 255);
    if (temp2 > 5)   strip2.show();
    if (temp3 > 5)   strip3.setPixelColor(i, 255, 0, 0);
    if (temp3 > 5)   strip3.setPixelColor(i - 1, 0, 0, 255);
    if (temp3 > 5)   strip3.show();
    if (temp4 > 5)   strip4.setPixelColor(i, 255, 0, 0);
    if (temp4 > 5)   strip4.setPixelColor(i - 1, 0, 0, 255);
    if (temp4 > 5)   strip4.show();
    if (temp5 > 5)   strip5.setPixelColor(i, 255, 0, 0);
    if (temp5 > 5)   strip5.setPixelColor(i - 1, 0, 0, 255);
    if (temp5 > 5)   strip5.show();
    delay(40);
    strip1.setPixelColor(i, 0, 0, 0);
    strip1.setPixelColor(i - 1, 0, 0, 0);
    strip1.show();
    strip2.setPixelColor(i, 0, 0, 0);
    strip2.setPixelColor(i - 1, 0, 0, 0);
    strip2.show();
    strip3.setPixelColor(i, 0, 0, 0);
    strip3.setPixelColor(i - 1, 0, 0, 0);
    strip3.show();
    strip4.setPixelColor(i, 0, 0, 0);
    strip4.setPixelColor(i - 1, 0, 0, 0);
    strip4.show();
    strip5.setPixelColor(i, 0, 0, 0);
    strip5.setPixelColor(i - 1, 0, 0, 0);
    strip5.show();
  }
  return;

  for (int i = 0; i < NUMPIXELS1; i++) {
    strip1.setPixelColor(i, 2, 0, 0);
  }
  strip1.show();
  delay(1000);

  for (int i = 0; i < NUMPIXELS1; i++) {
    strip1.setPixelColor(i, 0, 0, 2);
  }
  strip1.show();
  delay(1000);



  for (int i = 0; i < NUMPIXELS1; i++) {
    strip1.setPixelColor(i, 200, 0, 10);
    strip1.show();
    delay(50);
    strip1.setPixelColor(i, 0, 0, 0);
    strip1.show();
  }

}
