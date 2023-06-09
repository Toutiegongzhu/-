#ifndef __BSP_I2C_H
#define __BSP_I2C_H

#include "main.h"

void I2CStart(void);
void I2CStop(void);
unsigned char I2CWaitAck(void);
void I2CSendAck(void);
void I2CSendNotAck(void);
void I2CSendByte(unsigned char cSendByte);
unsigned char I2CReceiveByte(void);
void I2CInit(void);

uchar eeprom_read(uchar address);
void eeprom_write(uchar address, uchar data);

#endif
