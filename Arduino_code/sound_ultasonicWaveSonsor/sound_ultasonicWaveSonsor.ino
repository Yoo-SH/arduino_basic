#include<Servo.h>

Servo myservo; //Servo 라이브러리 변수 선언
int pos =0;//Servo 각도 

void setup() {
  myservo.attach(9); //디지털 핀 번호 초기화
}

void loop() {
  for(pos =0;pos<360;pos +=1)
  {
    myservo.write(pos); //서브 모터의 각도를 조절하는 명령어
    delay(10);
  }
}


