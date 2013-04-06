//
//  RoundTable.h
//  CCRoundTableViewTest
//
//  Created by 陶 然景 on 13-4-3.
//
//

#ifndef __CCRoundTableViewTest__RoundTable__
#define __CCRoundTableViewTest__RoundTable__

#include "cocos-ext.h"
#include "cocos2d.h"
USING_NS_CC;
USING_NS_CC_EXT;


class RoundTable: public CCSprite {
public:
    RoundTable();
    ~RoundTable();
    
    CREATE_FUNC(RoundTable);
    virtual bool init();
    
    void update(float dt);
    
    
    CC_SYNTHESIZE(float, m_fCurrentAngle, CurrentAntle);
    CC_SYNTHESIZE_RETAIN(CCSprite*, m_pRoundTableSprite, RoundTableSprite);
    
    void setTextureRect(const CCRect& rect, bool rotated, const CCSize& untrimmedSize);
};

#endif /* defined(__CCRoundTableViewTest__RoundTable__) */
