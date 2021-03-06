#ifndef __APPMACROS_H__
#define __APPMACROS_H__

#include "cocos2d.h"
#include "AnyData.h"

/* For demonstrating using one design resolution to match different resources,
   or one resource to match different design resolutions.

   [Situation 1] Using one design resolution to match different resources.
     Please look into Appdelegate::applicationDidFinishLaunching.
     We check current device frame size to decide which resource need to be selected.
     So if you want to test this situation which said in title '[Situation 1]',
     you should change ios simulator to different device(e.g. iphone, iphone-retina3.5, iphone-retina4.0, ipad, ipad-retina),
     or change the window size in "proj.XXX/main.cpp" by "CCEGLView::setFrameSize" if you are using win32 or linux plaform
     and modify "proj.mac/AppController.mm" by changing the window rectangle.

   [Situation 2] Using one resource to match different design resolutions.
     The coordinates in your codes is based on your current design resolution rather than resource size.
     Therefore, your design resolution could be very large and your resource size could be small.
     To test this, just define the marco 'TARGET_DESIGN_RESOLUTION_SIZE' to 'DESIGN_RESOLUTION_2048X1536'
     and open iphone simulator or create a window of 480x320 size.

   [Note] Normally, developer just need to define one design resolution(e.g. 960x640) with one or more resources.
 */

#define DESIGN_RESOLUTION_480X320    0
#define DESIGN_RESOLUTION_1024X768   1
#define DESIGN_RESOLUTION_2048X1536  2




/* If you want to switch design resolution, change next line */
#define TARGET_DESIGN_RESOLUTION_SIZE  DESIGN_RESOLUTION_480X320

typedef struct tagResource
{
    cocos2d::Size size;
    char directory[100];
}Resource;

static Resource smallResource  =  { cocos2d::Size(480, 320),   "iphone" };
static Resource mediumResource =  { cocos2d::Size(1024, 768),  "ipad"   };
static Resource largeResource  =  { cocos2d::Size(2048, 1536), "ipadhd" };

#if (TARGET_DESIGN_RESOLUTION_SIZE == DESIGN_RESOLUTION_480X320)
static cocos2d::Size designResolutionSize = cocos2d::Size(480, 320);
#elif (TARGET_DESIGN_RESOLUTION_SIZE == DESIGN_RESOLUTION_1024X768)
static cocos2d::Size designResolutionSize = cocos2d::Size(1024, 768);
#elif (TARGET_DESIGN_RESOLUTION_SIZE == DESIGN_RESOLUTION_2048X1536)
static cocos2d::Size designResolutionSize = cocos2d::Size(2048, 1536);
#else
#error unknown target design resolution!
#endif

// The font size 24 is designed for small resolution, so we should change it to fit for current design resolution
#define TITLE_FONT_SIZE  (cocos2d::Director::getInstance()->getOpenGLView()->getDesignResolutionSize().width / smallResource.size.width * 24)

#define k_BLimited_MaxChildNodeCnt        16
#define k_BLimited_InvalidChildNodeIndex  k_BLimited_MaxChildNodeCnt

enum E_ParallelFinishCondition
{
    k_PFC_OR = 1,
    k_PFC_AND
};

enum BevRunningStatus
{
    k_BRS_Executing					= 0,
    k_BRS_Finish					= 1,
    k_BRS_ERROR_Transition			= -1,
};

enum E_TerminalNodeStaus
{
    k_TNS_Ready         = 1,
    k_TNS_Running       = 2,
    k_TNS_Finish        = 3,
};

typedef AnyData BevNodeInputParam;
typedef AnyData BevNodeOutputParam;

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef const char*  StringPtr;

typedef float f32;
typedef double f64;

/************************************************************************/
/* static		-- s
 const		-- k
 unsigned     -- u
 pointer      -- po
 integer      -- i
 float        -- f
 boolean      -- b
 char         -- c
 string		-- str
 array        -- ar
 list         -- li
 hashmap      -- hm
 parameter    -- p_
 member       -- m_
 local		-- l_
 global		-- g_
 macro		-- D_
 enum         -- E_
 union		-- un
 
 */


#endif /* __APPMACROS_H__ */
