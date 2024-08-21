#ifndef EEPROM_DATUM_H
#define EEPROM_DATUM_H

#include <Arduino.h>

enum eeprom_obj_types {
  EE_DATA_TYPE_BOOL,
  EE_DATA_TYPE_INT,
  EE_DATA_TYPE_UINT,
  NUM_EE_DATA_TYPES,
  };

class eeprom_datum {
  public:
    uint8_t edo_type;
    String edo_name;
    uint8_t edo_val;
    uint8_t edo_def_val;


    eeprom_datum();
    eeprom_datum(String nName, uint8_t nIdx, bool nVal, bool nDefVal);
    eeprom_datum(String nName, uint8_t nIdx, uint8_t nVal, uint8_t nDefVal);
    eeprom_datum(String nName, uint8_t nIdx, int8_t nVal, int8_t nDefVal);

    eeprom_datum(String nName, uint8_t nIdx, bool nVal);
    eeprom_datum(String nName, uint8_t nIdx, uint8_t nVal);
    eeprom_datum(String nName, uint8_t nIdx, int8_t nVal);

    int8_t get_eng_val();
    void set_eng_val(bool nV);
    void set_eng_val(uint8_t nV);
    void set_eng_val(int8_t nV);

  private:
    uint8_t edo_eeprom_val;
    uint8_t edo_index;
    void constructor_core();
    int8_t get_eeprom_val() { return edo_eeprom_val; }
    void set_eeprom_val(bool nV);
    void set_eeprom_val(uint8_t nV);
    void set_eeprom_val(int8_t nV);




};




#endif