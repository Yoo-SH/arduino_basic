#define TRIG 2
#define ECHO 3
#define BLUE 9
#define GREEN 10
#define RED 11


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
  analogWrite(RED,0);
  analogWrite(GREEN,0);
  analogWrite(BLUE,0);

  if(distance<10)
    analogWrite(RED,255);
  else if(distance<20)
    analogWrite(GREEN,255);
  else if(distance<30)
    analogWrite(BLUE,255);

    delay(100); //0.1초마다 거리를 측정하도록 설정

}
