#include<SPI.h>
volatile boolean r;
volatile uint16_t  Slaver, Slaver2;

void setup()
{
  Serial.begin(9600);
  pinMode(MISO,OUTPUT);                   
  pinMode(10,INPUT);
  digitalWrite(10,LOW);
  SPCR |= _BV(SPE);                       
  r = false;
  SPI.attachInterrupt(); 
  Serial.print("SYSTEM BOOTING>...........");
  delay(2000);
  Serial.print("SYSTEM READY");                 
}


ISR (SPI_STC_vect)                        
{
    Slaver = SPDR;            
    r = true;
}

 

void loop()
{
  if(r)                           
  {   
      Serial.print("rec ");
      if(Slaver != 0)
      {
      r = false;    
      Serial.print("Room Temp  ");
      float t = Slaver;
      float t1= t/10;
      Serial.println(t1);
      delay(100);
      }
  }
}
