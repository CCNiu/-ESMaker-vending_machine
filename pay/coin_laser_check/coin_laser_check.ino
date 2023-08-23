const int LED = 6;
void setup() {
  // put your setup code here, to run once:
  pinMode(13,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(9,INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(13, HIGH);  // 打開鐳射頭
  if(digitalRead(9)==HIGH){ //pullup電路,如果光敏電阻沒有接受到雷射
    digitalWrite(LED, HIGH);
  }
  else{//如果光敏電阻有接受到雷射
    digitalWrite(LED, LOW);//
  }
              
}
