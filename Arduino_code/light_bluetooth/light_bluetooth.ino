#include <SoftwareSerial.h>       // 소프트웨어 시리얼 라이브러리를 불러옵니다.

int M_pin[4] = {5,6,10,11}; //모터 오른쪽(5,6) 왼쪽(10,11)

void setup()
{
 Serial.begin(9600);
 for(int i=0;i<4;i++)
 {
  pinMode(M_pin[i],OUTPUT);
 }
}

void loop()
{
}

  void serialEvent() //시리얼 데이터가 올떄마다 동작
  { 
    if(Serial.available()> 2)
    {
      byte pinout =Serial.read(); //핀설정 값 저장
      byte L_speed = Serial.read(); //좌측 모터 속도 저장
      byte R_speed = Serial.read(); //우측 모터 속도 저장
      for(int i=0;i<4;i++)
      {
        if(i<2)
          analogWrite(M_pin[i], (0x01 & (pinout >> i)) == 1 ? R_speed : 0);
        else
          analogWrite(M_pin[i], (0x01 & (pinout >> i)) == 1 ? L_speed : 0);
        
      }
    }
  }

 