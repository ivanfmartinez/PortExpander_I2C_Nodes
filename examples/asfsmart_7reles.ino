#include <Homie.h>

#include <PortExpander_I2C_Nodes.hpp>


int pin_SDA = 0;
int pin_SCL = 2;

// https://www.afeletronica.com.br/pd-4d1faf-esp-8266-modulo-afsmart-7-reles.html?ct=1d09d1&p=1&s=1
PortExpander_I2C reles(0x27);
PortExpander_I2C entradas(0x26); // SE PCF8574T
//PortExpander_I2C entradas(0x3F); // SE PCF8574AT


ExpanderRelayNode rele1 = ExpanderRelayNode("relay1", 0, &reles);
ExpanderRelayNode rele2 = ExpanderRelayNode("relay2", 1, &reles);
ExpanderRelayNode rele3 = ExpanderRelayNode("relay3", 2, &reles);
ExpanderRelayNode rele4 = ExpanderRelayNode("relay4", 3, &reles);
ExpanderRelayNode rele5 = ExpanderRelayNode("relay5", 4, &reles);
ExpanderRelayNode rele6 = ExpanderRelayNode("relay6", 5, &reles);
ExpanderRelayNode rele7 = ExpanderRelayNode("relay7", 6, &reles);


ExpanderContactNode contact1 = ExpanderContactNode("contact1", 0, &entradas);
ExpanderContactNode contact2 = ExpanderContactNode("contact2", 1, &entradas);
ExpanderContactNode contact3 = ExpanderContactNode("contact3", 2, &entradas);
ExpanderContactNode contact4 = ExpanderContactNode("contact4", 3, &entradas);
ExpanderContactNode contact5 = ExpanderContactNode("contact5", 4, &entradas);
ExpanderContactNode contact6 = ExpanderContactNode("contact6", 5, &entradas);
ExpanderContactNode contact7 = ExpanderContactNode("contact7", 6, &entradas);
ExpanderContactNode contact8 = ExpanderContactNode("contact8", 7, &entradas);




void setupHandler() {
  rele1.setRelay(false);
  rele2.setRelay(false);
  rele3.setRelay(false);
  rele4.setRelay(false);
  rele5.setRelay(false);
  rele6.setRelay(false);
  rele7.setRelay(false);
}

void setup() {
  Serial.begin(115200);
  Serial << endl << endl;

  Wire.begin(pin_SDA, pin_SCL);
  reles.init();
  entradas.init();

  Homie_setFirmware("ifm-asfsmart-7r-inputs", "1.0.2");
  
  relayBeforeHomieSetup();
  timestamp.beforeHomieSetup();

  Homie.setSetupFunction(setupHandler);
  Homie.setup();
}


void loop() {
  Homie.loop();
}

