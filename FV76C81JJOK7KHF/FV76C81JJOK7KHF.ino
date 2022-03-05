#include <Adafruit_NeoPixel.h>
#define PIN1 3  //connect 12 Neopixel strip to Digital PIN6
#define PIN2 13  //connect 6 Neopixel strip to Digital PIN7
#define PIN3 2  // connect 24 Neopixel ring to Digital PIN8 
#define PIN4 10  // connect 16 Neopixel ring to Digital PIN9 
#define PIN5 11  //  
#define NUMPIXELS1 71
#define NUMPIXELS2 71
#define NUMPIXELS3 71
#define NUMPIXELS4 71
#define NUMPIXELS5 71
Adafruit_NeoPixel pixels1 = Adafruit_NeoPixel(NUMPIXELS1, PIN1, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel pixels2 = Adafruit_NeoPixel(NUMPIXELS2, PIN2, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel pixels3 = Adafruit_NeoPixel(NUMPIXELS3, PIN3, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel pixels4 = Adafruit_NeoPixel(NUMPIXELS4, PIN4, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel pixels5 = Adafruit_NeoPixel(NUMPIXELS5, PIN5, NEO_GRB + NEO_KHZ800);

int delayval = 10; // timing delay
int redColor = 0;
int greenColor = 0;
int blueColor = 0;


void setup()  {
  pixels1.begin();
  pixels2.begin();
  pixels3.begin();
  pixels4.begin();
  pixels5.begin();
  pixels1.show();
  pixels2.show();
  pixels3.show();
  pixels4.show();
  pixels5.show();
}

void loop() {

  ring1();
  ring2();
  ring3();
  ring4();
  ring5();
}

void ring1() {
  setColor();

  for(int i=0;i<NUMPIXELS1;i++){

    // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
    pixels1.setPixelColor(i, pixels1.Color(redColor, greenColor, blueColor)); // Moderately bright green color.

    pixels1.show(); // This sends the updated pixel color to the hardware.

    delay(delayval); // Delay for a period of time (in milliseconds).
    
    // Serial.println(i);
    
    if (i == NUMPIXELS1){
    	i = 0; // start all over again!
        setColor();
	  }

  }
}
  
void ring2() {
  setColor();

  for(int i=0;i<NUMPIXELS2;i++){

    // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
    pixels2.setPixelColor(i, pixels2.Color(redColor, greenColor, blueColor)); // Moderately bright green color.

    pixels2.show(); // This sends the updated pixel color to the hardware.

    delay(delayval); // Delay for a period of time (in milliseconds).
    
    // Serial.println(i);
    
    if (i == NUMPIXELS2){
    	i = 0; // start all over again!
        setColor();
	  }

  }
}
void ring3() {
  setColor();

  for(int i=0;i<NUMPIXELS3;i++){

    // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
    pixels3.setPixelColor(i, pixels3.Color(redColor, greenColor, blueColor)); // Moderately bright green color.

    pixels3.show(); // This sends the updated pixel color to the hardware.

    delay(delayval); // Delay for a period of time (in milliseconds).
    
    // Serial.println(i);
    
    if (i == NUMPIXELS3){
    	i = 0; // start all over again!
        setColor();
	  }

  }
}
void ring4() {
  setColor();

  for(int i=0;i<NUMPIXELS4;i++){

    // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
    pixels4.setPixelColor(i, pixels4.Color(redColor, greenColor, blueColor)); // Moderately bright green color.

    pixels4.show(); // This sends the updated pixel color to the hardware.

    delay(delayval); // Delay for a period of time (in milliseconds).
    
    // Serial.println(i);
    
    if (i == NUMPIXELS4){
    	i = 0; // start all over again!
        setColor();
	  }

  }
}
void ring5() {
  setColor();

  for(int i=0;i<NUMPIXELS5;i++){

    // pixels5.Color takes RGB values, from 0,0,0 up to 255,255,255
    pixels5.setPixelColor(i, pixels5.Color(redColor, greenColor, blueColor)); // Moderately bright green color.

    pixels5.show(); // This sends the updated pixel color to the hardware.

    delay(delayval); // Delay for a period of time (in milliseconds).
    
    // Serial.println(i);
    
    if (i == NUMPIXELS5){
    	i = 0; // start all over again!
        setColor();
	  }

  }
}

// setColor()
// picks random values to set for RGB

void setColor(){
  redColor = random(0, 255);
  greenColor = random(0,255);
  blueColor = random(0, 255);
  Serial.print("red: ");
  Serial.println(redColor);
  Serial.print("green: ");
  Serial.println(greenColor);
  Serial.print("blue: ");
  Serial.println(blueColor);
  
}
