//----- 핀 설정
#define PIN_LCD_EN 12    // LCD EN핀
#define PIN_LCD_RS 13    // LCD RS핀
#define PIN_LCD_VE 6     // LCD 콘트라스트핀
#define PIN_LCD_D0 5     // LCD D0
#define PIN_LCD_D1 4     // LCD D1
#define PIN_LCD_D2 3     // LCD D2
#define PIN_LCD_D3 2     // LCD D3

#define PIN_DUST_OUT A0  // 미세먼지 센서 데이터 출력
#define PIN_DUST_LED 11  // 미세먼지 센서 적외선 LED

#define PIN_DHT_OUT 7    // DHT11 센서 데이터 출력

#define PIN_LED_R 10     // RGB LED 적색핀
#define PIN_LED_G 9      // RGB LED 녹색핀

//----- LCD 설정
#include <LiquidCrystal.h>
LiquidCrystal lcd(PIN_LCD_RS, PIN_LCD_EN, PIN_LCD_D0, PIN_LCD_D1, PIN_LCD_D2, PIN_LCD_D3);

//----- DHT11 센서 설정
#include <DHT.h>
DHT dht(PIN_DHT_OUT, DHT11);

void setup() {
  // pinMode 및 Serial 초기화
  Serial.begin(9600);
  pinMode(PIN_DUST_LED, OUTPUT);

  analogWrite(PIN_LCD_VE, 120);      // LCD 디스플레이 콘트라스트 조절
  analogWrite(PIN_LED_G, 0);         // 녹색 LED 초기값 설정
  analogWrite(PIN_LED_R, 0);         // 적색 LED 초기값 설정
  digitalWrite(PIN_DUST_LED, HIGH);  // 미세먼지 센서 적외선 LED 초기값 설정(부논리)

  // LCD 초기화
  lcd.begin(16, 2);

  // DHT11 초기화
  dht.begin();
}

float read_dust() {
  digitalWrite(PIN_DUST_LED, LOW);
  delayMicroseconds(280);
  int dustval = analogRead(PIN_DUST_OUT);
  delayMicroseconds(40);
  digitalWrite(PIN_DUST_LED, HIGH);
  delayMicroseconds(9680);
  float voltage = dustval * (5.0 / 1024.0);
  float dust_ug = (0.17 * voltage - 0.1) * 1000;
  return dust_ug >= 0 ? dust_ug : 0;
}

void print_lcd() {
  float dust_ug = read_dust();                  // 미세먼지 데이터 수집
  int dht_temperature = dht.readTemperature();  // DHT11 온도 데이터 수집
  int dht_humidity = dht.readHumidity();        // DHT11 습도 데이터 수집

  Serial.print("Temperature: ");
  Serial.print(dht_temperature);
  Serial.print(" C\nHumidity: ");
  Serial.print(dht_humidity);
  Serial.print(" %\nDust: ");
  Serial.print(dust_ug);
  Serial.println(" ug");

  lcd.clear();          // LCD 내용 삭제
  lcd.setCursor(0, 0);  // 0, 0으로 커서 설정
  lcd.print("T: ");     // 내용 출력
  lcd.print(dht_temperature);
  lcd.print(" C ");
  lcd.print("H: ");
  lcd.print(dht_humidity);
  lcd.print(" %");
  lcd.setCursor(0, 1);
  lcd.print("Dust: ");
  lcd.print(dust_ug);
  lcd.print("ug");

  if(dust_ug < 35) {         // 미세먼지가 35ug미만일 경우
    analogWrite(PIN_LED_G, 20);
    analogWrite(PIN_LED_R, 0);
  } else if(dust_ug < 75) {  // 미세먼지가 35ug이상, 75ug미만일 경우
    analogWrite(PIN_LED_G, 30);
    analogWrite(PIN_LED_R, 20);
  } else {                   // 미세먼지가 75ug 이상일 경우
    analogWrite(PIN_LED_G, 0);
    analogWrite(PIN_LED_R, 20);
  }
}

void loop() {
  print_lcd();
  delay(3000);
}
