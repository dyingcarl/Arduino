const int analogPin = A0;
const int LEDCount = 4;
int LEDPins[] = {0,1,2,3};

void setup() {
  // put your setup code here, to run once:

  for (int thisLED = 0; thisLED < LEDCount; thisLED++){
    pinMode(LEDPins[thisLED],OUTPUT);
  }
}

void loop() {
  // put your main code here, to run repeatedly:

  int sensorReading = analogRead(analogPin);

  int LEDLevel = map(sensorReading,0,1023,0,LEDCount);

  for (int thisLED = 0; thisLED < LEDCount; thisLED++){
    if(thisLED<LEDLevel){
      digitalWrite(LEDPins[thisLED],HIGH);
      
    }

    else{
      digitalWrite(LEDPins[thisLED],LOW);
    }
  }
}
