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

    Serial.print("packet num: ");
    Serial.println(RX_buffer[0]);
    Serial.print("x: ");
    Serial.println(RX_buffer[1]);
    Serial.print("y: ");
    Serial.println(RX_buffer[2]);
    Serial.print("z: ");
    Serial.println(RX_buffer[3]); 

    delay(10);
    digitalWrite(RED_LED, LOW);
  }
}
