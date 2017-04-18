#include<SoftwareSerial.h>
//SoftwareSerial myserial(9, 10);
byte pin1=A0;
byte pin2=A3;
int mopin=3;
int f=1;
void setup() {
  

  //myserial.begin(9600);
  pinMode(mopin,OUTPUT);
  pinMode(13,OUTPUT);
 while (!Serial);
  Serial.begin(9600);
  
}

void loop() {
  // put your main code here, to run repeatedly:
 int value1 = analogRead(pin1);
 int value2=analogRead(pin2);
 delay(1000);
 Serial.println(value1);
 Serial.println(value2  );
 if(value1<400&&value2<400)
 {
 analogWrite(mopin,255);
 digitalWrite(13,LOW);
 if(f==1){
  SendMessage(" Enough water is available for irrigation and so I am irrigating the field "( ;}
  f=0; 
 }
 else if(value1>400&&value2>400)
 {
  analogWrite(mopin,0); 
  digitalWrite(13,HIGH);
  if(f==0){
  SendMessage("Water had been ran dry and so I can't pump out further;)");}
  f=1;
 }
}
 void SendMessage(String s)
 {
  Serial.println ("hai");
  Serial.println("AT+CMGF=1");    
  Serial.println("AT+CMGS=\"+918526835173\"\r"); 
  Serial.println(s);
   Serial.println((char)26);
  delay(1000);
}
