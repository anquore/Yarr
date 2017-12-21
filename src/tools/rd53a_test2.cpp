#include <iostream>
#include <chrono>
#include <unistd.h>
#include "SpecController.h"

#define EN_RX2 0x1
#define EN_RX1 0x2
#define EN_RX4 0x4
#define EN_RX3 0x8
#define EN_RX6 0x10
#define EN_RX5 0x20
#define EN_RX8 0x40
#define EN_RX7 0x80

#define EN_RX10 0x100
#define EN_RX9 0x200
#define EN_RX12 0x400
#define EN_RX11 0x800
#define EN_RX14 0x1000
#define EN_RX13 0x2000
#define EN_RX16 0x4000
#define EN_RX15 0x8000

#define EN_RX18 0x10000
#define EN_RX17 0x20000
#define EN_RX20 0x40000
#define EN_RX19 0x80000
#define EN_RX22 0x100000
#define EN_RX21 0x200000
#define EN_RX24 0x400000
#define EN_RX23 0x800000

int main(void) {

    SpecController spec;
    
    //Send IO config to FMC
    //spec.writeSingle(0x6<<14 | 0x0, 0x55555555);
    spec.writeSingle(0x6<<14 | 0x0, EN_RX1 | EN_RX3 | EN_RX4 | EN_RX5);
    spec.writeSingle(0x6<<14 | 0x1, 0xF);
    spec.setCmdEnable(0x1);
    spec.writeFifo(0x6666d271);
    //spec.writeFifo(0x6a6c6ac6);
    //spec.writeFifo(0x69696969);
    //spec.writeFifo(0x5a5a6969);

    return 0;
}
