int sensorPin = A0;
int LEDPin = 13;
int sensorValue = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(LEDPin,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  sensorValue = analogRead(sensorPin);
  digitalWrite(LEDPin,HIGH);
  delay(sensorValue);
  digitalWrite(LEDPin,LOW);
  delay(sensorValue);
  Serial.println(sensorValue);
}
