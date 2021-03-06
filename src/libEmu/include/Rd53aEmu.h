#ifndef __RD53A_EMU_H__
#define __RD53A_EMU_H__

#define HEXF(x,y) std::hex << "0x" << std::hex << std::setw(x) << std::setfill('0') << static_cast<int>(y) << std::dec

#include "Rd53aCfg.h"
#include "EmuShm.h"
#include "RingBuffer.h"
#include "Gauss.h"

#include "Rd53aLinPixelModel.h"
#include "Rd53aDiffPixelModel.h"

#include "FrontEndGeometry.h"
#include "json.hpp"

#include "Histo1d.h"
#include "Histo2d.h"

#include "RingBuffer.h"

#include <cstdint>
#include <memory>

class Rd53aEmu {
    public:
        Rd53aEmu(RingBuffer * rx, RingBuffer * tx);
        ~Rd53aEmu();

        // the main loop which recieves commands from yarr
        void executeLoop();

        // functions for dealing with sending data to yarr
        void pushOutput(uint32_t value);

        RingBuffer * m_txRingBuffer;
        RingBuffer * m_rxRingBuffer;
        std::shared_ptr<Rd53aCfg> m_feCfg;

	uint8_t m_pixelRegisters[400][192];
	Rd53aLinPixelModel* m_rd53aLinPixelModelObjects[136][192];
	Rd53aDiffPixelModel* m_rd53aDiffPixelModelObjects[136][192];

        uint32_t m_header;
        uint32_t m_id_address_some_data;
        uint32_t m_small_data;

        volatile bool run;

        Histo1d* linScurve[136][192];
        Histo1d* linThreshold;

        Histo1d* diffScurve[136][192];
        Histo1d* diffThreshold;

        Histo2d* analogHits;
};

#endif //__RD53A_EMU_H__
