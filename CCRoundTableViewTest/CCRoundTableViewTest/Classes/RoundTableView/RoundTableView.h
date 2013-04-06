//
//  RoundTableView.h
//  CrossKaiser
//
//  Created by 陶 然景 on 13-4-3.
//
//

#ifndef __CrossKaiser__RoundTableView__
#define __CrossKaiser__RoundTableView__

#include "cocos-ext.h"
#include "cocos2d.h"
#include "RoundTable.h"
USING_NS_CC;
USING_NS_CC_EXT;


class RoundTableView: public CCLayer
{
public:
    RoundTableView();
    ~RoundTableView();
    
    CREATE_FUNC(RoundTableView);
    virtual bool init();

    CC_SYNTHESIZE_RETAIN(CCArray*, m_pSpriteArray, Array);
    CC_SYNTHESIZE_RETAIN(RoundTable*, m_pRoundTable, RoundTable);
    CC_SYNTHESIZE(float, m_fCurrentAngle, CurrentAngle);

void update(float dt);

private:
    void getCurretStatusByAngle(CCPoint &point, int &alpha, int &zOrder, float &scale, float angle);
};

#endif /* defined(__CrossKaiser__RoundTableView__) */
