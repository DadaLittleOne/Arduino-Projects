// Buttons
#define B1 13
#define B2 12
#define B3 11
#define B4 10

// 7-Segment Display
#define Sg 8
#define Sf 7
#define Sa 6
#define Sb 5
#define Se 4
#define Sd 3
#define Sc 2

byte number;
byte lastNumber = 0;

boolean numbers[10][4] = {
  {false, false, false, false}, // 0
  {false, false, false, true}, // 1
  {false, false, true, false}, // 2
  {false, false, true, true}, // 3
  {false, true, false, false}, // 4
  {false, true, false, true}, // 5
  {false, true, true, false}, // 6
  {false, true, true, true}, // 7
  {true, false, false, false}, // 8
  {true, false, false, true}  // 9
};

boolean segSt[10][7] = {
  // Sf Sa Sb Sg Se Sd Sc
  {true, true, true, false, true, true, true}, // 0
  {false, false, true, false, false, false, true}, // 1
  {false, true, true, true, true, true, false}, // 2
  {false, true, true, true, false, true, true}, // 3
  {true, false, true, true, false, false, true}, // 4
  {true, true, false, true, false, true, true}, // 5
  {true, true, false, true, true, true, true}, // 6
  {false, true, true, false, false, false, true}, // 7
  {true, true, true, true, true, true, true}, // 8
  {true, true, true, true, false, true, true}, // 9
};

void displayNum(int c) {
  segSt[c][0] ? digitalWrite(Sf, HIGH) : digitalWrite(Sf, LOW);
  segSt[c][1] ? digitalWrite(Sa, HIGH) : digitalWrite(Sa, LOW);
  segSt[c][2] ? digitalWrite(Sb, HIGH) : digitalWrite(Sb, LOW);
  segSt[c][3] ? digitalWrite(Sg, HIGH) : digitalWrite(Sg, LOW);
  segSt[c][4] ? digitalWrite(Se, HIGH) : digitalWrite(Se, LOW);
  segSt[c][5] ? digitalWrite(Sd, HIGH) : digitalWrite(Sd, LOW);
  segSt[c][6] ? digitalWrite(Sc, HIGH) : digitalWrite(Sc, LOW);
}

bool compare(byte Key[], boolean numbers[]) {
  for (byte i = 0; i <= 3; ++i) if (Key[i] != numbers[i] == 1 ? true : false) return false;
  return true;
}

void setup() {
  pinMode(Sf, OUTPUT);
  pinMode(Sa, OUTPUT);
  pinMode(Sb, OUTPUT);
  pinMode(Sg, OUTPUT);
  pinMode(Se, OUTPUT);
  pinMode(Sd, OUTPUT);
  pinMode(Sc, OUTPUT);

  pinMode(B1, INPUT);
  pinMode(B2, INPUT);
  pinMode(B3, INPUT);
  pinMode(B4, INPUT);
}

void loop() {
  byte Key[] = {digitalRead(B1), digitalRead(B2), digitalRead(B3), digitalRead(B4)};
  
  for (byte i = 0; i <= 9; ++i) if (compare(Key, numbers[i])) number = i;
  if (number != lastNumber) displayNum(number); 
  lastNumber = number;
}