#include <IRremote.hpp>

#define RECEIVER 2

void setup() {
  IrReceiver.begin(RECEIVER, ENABLE_LED_FEEDBACK);
  Serial.begin(9600);
}

void loop() {
  if (IrReceiver.decode()) {
   	IrReceiver.printIRResultShort(&Serial);
    IrReceiver.printIRSendUsage(&Serial);
    
    if (IrReceiver.decodedIRData.protocol == UNKNOWN) {
      Serial.println(F("Received noise or an unknown (or not yet enabled) protocol"));
      IrReceiver.printIRResultRawFormatted(&Serial, true);
    }

    Serial.println();
    IrReceiver.resume();
  }

  delay(100);
}