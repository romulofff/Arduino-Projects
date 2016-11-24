// Ultrasonic - Library for HR-SC04 Ultrasonic Ranging Module.
// Rev.4 (06/2012)
// J.Rodrigo ( www.jrodrigo.net )
// more info at http://www.ardublog.com
// Wiki: https://github.com/JRodrigoTech/Ultrasonic-HC-SR04/wiki/Plug-&-Play

#include <Ultrasonic.h>
#define me1 4
#define me2 5

Ultrasonic ultrasonic(8,9); // (Trig PIN,Echo PIN)
int valUltra = 0;
void setup() {
  Serial.begin(9600);
  pinMode(4, OUTPUT); // VCC pin
  pinMode(7, OUTPUT); // GND ping
  digitalWrite(4, HIGH); // VCC +5V mode  
  digitalWrite(7, LOW);  // GND mode 
  pinMode(me1, OUTPUT);
  pinMode(me2, OUTPUT);

}

void loop()
{
  Serial.print(ultrasonic.Ranging(CM)); // CM or INC
  valUltra = ultrasonic.Ranging(CM);
  Serial.println(" cm" );
  if(valUltra < 20){
    digitalWrite(me1, HIGH);
    digitalWrite(me2, LOW);
 
  }
  else{
        digitalWrite(me1, LOW);
 
  }
  delay(100);
}







