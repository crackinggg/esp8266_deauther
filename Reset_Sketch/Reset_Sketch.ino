#include <EEPROM.h>
#include <LittleFS.h>

void setup() {
  Serial.begin(115200);
  Serial.println("STARTING...");

  // Initialize EEPROM
  EEPROM.begin(4096);
  Serial.println("EEPROM initialized");
  
  // Clear EEPROM
  for (int i = 0; i < 4096; ++i){
    EEPROM.write(i, 0x00);
  }
  EEPROM.commit(); // Commit changes
  Serial.println("EEPROM cleaned");

  // Initialize SPIFFS
  if (LittleFS.begin()) {
    Serial.println("SPIFFS initialized");
    
    // Format and clear SPIFFS
    LittleFS.format();
    Serial.println("SPIFFS cleaned");
  } else {
    Serial.println("SPIFFS initialization failed");
  }

  // Erase WiFi credentials
  ESP.eraseConfig();
  Serial.println("WiFi credentials erased");

  Serial.println("DONE!");

  delay(10000);
  ESP.reset();
}

void loop() {
  // Empty loop
}
