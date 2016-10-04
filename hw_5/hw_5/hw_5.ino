//temperature source 
//http://www.circuitbasics.com/arduino-thermistor-temperature-sensor-tutorial/ 
int ledPin = 7;

#include <math.h>

double Thermistor(int RawADC) {
 double Temp;
 Temp = log(10000.0*((1024.0/RawADC-1))); 
 Temp = 1 / (0.001129148 + (0.000234125 + (0.0000000876741 * Temp * Temp ))* Temp );
 Temp = Temp - 273.15;          
 Temp = (Temp * 9.0)/ 5.0 + 32.0; 
 return Temp;
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(7, OUTPUT);

}

void loop() {
  int val;                
  double temp;            
  val=analogRead(0);      
  temp=Thermistor(val);   
  Serial.print("Temperature = ");
  Serial.print(temp);   
  Serial.println(" F");
  delay(500); 
  if(temp > 90){ 
    digitalWrite(7, HIGH);
    }else{
     digitalWrite(7,LOW);
     }
}
