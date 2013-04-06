//
//  RoundTableKnight.h
//  CrossKaiser
//
//  Created by 陶 然景 on 13-4-3.
//
//

#ifndef __CrossKaiser__RoundTableKnight__
#define __CrossKaiser__RoundTableKnight__

#include "cocos-ext.h"
#include "cocos2d.h"
USING_NS_CC;
USING_NS_CC_EXT;

class RoundTableKnight: public CCLayer {
public:
    RoundTableKnight();
    ~RoundTableKnight();
    
CREATE_FUNC(RoundTableKnight);
virtual bool init();

CC_SYNTHESIZE(float, m_fCurrentAngle, CurrentAngle);
};

#endif /* defined(__CrossKaiser__RoundTableKnight__) */
