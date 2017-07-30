String inString ="";
int currentColor = 0;
int red,green,blue = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  while(!Serial){
    ;
  }
  Serial.println("\n\nString toInt() RGB:");
  Serial.println();

  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(11,OUTPUT);

  pinMode(13,OUTPUT);
  digitalWrite(13,HIGH);

}

void loop() {
  // put your main code here, to run repeatedly:

  int inChar;

  if(Serial.available()>0){
    inChar = Serial.read();
    Serial.println("\n\nsSerial availability verified.");
  }

  if(isDigit(inChar)){
    inString += (char)inChar;
    Serial.println("\n\nInput detected, inString has been changed.");
  }

  if(inChar == ','){
    Serial.println("\n\nSwitch on the way.");
    switch(currentColor){
      case 0:
        red = inString.toInt();
        inString = "";
        Serial.println("\n\nRed parameter ready, inString cleared.");
        analogWrite(10,255-red);
        Serial.print(red);
        Serial.print(green);
        Serial.print(blue);
        break;

      case 1:
        green = inString.toInt();
        inString = "";
        Serial.println("\n\nGreen parameter ready, inString cleared.");
        analogWrite(9,255-green);
        Serial.print(red);
        Serial.print(green);
        Serial.print(blue);
        break;

      case 2:
        blue = inString.toInt();
        inString = "";
        Serial.println("\n\nBlue parameter ready, inString cleared.");
        analogWrite(11,255-blue);
        Serial.print(red);
        Serial.print(green);
        Serial.print(blue);
        break;
    }

    currentColor++;
    if(currentColor == 3){
      currentColor = 0;
    }
  }

  /*if(inChar == '\r'){

    Serial.println("\n\nShift detected. Blue parameter ready.");
    blue = inString.toInt();
    Serial.println("\n\nShift detected. Writing on its way.");
    analogWrite(11,255-blue);
    analogWrite(9,255-green);
    analogWrite(10,255-red);

    Serial.print("Red: ");
    Serial.print(red);
    Serial.print(", Green: ");
    Serial.print(green);
    Serial.print(", Blue: ");
    Serial.print(blue);

    inString = "";

    currentColor = 0;
  }*/
}

/*void loop(){
    analogWrite(11,255);//B
    analogWrite(9,0);//R
    analogWrite(10,0);//G

}*/
