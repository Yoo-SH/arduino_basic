#include <Servo.h>

Servo myservo; // Servo 라이브러리 변수 선언

void setup() {
  myservo.attach(9); // 디지털 핀 번호 초기화
}

void loop() {
  int sensorValue = analogRead(A0);
  int angle = map(sensorValue, 0, 1023, 0, 180); // 아날로그 핀 값을 0에서 180도로 변환
  myservo.write(angle); // 서보 모터에 각도 적용
  delay(50);
}
