#define BLUE 4
#define GREEN 5
#define RED 6
#define ANALOG_SOUND A5
#define DIGITAL_SOUND 2
#define RAW_VOLUME analogRead(ANALOG_SOUND)

int state = 0;

void setup() {
  Serial.begin(9600);
  pinMode(ANALOG_SOUND, INPUT);
  pinMode(DIGITAL_SOUND, INPUT);
  
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);
}

void loop() {
 int volume = map(RAW_VOLUME, 0, 1000, 0, 100);

 if (volume >= 5) {
  state++;
 }
 if (state == 3) {
  state = 0;
 }
 
 if (state == 0) {
  digitalWrite(BLUE, HIGH);
 } else if (state == 1) {
  digitalWrite(GREEN, HIGH);
 } else if (state == 2) {
  digitalWrite(RED, HIGH);
 }
 Serial.println(volume);
 digitalWrite(RED, LOW);
 digitalWrite(GREEN, LOW);
 digitalWrite(BLUE, LOW);
}
