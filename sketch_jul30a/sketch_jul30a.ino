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

/*void loop() {
  // put your main code here, to run repeatedly:

  int inChar;

  if(Serial.available()>0){
    inChar = Serial.read();
  }

  if(isDigit(inChar)){
    inString += (char)inChar;
  }

  if(inChar == ','){
    switch(currentColor){
      case 0:
        red = inString.toInt();
        inString = "";
        break;

      case 1:
        green = inString.toInt();
        inString = "";
        break;
    }

    currentColor++;
  }

  if(inChar == '\r'){
    blue = inString.toInt();
    analogWrite(11,255-red);
    analogWrite(9,255-green);
    analogWrite(10,255-blue);

    Serial.print("Red: ");
    Serial.print(red);
    Serial.print(", Green: ");
    Serial.print(green);
    Serial.print(", Blue: ");
    Serial.print(blue);

    inString = "";

    currentColor = 0;
  }*/

void loop(){
    analogWrite(11,255);
    analogWrite(9,0);//R
    analogWrite(10,0);

}
