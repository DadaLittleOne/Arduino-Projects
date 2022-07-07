#define RED 2
#define GREEN 3
#define BLUE 4

#define BUTTON 5

int state = 0;
int last = 0;

void setup() {
  Serial.begin(9600);
  pinMode(BUTTON, INPUT);

  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);
}

void changeRed() {
  digitalWrite(RED, HIGH);
  digitalWrite(GREEN, LOW);
  digitalWrite(BLUE, LOW);
}

void changeGreen() {
  digitalWrite(RED, LOW);
  digitalWrite(GREEN, HIGH);
  digitalWrite(BLUE, LOW);
}

void changeBlue() {
  digitalWrite(RED, LOW);
  digitalWrite(GREEN, LOW);
  digitalWrite(BLUE, HIGH);
}

void loop(){
  int b = digitalRead(BUTTON);

  if (b == 1 && last == 0) {
    state++;
  }
  
  switch(state) {
    case 0:
      changeRed();
      break;
     case 1:
      changeGreen();
      break;
     case 2:
      changeBlue();
      break;
     default:
      state = 0;
      break;
  }
  
  Serial.print("Button pressed: ");
  Serial.print(b);
  Serial.print("\n");

  last = b;
}
