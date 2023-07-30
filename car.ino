#include <SoftwareSerial.h>  
SoftwareSerial BT(12, 13);
char data;
// 电机引脚定义
#define left1 9
#define left2 3
#define right1 11
#define right2 10

void setup() {
  // 初始化电机引脚
  pinMode(left1,OUTPUT);
  pinMode(left2,OUTPUT);
  pinMode(right1,OUTPUT);
  pinMode(right2,OUTPUT);
  // 初始化串口通讯
  Serial.begin(9600);
  Serial.println("蓝牙连接正常");    
  BT.begin(9600);  
}

void forward(){
  analogWrite(left1,10);
  analogWrite(left2,200);
  analogWrite(right1,10);
  analogWrite(right2,200);
}

void backward(){
  analogWrite(left1,100);
  analogWrite(left2,10);
  analogWrite(right1,100);
  analogWrite(right2,10);
}

void left(){
  analogWrite(left1,10);
  analogWrite(left2,100);
  analogWrite(right1,100);
  analogWrite(right2,10);
}

void right(){
  analogWrite(left1,100);
  analogWrite(left2,10);
  analogWrite(right1,10);
  analogWrite(right2,100);
}

void Stop(){
  //停车
  analogWrite(left1,0);
  analogWrite(left2,0);
  analogWrite(right1,0);
  analogWrite(right2,0);
}



void loop() {
  
  if(BT.available()){
    data = BT.read();
    Serial.print("data:");
    Serial.println(data);
    if(data=='f'){
      forward();
      delay(500);
      Stop();
      Serial.println("forward...");
    }else if(data=='b'){
      backward();
      delay(500);
      Stop();
      Serial.println("forward...");
    }else if(data=='l'){
      left();
      delay(500);
      Stop();
      Serial.println("left...");
    }else if(data=='r'){
      right();
      delay(500);
      Stop();
      Serial.println("right...");
    }
  }
}
