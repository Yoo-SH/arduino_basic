#include<DHT.h>        // DHT.h 라이브러리를 포함합니다.

#define DHTPIN 2       // DHTPIN을 2로 설정합니다.
#define DHTTYPE DHT11  // DHTTYPE를 DHT11로 설정합니다.

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);  // 시리얼 통신을 보레이트 9600으로 초기화합니다.
  dht.begin();         // DHT11 센서를 초기화합니다.
}

void loop() {
  delay(2000);                    // 2초 대기
  int h = dht.readHumidity();     // 변수 h를 선언하여 습도값을 대입
  int t = dht.readTemperature();  // 변수 t를 선언하여 온도값을 대입
  Serial.print("Humidity: ");     // 시리얼 프린터에 출력 (이하생략)
  Serial.print(h);
  Serial.print("%\t");
  Serial.print("Temperature: ");
  Serial.print(t);
  Serial.println(" C");
}