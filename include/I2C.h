#pragma once

#include "Driver_I2C.h"

#include <cstdint>

class I2C {

private:
  ARM_DRIVER_I2C *m_drv;

public:
  I2C(ARM_DRIVER_I2C *drv);

  ~I2C();

  void read(uint8_t addr, uint8_t reg, uint8_t num, uint8_t *val);

  void write(uint8_t addr, uint8_t reg, uint8_t num, uint8_t const *val);
};
