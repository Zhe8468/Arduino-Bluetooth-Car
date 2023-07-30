#include <SoftwareSerial.h>
SoftwareSerial BT(12, 13);          
char data;                           
void setup() 
{
  Serial.begin(9600);         
  BT.begin(9600);                  
}
void loop()                         
{
  if (BT.available())     // 接收发送给蓝牙的数据 并打印出来        
  {
    data = BT.read();                 
    Serial.print(data);             
  }
}
