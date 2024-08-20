#include <eeprom_datum.h>


//-----------------------------------------------------------------------------
eeprom_datum::eeprom_datum() {
  constructor_core();
}


//-----------------------------------------------------------------------------
eeprom_datum::eeprom_datum(String nName, uint8_t nIdx, bool nVal, bool nDefVal) {
  constructor_core();
  edo_index = nIdx;
  edo_name = nName;
  edo_val = nVal;
  edo_def_val = nDefVal;
  set_eeprom_val(edo_val);

}

//-----------------------------------------------------------------------------
eeprom_datum::eeprom_datum(String nName, uint8_t nIdx, uint8_t nVal, uint8_t nDefVal) {
  constructor_core();
  edo_index = nIdx;
  edo_name = nName;
  edo_val = nVal;
  edo_def_val = nDefVal;
  edo_eeprom_val = nVal;

}


//-----------------------------------------------------------------------------
eeprom_datum::eeprom_datum(String nName, uint8_t nIdx, int8_t nVal, int8_t nDefVal) {
  constructor_core();
  edo_index = nIdx;
  edo_name = nName;
  edo_val = nVal;
  edo_def_val = nDefVal;
  edo_eeprom_val = nVal;
  set_eeprom_val(edo_val);
}

//-----------------------------------------------------------------------------
void eeprom_datum::constructor_core() {
  edo_eeprom_val = 0;
  edo_index = 0;
  edo_type = EE_DATA_TYPE_INT;
  edo_name = "Def eeprom datum";
  edo_val = 0;
  edo_def_val = 0;
}


//-----------------------------------------------------------------------------
void eeprom_datum::set_eeprom_val(bool nV) {
  edo_type = EE_DATA_TYPE_BOOL;
  edo_eeprom_val = (uint8_t)nV;
}

//-----------------------------------------------------------------------------
void eeprom_datum::set_eeprom_val(uint8_t nV) {
  edo_type = EE_DATA_TYPE_UINT;
  edo_eeprom_val = nV;
}

//-----------------------------------------------------------------------------
void eeprom_datum::set_eeprom_val(int8_t nV) {
  edo_type = EE_DATA_TYPE_INT;
  edo_eeprom_val = (uint8_t)(nV + 127);

}

//-----------------------------------------------------------------------------
int8_t eeprom_datum::get_eng_val() {

  switch (edo_type) {
    default:
    case EE_DATA_TYPE_UINT:
      edo_val = edo_eeprom_val;
      break;

    case EE_DATA_TYPE_BOOL:
      edo_val = edo_eeprom_val;

      break;

    case EE_DATA_TYPE_INT:
      edo_val = (int8_t)edo_eeprom_val - 127;

      break;
  }
  return edo_val;
}

//-----------------------------------------------------------------------------
void eeprom_datum::set_eng_val(bool nV) {

}

//-----------------------------------------------------------------------------
void eeprom_datum::set_eng_val(uint8_t nV) {

}

//-----------------------------------------------------------------------------
void eeprom_datum::set_eng_val(int8_t nV) {

}
