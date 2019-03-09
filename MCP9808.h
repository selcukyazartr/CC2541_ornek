#include "hal_i2c.h"
#include "comdef.h"


#define MCP9808_I2CADDR_DEFAULT        0x18
#define MCP9808_REG_CONFIG             0x01

#define MCP9808_REG_CONFIG_SHUTDOWN    0x0100
#define MCP9808_REG_CONFIG_CRITLOCKED  0x0080
#define MCP9808_REG_CONFIG_WINLOCKED   0x0040
#define MCP9808_REG_CONFIG_INTCLR      0x0020
#define MCP9808_REG_CONFIG_ALERTSTAT   0x0010
#define MCP9808_REG_CONFIG_ALERTCTRL   0x0008
#define MCP9808_REG_CONFIG_ALERTSEL    0x0004
#define MCP9808_REG_CONFIG_ALERTPOL    0x0002
#define MCP9808_REG_CONFIG_ALERTMODE   0x0001

#define MCP9808_REG_UPPER_TEMP         0x02
#define MCP9808_REG_LOWER_TEMP         0x03
#define MCP9808_REG_CRIT_TEMP          0x04
#define MCP9808_REG_AMBIENT_TEMP       0x05
#define MCP9808_REG_MANUF_ID           0x06
#define MCP9808_REG_DEVICE_ID          0x07
//bool mcp_ready=FALSE;


extern void HalI2CInit(uint8 address, i2cClock_t clockRate); //baska bir c dosyasindan fonksiyon çagiracaksan ekleyeceksin


bool mcp9808_begin();
float mcp9808_readTempF( void );
float mcp9808_readTempC( void );
void mcp9808_shutdown_wake( uint8 sw_ID );
void mcp9808_wake(void);
void mcp9808_write16(uint8 reg, uint16 val);
uint16 mcp9808_read16(uint8 reg);



//   ISIK IÇIN //

#define BH1750_POWER_DOWN 0x00
#define BH1750_POWER_ON 0x01
#define BH1750_RESET 0x07
#define BH1750_addr 0x23
#define CONTINUOUS_HIGH_RES_MODE 0x10
#define CONTINUOUS_HIGH_RES_MODE_2  0x11
#define CONTINUOUS_LOW_RES_MODE  0x13
#define ONE_TIME_HIGH_RES_MODE 0x20
#define ONE_TIME_HIGH_RES_MODE_2 0x21
#define ONE_TIME_LOW_RES_MODE  0x23