#define magnet 7
#define ir 2

void setup() {
  // put your setup code here, to run once:
pinMode(magnet, OUTPUT);
pinMode(ir, INPUT);
}

void loop() {
  if(digitalRead(ir) == 0)
  { // if hand is detected
    digitalWrite(magnet, LOW); // magnet OFF
  }
  else if(digitalRead(ir) == 1)
  { // if hand is NOT detected
    digitalWrite(magnet, HIGH); // magnet ON
  }
}
