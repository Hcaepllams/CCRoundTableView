//
//  RoundTableKnight.cpp
//  CrossKaiser
//
//  Created by 陶 然景 on 13-4-3.
//
//

#include "RoundTableKnight.h"

RoundTableKnight::RoundTableKnight()
:m_fCurrentAngle(0.0f)
{
    
}

RoundTableKnight::~RoundTableKnight()
{
    
}

bool RoundTableKnight::init()
{
    if (!CCLayer::init())
    {
        return false;
    }
    
    CCSprite *card = CCSprite::create("Icon@2x.png");
    this->setContentSize(CCSizeMake(card->getContentSize().width, card->getContentSize().height));
    card->setPosition(ccp(this->getContentSize().width / 2, this->getContentSize().height / 2));
    this->addChild(card);
    
    return true;
}