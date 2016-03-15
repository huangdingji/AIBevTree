#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "BTInit.h"
#include "BevNode.h"
#include "BevNodeFactory.h"
USING_NS_CC;

class HelloWorld : public cocos2d::Layer
{
public:
    HelloWorld();
    
    virtual bool init() override;
    
    virtual void onEnter() override;
    
    virtual void onExit() override;

    static cocos2d::Scene* scene();
    
    void GameLoop(float dt);
    


    // implement the "static create()" method manually
    CREATE_FUNC(HelloWorld);
    
private:
    BevNode* m_BevTreeRoot;
    BevInputData m_BevTreeInputData;
    BevOutputData m_BevTreeOutputData;
    float m_TimeToFindNewTargetPos;
    
};

#endif // __HELLOWORLD_SCENE_H__
