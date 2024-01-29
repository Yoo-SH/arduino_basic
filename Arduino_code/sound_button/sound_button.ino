

void setup() {

}

void loop() {
 analogWrite(9,map(analogRead(A0),0,1023,0,255));  
}
