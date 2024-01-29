#define TRIG 2
#define ECHO 3

void setup() {
  pinMode(TRIG,OUTPUT);
  pinMode(ECHO,INPUT);
}

void loop() {
  //TRIG값을 껏다 키면서 값을 보정
  digitalWrite(TRIG,LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG,HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG,LOW);

  long distance = pulseIn(ECHO,HIGH) /58.2; //pulseln에서는 ECHO에 들어오는 값을 측정. 58.2는 들어오는 값을 CM로 환산
  
  tone(8,1000,20);
  delay(100); //0.1초마다 거리를 측정하도록 설정
  tone(8,1000,20);
  delay(distance*10);  //거리에 따라 tone주기 설정(자동차 후진 등에 사용)

}
