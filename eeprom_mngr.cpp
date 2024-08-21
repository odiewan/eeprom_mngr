#include <eeprom_mngr.h>

//=================================================================================================
eeprom_mngr::eeprom_mngr() {
  for(int i = 0; i < EEPROM_SIZE; i++) {
    eeprom[i] = 0;
    eeprom_live[i] = eeprom[i];
  }
  if(Serial)
    Serial.print(printEEPROM());
}

//=================================================================================================
void eeprom_mngr::setEepromReg(uint8_t nIdx, bool nV) {
  eeprom_live[nIdx] = (uint8_t)nV;

}

//=================================================================================================
void eeprom_mngr::setEepromReg(uint8_t nIdx, int8_t nV) {
  eeprom_live[nIdx] = (uint8_t)(nV + 127);

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
    if(Serial){
      Serial.print("reg:");
      Serial.print(nIdx);
      Serial.println(" changed: write");
    }
    return 1;
  }
  else {
    // if(Serial)
      // Serial.println(" unchanged: skip");
    return 0;
  }

}

//=================================================================================================
void eeprom_mngr::writeEEPROM() {
  int byte_write_cnt = 0;


  for (int i = 0; i < EEPROM_SIZE; i++) {

    byte_write_cnt += writeEepromReg(i);
    delay(EEPROM_DELAY);
  }
  if (Serial) {
    Serial.print("wrote ");
    Serial.print(byte_write_cnt);
    Serial.println(" bytes");
  }
}


//=================================================================================================
void eeprom_mngr::readEEPROM() {
  int byte_read_cnt = 0;

  for (int i = 0; i < EEPROM_SIZE; i++) {
    eeprom[i] = EEPROM.read(i);
    eeprom_live[i] = eeprom[i];
    byte_read_cnt++;
  }
  // memcpy(eeprom_live, eeprom, sizeof(eeprom_live));
}

//=================================================================================================
String eeprom_mngr::printEEPROM() {
  return printEEPROM(EEPROM_SIZE);
}
//=================================================================================================
String eeprom_mngr::printEEPROM(int lim) {
  String tmpStr = "";

  for (int i = 0; i < lim; i++) {
    tmpStr += "e_live[";
    tmpStr += i;
    tmpStr += "]:";
    tmpStr += eeprom_live[i];
    tmpStr += " e[";
    tmpStr += i;
    tmpStr += "]:";
    tmpStr += eeprom[i];
    tmpStr += "\n";
  }
  return tmpStr;
}