#include <SPI.h>
#include <MFRC522.h>

MFRC522 RFIDReader(10, 9);

void setup()
{
  SPI.begin();
  RFIDReader.PCD_Init();
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
}

void loop()
{
  if (!RFIDReader.PICC_IsNewCardPresent() || !RFIDReader.PICC_ReadCardSerial()) return;
  
  String content = "";
  for (byte i = 0; i < RFIDReader.uid.size; i++) {
    content.concat(String(RFIDReader.uid.uidByte[i] < 0x10 ? " 0" : " "));
    content.concat(String(RFIDReader.uid.uidByte[i], HEX));
  }
  
  content.toUpperCase();
  content = content.substring(1);
  if (content == "32 D9 5B 1A") {
    digitalWrite(3, HIGH);
    delay(3000);
    digitalWrite(3, LOW);
  } else {
    digitalWrite(2, HIGH);
    delay(3000);
    digitalWrite(2, LOW);
  }
}
