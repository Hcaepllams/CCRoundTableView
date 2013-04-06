//
//  RoundTable.cpp
//  CCRoundTableViewTest
//
//  Created by 陶 然景 on 13-4-3.
//
//

#include "RoundTable.h"

RoundTable::RoundTable()
:m_pRoundTableSprite(NULL)
,m_fCurrentAngle(0.0f)
{
    
}

RoundTable::~RoundTable()
{
    CC_SAFE_RELEASE_NULL(m_pRoundTableSprite);
}

bool RoundTable::init()
{
    if (!CCSprite::init())
    {
        return false;
    }
    
    this->setContentSize(CCSizeMake(200, 200));
    
    this->setRoundTableSprite(CCSprite::create("yuan.png"));
    this->addChild(m_pRoundTableSprite);
    this->setContentSize(m_pRoundTableSprite->getContentSize());
    
    m_pRoundTableSprite->setPosition(ccp(this->getContentSize().width / 2, this->getContentSize().height / 2));
    
    this->scheduleUpdate();

    m_sQuad.tl.vertices.x = m_sQuad.tl.vertices.x + this->getContentSize().width / 4;
    m_sQuad.tr.vertices.x = m_sQuad.tr.vertices.x - this->getContentSize().width / 4;
    

    
    return true;
}

void RoundTable::setTextureRect(const CCRect& rect, bool rotated, const CCSize& untrimmedSize)
{
    m_bRectRotated = rotated;
    
    setContentSize(untrimmedSize);
    setVertexRect(rect);
    setTextureCoords(rect);
    
    CCPoint relativeOffset = m_obUnflippedOffsetPositionFromCenter;
    
    // issue #732
    if (m_bFlipX)
    {
        relativeOffset.x = -relativeOffset.x;
    }
    if (m_bFlipY)
    {
        relativeOffset.y = -relativeOffset.y;
    }
    
    m_obOffsetPosition.x = relativeOffset.x + (m_obContentSize.width - m_obRect.size.width) / 2;
    m_obOffsetPosition.y = relativeOffset.y + (m_obContentSize.height - m_obRect.size.height) / 2;
    
    // rendering using batch node
    if (m_pobBatchNode)
    {
        // update dirty_, don't update recursiveDirty_
        setDirty(true);
    }
    else
    {
        // self rendering
        
        // Atlas: Vertex
        float x1 = 0 + m_obOffsetPosition.x;
        float y1 = 0 + m_obOffsetPosition.y;
        float x2 = x1 + m_obRect.size.width;
        float y2 = y1 + m_obRect.size.height;
        
        // Don't update Z.
        m_sQuad.bl.vertices = vertex3(x1, y1, 0);
        m_sQuad.br.vertices = vertex3(x2, y1, 0);
        m_sQuad.tl.vertices = vertex3(x1 + 20, y2, 50);
        m_sQuad.tr.vertices = vertex3(x2 - 20, y2, 50);
    }
}


void RoundTable::update(float dt)
{
//    m_sQuad.tl.vertices.x = 0;
//    m_sQuad.tr.vertices.x = 0;
    m_fCurrentAngle -= 50;
    m_pRoundTableSprite->setRotation(m_fCurrentAngle * M_PI / 180);
}