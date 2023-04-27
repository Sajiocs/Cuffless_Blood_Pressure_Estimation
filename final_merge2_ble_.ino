
//char caracter;
#include<SoftwareSerial.h>
int RX_pin=4;
int TX_pin=2;
SoftwareSerial BTserial(RX_pin,TX_pin);
//String Arduino_data;
int pulsePin = A0;
int ecgout = A1; 
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
BTserial.begin(38400);
pinMode(10, INPUT); // Setup for leads off detection LO +
pinMode(11, INPUT); // Setup for leads off detection LO -

}
void loop() {



 if(((digitalRead(10) == 1)||(digitalRead(11) == 1))){
    char buffer4[7];
  dtostrf(analogRead(pulsePin)*0.002,5,3,buffer4);
  char buffer5[20];
  sprintf(buffer5,"0.000 %s",buffer4);
  //if(Serial.available()) {
    //caracter = Serial.read();
   // if(caracter == 'D'){
      //Arduino_data=Serial.readString(buffer5);
      BTserial.println(buffer5);
  //  }
 // }
}
else{
char buffer1[7];
char buffer2[7];
dtostrf(analogRead(ecgout)*0.001,5,3,buffer1);
dtostrf(analogRead(pulsePin)*0.002,5,3,buffer2);
char buffer3[20];
sprintf(buffer3,"%s %s",buffer1,buffer2);
//if(Serial.available()) {
    //caracter = Serial.read();
    //if(caracter == 'D'){
      //Arduino_data=Serial.readString(buffer3);
      BTserial.println(buffer3);
    //}
  //}

}
delay(1000);
}

//try to send bluetooth using different transmitter and reciver pins-38400
//and rest serial begin with 9600
