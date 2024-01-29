#include <SoftwareSerial.h>       // 소프트웨어 시리얼 라이브러리를 불러옵니다.
SoftwareSerial bluetooth(2, 3);   // 블루투스 모듈을 선언합니다. 블루투스의 TX를 2번에 RX를 3번에 연결합니다.
int LED = 8;                                // LED를 8번으로 설정합니다.
char val;                                   // 블루투스 통신을 통해 받은 값을 저장하는 변수를 만들어줍니다.
void setup()
{
  bluetooth.begin(9600);             // 소프트웨어 시리얼의 보드레이트를 9600으로 설정합니다.
  pinMode(LED, OUTPUT);         // LED 핀을 출력핀으로 설정합니다.
}
void loop()
{
  if (bluetooth.available())             // 블루투스 모듈을 통해 새로운 값을 받으면 (안드로이드 폰으로 값을 보내면)
  {
    val = bluetooth.read();              // 이를 val 변수에 저장합니다.
    if (val == '0')                             // 저장된 값이 0이면
    {
      digitalWrite(LED, LOW);          // LED를 끕니다.
    }
    if (val == '1')                            // 저장된 값이 1이면
    {
      digitalWrite(LED, HIGH);         // LED를 켭니다.
    }
  }
}
