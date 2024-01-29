#define NOTE_C4 262
#define NOTE_D4 294
#define NOTE_E4 330

int pins[] = {2, 3, 4};
int notes[] = {NOTE_E4, NOTE_D4, NOTE_C4};

void setup() {
  for (int i = 0; i < 3; i++) {
    pinMode(pins[i], INPUT);
  }
  pinMode(8, OUTPUT); // 부저를 제어할 핀을 출력으로 설정
}

void loop() {
  for (int i = 0; i < 3; i++) {
    if (digitalRead(pins[i]) == HIGH) { // 괄호 위치 수정
      tone(8, notes[i], 200);  // 음의 재생 길이를 늘임 (20에서 200으로, 박자)
      delay(500); // 잠시 소리를 듣기 위해 대기
      noTone(8);  // 소리 중단
    }
  }
}
