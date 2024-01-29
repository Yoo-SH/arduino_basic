#define RED 9
#define GREEN 10
#define BLUE 11
#define RED_BUTTON 4
#define GREEN_BUTTON 5
#define BULE_BUTTON 6

int r=0, g=0, b=0;

void setup() {
  pinMode(RED_BUTTON,INPUT);
  pinMode(GREEN_BUTTON,INPUT);
  pinMode(BULE_BUTTON,INPUT);

}

void loop() {
  if(digitalRead(RED_BUTTON) == HIGH)
  {
    ++r;
    if(r>255)
      r=0;    
  }
  else if(digitalRead(GREEN_BUTTON) == HIGH)
  {
    ++g;
    if(g>255)
      g=0;
  }
  else if(digitalRead(BULE_BUTTON) == HIGH)
  {
    ++b;
    if(b>255)
      b=0;
  }

  analogWrite(RED,r);
  analogWrite(GREEN,g);
  analogWrite(BLUE,b);

}
