//
//  RoundTableView.cpp
//  CrossKaiser
//
//  Created by 陶 然景 on 13-4-3.
//
//

#include "RoundTableView.h"
#include "RoundTableKnight.h"

#include <math.h>

RoundTableView::RoundTableView()
:m_pSpriteArray(NULL)
,m_fCurrentAngle(0)
,m_pRoundTable(NULL)
{
    
}

RoundTableView::~RoundTableView()
{
    CC_SAFE_RELEASE_NULL(m_pSpriteArray);
    CC_SAFE_RELEASE_NULL(m_pRoundTable);
}

bool RoundTableView::init()
{
    if (!CCLayer::init())
    {
        return false;
    }
    
    this->setContentSize(CCSizeMake(640, 960));
    
    if (m_pSpriteArray == NULL)
    {
        this->setArray(CCArray::create());
    }
    
    float anglePerKnight = 360 / 5;
    float startAngle = -90;
    
    for (int i = 0; i < 5; i ++)
    {
        RoundTableKnight *knight = RoundTableKnight::create();
        knight->setCurrentAngle(startAngle + anglePerKnight * i);
        this->getArray()->addObject(knight);
        CCPoint point = CCPointZero;
        int alhpa = 0;
        int zOrder = 0;
        float scale = 1;
        getCurretStatusByAngle(point, alhpa, zOrder, scale, knight->getCurrentAngle());
        knight->setPosition(point);
        knight->setScale(scale);
        this->addChild(knight);
    }
    
    this->setRoundTable(RoundTable::create());
    this->addChild(this->getRoundTable());
    //m_pRoundTable->setScaleY(0.5);
    m_pRoundTable->setPosition(ccp(200, 200));
    
    
    this->scheduleUpdate();
    return true;
}

void RoundTableView::getCurretStatusByAngle(CCPoint &point, int &alpha, int &zOrder, float &scale, float angle)
{
    float a = 200.0f;
    float b = 100.0f;
    float radius = angle * M_PI / 180.0;
    float r = a * b / sqrtf(a * a * sinf(radius) * sinf(radius) + b * b * cosf(radius) * cosf(radius));
    
    
    point.x = r * cosf(radius) + 200;
    point.y = r * sinf(radius) + 200;
    
    float k, m = 0;
    if (angle < 90)
    {
        k = -1.0f / 180;
        m = - 90.0f * k;
        scale = angle * k + m;
    }
    else
    {
        k = 1.0f / 180;
        m = - 90.0f * k;
        scale = angle * k + m;
    }    
}

void RoundTableView::update(float dt)
{
    CCObject *obj = NULL;
    CCARRAY_FOREACH(m_pSpriteArray, obj)
    {
        RoundTableKnight *knight = (RoundTableKnight*)obj;
        float angle = knight->getCurrentAngle();
        angle += 5;
        if (angle > 270)
        {
            angle -= 360;
        }
        if (angle < -90)
        {
            angle += 360;
        }
        
        knight->setCurrentAngle(angle);
        
        CCPoint point = CCPointZero;
        int alhpa = 0;
        int zOrder = 0;
        float scale = 1;
        getCurretStatusByAngle(point, alhpa, zOrder, scale, knight->getCurrentAngle());
        
        knight->setPosition(point);
        knight->setScale(scale);

    }
    
    
    m_fCurrentAngle += 5;
    
    if (m_fCurrentAngle > 360)
    {
        m_fCurrentAngle -= 360;
    }
    
    if (m_fCurrentAngle < 0)
    {
        m_fCurrentAngle += 360;
    }
    
  //  m_pRoundTable->setCurrentAntle(m_fCurrentAngle);
    
    
}