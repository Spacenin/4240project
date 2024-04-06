#include <cc1101.h>
#include <macros.h>
#include <pins.h>
#include <registers.h>

#define X A3
#define Y A4
#define Z A5

#define packetSize 10
#define dataRate 4
#define logChannel 5

byte TX_buffer[packetSize] = {0};
int packetNum = 0;

void setup() {
  Serial.begin(9600);
  
  pinMode(RED_LED, OUTPUT);
  digitalWrite(RED_LED, LOW);

  Radio.Init();
  Radio.SetDataRate(dataRate);
  Radio.SetLogicalChannel(logChannel);
  Radio.SetTxPower(0);
}

void loop() {
    digitalWrite(RED_LED, HIGH);
    TX_buffer[0] = packetNum;

    for (int i = 0; i < 10; ++i) {
      int xVal = analogRead(X);
      int yVal = analogRead(Y);
      int zVal = analogRead(Z);
      
      TX_buffer[1] = map(xVal, 0, 4095, 0, 255);
      TX_buffer[2] = map(yVal, 0, 4095, 0, 255);
      TX_buffer[3] = map(zVal, 0, 4095, 0, 255);

      Serial.print("packet num: ");
      Serial.println(TX_buffer[0]);
      Serial.print("x: ");
      Serial.println(TX_buffer[1]);
      Serial.print("y: ");
      Serial.println(TX_buffer[2]);
      Serial.print("z: ");
      Serial.println(TX_buffer[3]); 

      Radio.SendData(TX_buffer, packetSize);
      delay(50);
    }
}
