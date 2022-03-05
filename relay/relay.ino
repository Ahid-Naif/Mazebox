void setup() {
  // put your setup code here, to run once:
pinMode(3, OUTPUT);
pinMode(7, INPUT);
//Serial.begin(9600);
}

void loop() {
  if(digitalRead(7) == 1)
  {
    delay(2000);
    if(digitalRead(7) == 1)
    {
   //  Serial.println("Yaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaay");
     digitalWrite(3, LOW);
    }
    else
    {
    //  Serial.println("------------------------------------------");
      digitalWrite(3, HIGH);
    }
  }
  else
  {
   // Serial.println("------------------------------------------");
    digitalWrite(3, HIGH);
  }

 // Serial.println(digitalRead(7));
 // delay(100);
}
