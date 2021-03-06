#include "arinc429_service.h"

int arinc429[11] = {0};
void SetArinc429CtlReg(ARINC429_CTL_REG ctlRegVal)
{
    Uint16 opcode = 0x10;

    Assert_CS_Pin();

    SpiaRegs.SPITXBUF = (opcode)<< 8;
    SpiaRegs.SPITXBUF = (ctlRegVal.HighLowByte.HighByte << 8);
    SpiaRegs.SPITXBUF = (ctlRegVal.HighLowByte.LowByte << 8);

    while(SpiaRegs.SPIFFRX.bit.RXFFST < 3);
    arinc429[0] = SpiaRegs.SPIRXBUF;
    arinc429[1] = SpiaRegs.SPIRXBUF;
    arinc429[2] = SpiaRegs.SPIRXBUF;

    Deassert_CS_Pin();
}

Uint16 ReadArinc429StatusReg(void)
{
    int ret;
    Uint16 opcode = 0x0A;

    Assert_CS_Pin();

    SpiaRegs.SPITXBUF = (opcode << 8);
    SpiaRegs.SPITXBUF = (0x0000 << 8);

    while(SpiaRegs.SPIFFRX.bit.RXFFST < 2);
    arinc429[3] = SpiaRegs.SPIRXBUF;
    arinc429[4] = SpiaRegs.SPIRXBUF;

    ret = arinc429[3];
    ret = ret << 8;
    ret = ret | arinc429[4];


    Deassert_CS_Pin();

    return ret;
}

Uint16 ReadArinc429CtlReg(void)
{
    Uint16 opcode = 0x0D;
    Uint16 ret;

    Assert_CS_Pin();
  
    SpiaRegs.SPITXBUF = (opcode << 8);
    SpiaRegs.SPITXBUF = (0x0000 << 8);
    SpiaRegs.SPITXBUF = (0x0000 << 8);
    while(SpiaRegs.SPIFFRX.bit.RXFFST < 3);
    arinc429[5] = SpiaRegs.SPIRXBUF;
    arinc429[6] = SpiaRegs.SPIRXBUF;
    arinc429[7] = SpiaRegs.SPIRXBUF;

    ret = arinc429[6];
    ret = ret << 8;
    ret = ret | arinc429[7];

    Deassert_CS_Pin();

    return ret;
}



