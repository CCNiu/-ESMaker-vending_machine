#include <Servo.h>
Servo myservo;  
const int LED = 6;
const int led = 2;
int stop_degree = 90;//停止角度
int coin = 0;//計數變數

void setup() {
  myservo.attach(5);
  pinMode(13, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(9, INPUT);
  pinMode(4, INPUT);
  Serial.begin(9600);
  digitalWrite(LED, LOW);
  digitalWrite(led, LOW);
}

void reset() {
  coin = 0; 
  digitalWrite(LED, LOW);
  digitalWrite(led, LOW);
}

void rotate() { //馬達旋轉一圈 可調整停止位置
  myservo.write(0);
  delay(1420);
  myservo.write(stop_degree);
  delay(2000);
}

void loop() {
  digitalWrite(13, HIGH);// 打開激光頭
  delay(500); 

  if (digitalRead(9) == HIGH) { // 光敏電阻没有接收到激，有硬幣通過
    digitalWrite(LED, HIGH);//第一顆燈亮
    coin += 1;計數變數加一
    delay(1000);

    if (coin == 2) {//當投入第二枚硬幣
      digitalWrite(led, HIGH);//第二顆燈亮
      while (digitalRead(4) == HIGH) {}進入迴，當按下按鈕短路後跳出
      rotate();
      reset();//重設所有變數、LED
    }
  }
}
