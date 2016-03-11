//
//  AnyData.h
//  cocos2d_tests
//
//  Created by huangdingji on 16/3/9.
//
//

#ifndef AnyData_h
#define AnyData_h

class AnyData {
public:
    template<typename RealDataType>
    AnyData& GetRealDataType() {
        return *reinterpret_cast<RealDataType*>(m_RealData);
    }
    template<typename RealDataType>
    const RealDataType& GetRealDataType() const{
        return *reinterpret_cast<const RealDataType*>(m_RealData);
    }
    template<typename RealDataType>
    AnyData& operator =(RealDataType* _Data)
    {
        Set<RealDataType>(_Data);
        return *this;
    }
private:
    template<typename RealDataType>
    void Set(RealDataType* _Data)
    {
        m_RealData = reinterpret_cast<void*>(_Data);
    }
private:
    void* m_RealData;
};



#endif /* AnyData_h */
