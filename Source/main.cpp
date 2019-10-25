
#include <iostream>
#include <vector>
#include "FastDelegate/FastDelegate.h"
#include "CppDelegates/Delegate.h"

using namespace std;
using namespace CppDelegates;
using namespace fastdelegate;

typedef CppDelegates::delegate<void (float)> EventDelegate;

class GameObj{
    public:
        void OnEvent(float param){
            cout << "GameObj::OnEvent --> " << param << endl;
        }
};

class EventManager{
    public:
        EventManager(){}
        ~EventManager(){}
        
        void AddListener(EventDelegate ed){
            _list.push_back(ed);
        }
        
        void Call(){
            float f = 1.29f;
            for(int i = 0; i < _list.size(); i++){
                _list[i](f);
                f += 0.23342;
            }
        }
        
    private:
        vector<EventDelegate> _list;
};


int main( void )
{
    GameObj obj1, obj2, obj3;
    
/*
    typedef FastDelegate1<float> MyDelegate;
    MyDelegate newdeleg;
    newdeleg = MakeDelegate(&obj1, &GameObj::OnEvent);
    newdeleg(6.3334443);
    
        
    delegate<void (float)> d;
    auto dInstance = decltype(d)::create<GameObj, &GameObj::OnEvent>(&obj2);  
    dInstance(3.1415);
    
    auto d1 = delegate<void(float)>::create<GameObj, &GameObj::OnEvent>(&obj3);
    d1(1.41);
*/
  
    auto d1 = delegate<void(float)>::create<GameObj, &GameObj::OnEvent>(&obj1);
    auto d2 = delegate<void(float)>::create<GameObj, &GameObj::OnEvent>(&obj2);
    auto d3 = delegate<void(float)>::create<GameObj, &GameObj::OnEvent>(&obj3);
    
    EventManager emgr;
    emgr.AddListener(d1);
    emgr.AddListener(d2);
    emgr.AddListener(d3);
    
    emgr.Call();
    
	return 0;
}

