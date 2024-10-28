#include "I2C.h"

#include "Driver_I2C.h"

#include <cstdint>

I2C::I2C(ARM_DRIVER_I2C *drv) : m_drv(drv) {
  m_drv->Initialize(NULL);
  m_drv->PowerControl(ARM_POWER_FULL);
  m_drv->Control(ARM_I2C_BUS_SPEED, ARM_I2C_BUS_SPEED_STANDARD);
}

I2C::~I2C() {
  m_drv->Uninitialize();
}

void I2C::read(uint8_t addr, uint8_t reg, uint8_t num, uint8_t *val) {
  // Selects the internal register to be read from
  m_drv->MasterTransmit(addr, &reg, 1, true);
  while (m_drv->GetStatus().busy) {}

  // Reads data from the register
  m_drv->MasterReceive(addr, val, num, false);
  while (m_drv->GetStatus().busy) {}
}

void I2C::write(uint8_t addr, uint8_t reg, uint8_t num, uint8_t const *val) {
  // Transmits both the internal register and the data to be written
  uint8_t temp[1 + num];
  temp[0] = reg;
  for (int i = 0; i < num; ++i)
    temp[1 + i] = val[i];

  m_drv->MasterTransmit(addr, temp, 1 + num, false);
  while (m_drv->GetStatus().busy) {}
}
