#include <cc1101.h>
#include <macros.h>
#include <pins.h>
#include <registers.h>

#define packetSize 10
#define dataRate 4
#define logChannel 5

byte RX_buffer[10] = {0};
byte sizeRX;

void setup() {
  Serial.begin(9600);
  
  pinMode(RED_LED, OUTPUT);
  digitalWrite(RED_LED, LOW);
  
  Radio.Init();
  Radio.SetDataRate(dataRate);
  Radio.SetLogicalChannel(logChannel);
  Radio.SetTxPower(1);

  Radio.RxOn();
}

void loop() {
  if (Radio.CheckReceiveFlag()) {
    digitalWrite(RED_LED, HIGH);
    
    sizeRX = Radio.ReceiveData(RX_buffer);

    int xVal = RX_buffer[1] | (RX_buffer[2] << 8);
    int yVal = RX_buffer[3] | (RX_buffer[4] << 8);
    int zVal = RX_buffer[5] | (RX_buffer[6] << 8);

    Serial.print("packet num: ");
    Serial.println(RX_buffer[0]);
    Serial.print("x: ");
    Serial.println(xVal);
    Serial.print("y: ");
    Serial.println(yVal);
    Serial.print("z: ");
    Serial.println(zVal); 

    delay(500);
    digitalWrite(RED_LED, LOW);

    Radio.RxOn();
  }
}
