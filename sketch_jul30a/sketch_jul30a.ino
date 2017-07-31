String inString ="";
int currentColor = 0;
int red,green,blue = 0;
int reading = 0;
int rainbowFlag = 0;

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

  pinMode(8,INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:

  
  int inChar;

  if(Serial.available()>0){
    inChar = Serial.read();
    Serial.println("\nSerial availability verified.");
  }

  if(isDigit(inChar)){
    inString += (char)inChar;
    Serial.println("\nInput detected, inString has been changed.");
  }
  if(inChar == 'a'){
    rainbowFlag++;
    
    Serial.println("\nrainbowFlag increased by 1.");
  }
  if(rainbowFlag%2 ==1){
    //reading = reading + 10;
    //if(reading > 1030){
    //  reading = 0;
   // }
    reading = analogRead(A0);
    Serial.println("\nanalogReading is loaded.");
    //setRGB(map(reading,300,500,0,1023));
    setRGB(reading);
    Serial.println("\nRGB set.");
    Serial.print(reading);
    delay(350);
  }

  if(inChar == ','){
    Serial.println("\nSwitch on the way.");
    switch(currentColor){
      case 0:
        red = inString.toInt();
        inString = "";
        Serial.println("\nRed parameter ready, inString cleared.");
        analogWrite(10,255-red);
        Serial.print(red);
        Serial.print(green);
        Serial.print(blue);
        break;

      case 1:
        green = inString.toInt();
        inString = "";
        Serial.println("\nGreen parameter ready, inString cleared.");
        analogWrite(9,255-green);
        Serial.print(red);
        Serial.print(green);
        Serial.print(blue);
        break;

      case 2:
        blue = inString.toInt();
        inString = "";
        Serial.println("\nBlue parameter ready, inString cleared.");
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

void setR(int r){
  if(r < 337){
    red = 255;
  }
  else if(r > 486){
    red = 0;
  }
  else{
    red = 255-map(r,337,486,0,255);
  }
  analogWrite(10,red);
  return;
}

void setG(int g){
  if((g < 637) &&(g > 186)){
    green = 0;
  }
  else if(g > 786){
    green = 255;
  }
  else if(g < 187){
    green = 255-map(g,37,186,0,255);
  }
  else if((g > 636)&&(g < 787)){
    green = 0+map(g,637,786,0,255);
  }
  analogWrite(9,green);
  return;
}

void setB(int b){
  if((b < 187)||((b > 636) &&(b < 787))){
    blue = 255;
  }
  else if((b > 487) &&(b < 336)){
    blue = 0;
  }
  else if((b > 186)&&(b < 337)){
    blue = 255-map(b,187,336,0,255);
  }
  else if((b > 786)&&(b < 937)){
    blue = 255-map(b,787,936,0,255);
  }
  else if((b > 487)&&(b < 636)){
    blue = 0+map(b,487,636,0,255);
  }
  analogWrite(11,blue);
  return;
}

int setRGB(int num){
  setR(num);
  setG(num);
  setB(num);
  return 1;
}
/*void loop(){
    analogWrite(11,255);//B
    analogWrite(9,0);//R
    analogWrite(10,0);//G

}*/
