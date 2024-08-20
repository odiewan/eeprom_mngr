#ifndef EEPROM_MNGR_H
#define EEPROM_MNGR_H


#include <Arduino.h>
#include <EEPROM.h>

#define EEPROM_SIZE             512
#define EEPROM_DELAY            5

class eeprom_mngr {
  public:
  
    eeprom_mngr();
    void setEepromReg(uint8_t nIdx, uint8_t nV);
    uint8_t getEepromReg(uint8_t nIdx);
    void writeEEPROM();
    void readEEPROM();
    String printEEPROM();


  private:
    int writeEepromReg(uint16_t nIdx);
    uint8_t eeprom[EEPROM_SIZE];
    uint8_t eeprom_live[EEPROM_SIZE];

};


#endif