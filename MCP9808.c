#include "comdef.h"
#include "hal_board_cfg.h"
#include "hal_drivers.h"
#include "osal.h"
#include "hal_i2c.h"
#include "math.h"
#include "MCP9808.h"

void DelayMS(uint16 msec)
{ 
    uint16 i,j;
    
    for (i=0; i<msec; i++)
        for (j=0; j<536*2; j++);
}

typedef union {
uint16 var_16;
uint8 var_8[2];
} uint_convert;

typedef union {
uint16 var_16[2];
float var_float;
} uint_convert_float;


/* Gerçeklenecekler

bool mcp9808_begin(uint8 addr);
float mcp9808_readTempF( void );
float mcp9808_readTempC( void );
void mcp9808_shutdown_wake( uint8 sw_ID );
void mcp9808_wake(void);
void mcp9808_write16(uint8 reg, uint16 val);
uint16 mcp9808_read16(uint8 reg);

*/



void mcp9808_select(){
//   DelayMS(100);
HalI2CInit(MCP9808_I2CADDR_DEFAULT,i2cClock_33KHZ );
// DelayMS(100);
}

void mcp9808_write16(uint8 reg, uint16 val){
uint_convert temp;
temp.var_16= val;
//  DelayMS(300);
HalI2CWrite(1, &reg); 
//   DelayMS(300);
HalI2CWrite(2, &temp.var_8[0]);
//  DelayMS(300);
//HalI2CWrite(1, &temp.var_8[0]);



  
}



uint16 mcp9808_read16(uint8 reg){
  uint_convert temp;
//    DelayMS(300);
  HalI2CWrite(1, &reg); 
//    DelayMS(300);
  HalI2CRead(2,  &temp.var_8[0]); 
//    DelayMS(300);
  //HalI2CRead(1,  &temp.var_8[0]);
return temp.var_16;
 
  
  
}
float mcp9808_readTempC( void ){
mcp9808_select();
uint_convert tt;
uint16 t = mcp9808_read16(MCP9808_REG_AMBIENT_TEMP);
tt.var_16=t;
//float temp = t & 0x0FFF;
//temp /=  16.0;
//if (t & 0x1000) temp=256-temp;// -=256;
float temp=tt.var_8[0]*16.0 + tt.var_8[1]/16.0;
if (t & 0x1000) temp-=256;
return temp;
}

bool mcp9808_begin() {
  
//DelayMS(300);
 HalI2CInit(MCP9808_I2CADDR_DEFAULT,i2cClock_33KHZ);
//DelayMS(300); 
 if (mcp9808_read16(MCP9808_REG_MANUF_ID) == 0x0054) return false;
//  DelayMS(300);
 if (mcp9808_read16(MCP9808_REG_DEVICE_ID) == 0x0400) return false;
// DelayMS(300);
 mcp9808_write16(MCP9808_REG_CONFIG, 0x0000);
// DelayMS(300);
return true;
}


void  bh1750_select(){
HalI2CInit(BH1750_addr,i2cClock_33KHZ);
}

float bh1750_read( void ){
bh1750_select();
uint16 t = mcp9808_read16(0x23);
return t;
}

