#include <eeprom_mngr.h>

//=================================================================================================
eeprom_mngr::eeprom_mngr() {
  eeprom[EEPROM_SIZE] = {};
  eeprom_live[EEPROM_SIZE] = {};
}

//=================================================================================================
void eeprom_mngr::setEepromReg(uint8_t nIdx, uint8_t nV) {
  eeprom_live[nIdx] = nV;

}

//=================================================================================================
uint8_t eeprom_mngr::getEepromReg(uint8_t nIdx){
  return eeprom_live[nIdx];
}

//================================4=================================================================
int eeprom_mngr::writeEepromReg(uint16_t nIdx) {

  if (eeprom_live[nIdx] != eeprom[nIdx]) {
    eeprom[nIdx] = eeprom_live[nIdx];
    EEPROM.write(nIdx, eeprom[nIdx]);
    return 1;
    }
  else {
    return 0;
    }

  }

//=================================================================================================
void eeprom_mngr::writeEEPROM() {
  int byte_write_cnt = 0;


  for (int i = 0; i < NUM_EEPROM_REG; i++) {

    byte_write_cnt += writeEepromReg(i);
    delay(EEPROM_DELAY);
    }

  }


//=================================================================================================
void eeprom_mngr::readEEPROM() {
  int byte_read_cnt = 0;

  for (int i = 0; i < NUM_EEPROM_REG; i++) {
    eeprom[i] = EEPROM.read(i);
    eeprom_live[i] = eeprom[i];
    byte_read_cnt++;
    }
  // memcpy(eeprom_live, eeprom, sizeof(eeprom_live));


  }

//=================================================================================================
String eeprom_mngr::printEEPROM() {
  String tmpStr;

  for (int i = 0; i < NUM_EEPROM_REG; i++) {
    tmpStr = "print_eeprom_live()[";
    tmpStr += i;
    tmpStr += "]:";
    tmpStr += eeprom_live[i];
    tmpStr += " e:";
    tmpStr += eeprom[i];
    tmpStr += "\n";
  }
  return tmpStr;
}