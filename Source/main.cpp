
#include <iostream>
#include "FastDelegate/FastDelegate.h"
#include "CppDelegates/Delegate.h"

using namespace std;
using namespace CppDelegates;
using namespace fastdelegate;

class GameObj{
    public:
        void OnEvent(float param){
            cout << "GameObj::OnEvent --> " << param << endl;
        }
};

int main( void )
{
    GameObj obj1, obj2, obj3;
    

    typedef FastDelegate1<float> MyDelegate;
    MyDelegate newdeleg;
    newdeleg = MakeDelegate(&obj1, &GameObj::OnEvent);
    newdeleg(6.3334443);
    
        
    delegate<void (float)> d;
    auto dInstance = decltype(d)::create<GameObj, &GameObj::OnEvent>(&obj2);  
    dInstance(3.1415);
    
    auto d1 = delegate<void(float)>::create<GameObj, &GameObj::OnEvent>(&obj3);
    d1(1.41);
    
	return 0;
}

