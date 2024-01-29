

void setup() {

}

void loop() {
 tone(8,map(analogRead(A0),0,1023,31,4978),20); // 31~4978은 능동부저가 낼 수 있는 음의 범위
 delay(1000);
}
