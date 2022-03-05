#include <TM1637Display.h>

// Module connection pins (Digital Pins)
#define CLK 7
#define DIO 6

unsigned long countdownTime = 0;

// The amount of time (in milliseconds) between tests
#define COUNTDOWN_DELAY   1

TM1637Display display(CLK, DIO);

int count = 360000;
uint8_t data[] = {0, 0, 0, 0};
/////////////////////////////////////////////////
int buzzle = 12; // it represents whether switches are on the correct pattern and the puzzle is solved
int red_led = 13;
int green_led = 11;
int door = 10;
////////////////////////////////////////////////

// waiting variables
bool waiting = 0, solved = 0;
unsigned long pressed_time=0;
unsigned long previousTime = 0;

bool led_status = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(buzzle, INPUT);
  pinMode(red_led, OUTPUT);
  pinMode(green_led, OUTPUT);
  pinMode(door, OUTPUT);

  digitalWrite(red_led, LOW);
  digitalWrite(green_led, LOW);
  digitalWrite(door, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  countDown();
  
  if(solved)
  {
    checkSwitchesOFF();
    digitalWrite(green_led, HIGH);
    digitalWrite(door, HIGH);
    digitalWrite(red_led, LOW);
    led_status = 0;
  }
  else
  {
    checkSwitchesON();
    digitalWrite(green_led, LOW);
    digitalWrite(door, LOW);
    blinking();
  }
}

void checkSwitchesON()
{
  if(waiting)
  {
    if(millis() - pressed_time >= 30) //30ms is the debounceperiod. (If the debounceperiod has elapsed)
    {
      waiting = 0;
      if(digitalRead(buzzle))
      {
        solved = 1;
      }
    }
  }
  else
  {
    if(digitalRead(buzzle))
    {
      pressed_time = millis(); //Take note of the time and then start waiting
      waiting = 1;
    }
  }
}

void checkSwitchesOFF()
{
  if(waiting)
  {
    if(millis() - pressed_time >= 30) //30ms is the debounceperiod. (If the debounceperiod has elapsed)
    {
      waiting = 0;
      if(digitalRead(buzzle) == 0)
      {
        solved = 0;
      }
    }
  }
  else
  {
    if(digitalRead(buzzle) == 0)
    {
      pressed_time = millis(); //Take note of the time and then start waiting
      waiting = 1;
    }
  }
}

void blinking()
{
  if(led_status == 0) //If the LED is currently OFF
  {
    if(millis() - previousTime >= 500)//2000 is OFF duration
    {
      digitalWrite(red_led, HIGH);
      led_status = 1;
      previousTime = millis(); //Take note of the time
    }
  }
  else //LED is currently ON
  {
    if(millis() - previousTime >= 500)//2000 is ON duration
    {
      digitalWrite(red_led, LOW);
      led_status = 0;
      previousTime = millis();
    }
  }
}

void countDown()
{
  display.setBrightness(0x0f);

  data[3] = display.encodeDigit(count/1 % 10);
  data[2] = display.encodeDigit(count/10 % 10);
  data[1] = display.encodeDigit(count/100 % 10);
  data[0] = display.encodeDigit(count/1000 % 10);
  display.setSegments(data);
  
  if(millis() - countdownTime >= COUNTDOWN_DELAY)//2000 is OFF duration
  {
    if(count <= 0) {
      count = 6000;
    } else {
      count--;
    }
    countdownTime = millis(); //Take note of the time
  }
}
