# 基于蓝牙的Arduino智能小车

## 效果图
没有理线 电池可以换个小点的 凑合用了 因为我得电池比较大 所以直接放在万向轮的一侧 否则会导致小车前倾 整的很丑
[![pPp5dSK.jpg](https://s1.ax1x.com/2023/07/30/pPp5dSK.jpg)](https://imgse.com/i/pPp5dSK)

## 原件
1. Arduino Uno
2. 杜邦线
3. HC-05蓝牙模块
4. 12V锂电池
5. 电机
6. L298N电机驱动模块
7. 麦轮
8. 亚克力板

## 基本原理

由于没有HC-05的USB供电模块，故直接用电脑USB给Arduino蓝牙模块供电来设置HC-05的基本信息
```c++
SoftwareSerial BT(12, 13);   //TXD 和 RXD不能写错
Serial.begin(9600);            
BT.begin(9600);              
```
然后使用AT命令配置蓝牙信息即可

### 基于PWM的四种运动模式
```c++

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
```

### 根据不同信号处理
```c++
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
```

### 手机端

手机匹配蓝牙后 用**蓝牙调试器app**进行连接

![](https://img.xiazaiba.com/d/file/2020/08-28/d8b8b652245e63c87a12af17bbc93a3a.png)

可以自定义按钮来发送不同信号

[![pPpIMtI.jpg](https://s1.ax1x.com/2023/07/30/pPpIMtI.jpg)](https://imgse.com/i/pPpIMtI)