#include <Wire.h>
#include <SPI.h>
#include <RTClib.h>
#include <RTC_DS3231.h>

//Instancia del reloj.
RTC_DS3231 RTC;







void setup()  {
  
  
  Serial.begin(9600);
  
  
  //--------RTC SETUP ------------
  Wire.begin();
  RTC.begin();

  if (! RTC.isrunning()) {
    Serial.println("El RTC no esta funcionando!");

    //Cogemos como fecha y hora aquella en la que el programa fue compilado.
    RTC.adjust(DateTime(__DATE__, __TIME__));
  }
  
  //Cogemos la fecha y la hora del reloj.
  DateTime now = RTC.now();  
  
  //Cogemos la hora en que compilamos el programa.
  DateTime compiled = DateTime(__DATE__, __TIME__);
  
  if (now.unixtime() < compiled.unixtime()) {
    Serial.println("La hora del RTC es mas antigua que la compilacion!  Actualizando...");
    RTC.adjust(DateTime(__DATE__, __TIME__));
  }
           
}//Fin de la funcion setup.




void loop()
{
  
  
  DateTime now = RTC.now();
  
  Serial.print(now.day());
  Serial.print('/');
  Serial.print(now.month());
  Serial.print('/');
  Serial.print(now.year());
  Serial.print(' ');
  
  Serial.print(now.hour());
  Serial.print(':');
  Serial.print(now.minute());
  Serial.print(':');
  Serial.print(now.second());
  Serial.println();
  
  
  Serial.println();
    
  delay(5000);
    
  
}//Fin de la funcion loop.
