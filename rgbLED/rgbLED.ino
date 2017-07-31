int pushButton = 2;
int LED = 13;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  pinMode(pushButton,INPUT);

  pinMode(13,OUTPUT);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  int buttonState = digitalRead(pushButton);

  digitalWrite(LED,buttonState);

  Serial.println(buttonState);

  delay(10);
}
