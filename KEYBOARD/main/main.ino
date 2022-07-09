// Buttons
#define B1 13
#define B2 12
#define B3 11
#define B4 10

// 7-Segment Display
#define Sf 7
#define Sa 6
#define Sb 5
#define Sg 8
#define Se 4
#define Sd 3
#define Sc 2

int numbers[10][4] = {
  {0, 0, 0, 0}, // 0
  {0, 0, 0, 1}, // 1
  {0, 0, 1, 0}, // 2
  {0, 0, 1, 1}, // 3
  {0, 1, 0, 0}, // 4
  {0, 1, 0, 1}, // 5
  {0, 1, 1, 0}, // 6
  {0, 1, 1, 1}, // 7
  {1, 0, 0, 0}, // 8
  {1, 0, 0, 1}  // 9
};

String segSt[10][7] = {
  // Sf Sa Sb Sg Se Sd Sc
  {"HIGH", "HIGH", "HIGH", "LOW", "HIGH", "HIGH", "HIGH"}, // 0
  {"LOW", "LOW", "HIGH", "LOW", "LOW", "LOW", "HIGH"}, // 1
  {"LOW", "HIGH", "HIGH", "HIGH", "HIGH", "HIGH", "LOW"}, // 2
  {"LOW", "HIGH", "HIGH", "HIGH", "LOW", "HIGH", "HIGH"}, // 3
  {"HIGH", "LOW", "HIGH", "HIGH", "LOW", "LOW", "HIGH"}, // 4
  {"HIGH", "HIGH", "LOW", "HIGH", "LOW", "HIGH", "HIGH"}, // 5
  {"HIGH", "HIGH", "LOW", "HIGH", "HIGH", "HIGH", "HIGH"}, // 6
  {"LOW", "HIGH", "HIGH", "LOW", "LOW", "LOW", "HIGH"}, // 7
  {"HIGH", "HIGH", "HIGH", "HIGH", "HIGH", "HIGH", "HIGH"}, // 8
  {"HIGH", "HIGH", "HIGH", "HIGH", "LOW", "HIGH", "HIGH"}, // 9
};

void displayNum(int c) {
  if (segSt[c][0] == "HIGH"){
    digitalWrite(Sf, HIGH);
  } else {
    digitalWrite(Sf, LOW);
  }
  if (segSt[c][1] == "HIGH"){
    digitalWrite(Sa, HIGH);   
  } else {
    digitalWrite(Sa, LOW);
  }
  if (segSt[c][2] == "HIGH"){
    digitalWrite(Sb, HIGH);  
  } else {
    digitalWrite(Sb, LOW);
  }
  if (segSt[c][3] == "HIGH"){
    digitalWrite(Sg, HIGH);   
  } else {
    digitalWrite(Sg, LOW);
  }
  if (segSt[c][4] == "HIGH"){
    digitalWrite(Se, HIGH);   
  } else {
    digitalWrite(Se, LOW);
  }
  if (segSt[c][5] == "HIGH"){
    digitalWrite(Sd, HIGH);   
  } else {
    digitalWrite(Sd, LOW);
  }
  if (segSt[c][6] == "HIGH"){
    digitalWrite(Sc, HIGH);   
  } else {
    digitalWrite(Sc, LOW);
  }
}

bool compareArray(int arr1[], int arr2[], int sizeArrs) {
  for (int i = 0; i <= sizeArrs; i++) {
    if (arr1[i] != arr2[i]) {
      return false;
    }
  }
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

  Serial.begin(9600);
}

void loop() {
  int Key[] = {digitalRead(B1), digitalRead(B2), digitalRead(B3), digitalRead(B4)};
  int number;
  
  for (int i = 0; i <= 9; i++) {
    if (compareArray(Key, numbers[i], 3)) {
      number = i;
    }
  }
  displayNum(number);
}
