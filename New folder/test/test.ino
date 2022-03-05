const unsigned long eventInterval = 1500;
unsigned long previousTime = 0;
bool waiting = 0, finished = 0;
int count = 0;

#define vibrationSensor 7
#define outputSignal 13

void setup() {
  // put your setup code here, to run once:
  pinMode(outputSignal, OUTPUT);
  pinMode(vibrationSensor, INPUT);

  Serial.begin(9600);
}

void loop() {
  Serial.println(digitalRead(vibrationSensor));
  // put your main code here, to run repeatedly:
  if(count == 0)
  {
    if(digitalRead(vibrationSensor) == 1)
    {
      previousTime = millis();
      count++;
    }
  }
  else if(count == 1)
  {
    if(millis() - previousTime < eventInterval)
    {
      if(millis() - previousTime > 200)
      {
        if(digitalRead(vibrationSensor) == 1)
        {
          previousTime = millis();
          count++;
        } 
      }
    }
    else
    {
      count = 0;
    }
  }
  else if(count == 2)
  {
    if(millis() - previousTime < eventInterval)
    {
      if(millis() - previousTime > 200)
      {
        if(digitalRead(vibrationSensor) == 1)
        {
          previousTime = millis();
          count++;
        } 
      }
    }
    else
    {
      count = 0;
    }
  }
  else if(count == 3)
  {
    if(millis() - previousTime < eventInterval)
    {
      if(millis() - previousTime > 200)
      {
        if(digitalRead(vibrationSensor) == 1)
        {
          previousTime = millis();
          count++;
        } 
      }
    }
    else
    {
      count = 0;
    }
  }
  else if(count == 4)
  {
    if(millis() - previousTime < eventInterval)
    {
      if(millis() - previousTime > 200)
      {
        if(digitalRead(vibrationSensor) == 1)
        {
          previousTime = millis();
          count++;
        } 
      }
    }
    else
    {
      count = 0;
    }
  }
  else if(count == 5)
  {
    finished = 1;
  }
  
  if(finished == 1)
  {
    digitalWrite(13, HIGH);
    Serial.print("Success");
    delay(3000);
    finished = 0;
    count = 0;
  }
  else
  {
    digitalWrite(13, LOW);
  }
}
