void setup() {
  pinMode(3, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(7, INPUT_PULLUP);
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
  if(digitalRead(7) == 0){
    digitalWrite(3, HIGH);
    delay(500);
    digitalWrite(3,LOW);
    delay(500);
    digitalWrite(5, LOW);

    
  }else{
    digitalWrite(3, LOW);
    digitalWrite(5, HIGH);
  }

}
