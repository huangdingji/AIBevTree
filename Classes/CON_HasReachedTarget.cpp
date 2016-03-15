//
//  CON_HasReachedTarget.cpp
//  cocos2d_tests
//
//  Created by huangdingji on 16/3/14.
//
//

#include "CON_HasReachedTarget.h"


bool CON_HasReachedTarget::ExternalCondition(const BevNodeInputParam& input) {
    const BevInputData& inputData = input.GetRealDataType<BevInputData>();
    Vec2 targetPoint = inputData.m_TargetPosition;
    Vec2 curPosition = inputData.m_Ower->getPosition();
    Vec2 dir = targetPoint-curPosition;
    if (dir.lengthSquared() < 0.5f) {
        return true;
    }
    return false;
}