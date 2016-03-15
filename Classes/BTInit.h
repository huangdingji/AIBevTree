//
//  BTInit.h
//  cocos2d_tests
//
//  Created by huangdingji on 16/3/14.
//
//

#ifndef BTInit_h
#define BTInit_h

#include "cocos2d.h"
#include "AppMacros.h"

USING_NS_CC;

struct BevInputData {
    f32 m_TimeStep;
    Sprite* m_Ower;
    Vec2 m_TargetPosition;
    Vec2 m_CurrentFacing;
};

struct BevOutputData {
    Color3B m_BodyColor;
    Size m_BodySize;
    Vec2 m_NextPosition;
    Vec2 m_NextFacing;
};


#endif /* BTInit_h */
