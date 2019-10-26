
#include <iostream>
#include <vector>
#include "FastDelegate/FastDelegate.h"
#include "CppDelegates/Delegate.h"
#include "Event.hpp"
#include "EventManager.hpp"
#include <map>
#include <string>
#include <chrono>
#include <memory>


using namespace std;
using namespace std::chrono;
using namespace CppDelegates;
using namespace fastdelegate;
using namespace FEngine;

//typedef CppDelegates::delegate<void (float)> EventDelegate;

class GameObj{
    public:
        void OnEvent(EventPtr e){
            cout << this << "  GameObj::OnEvent --> " << e->GetArg("health") << endl;
            double d = e->GetArg("health");
        }
};

/*
 *class EventManager{
 *    public:
 *        EventManager(){}
 *        ~EventManager(){}
 *
 *        void AddListener(EventDelegate ed){
 *            _list.push_back(ed);
 *        }
 *
 *        void Call(){
 *            float f = 1.29f;
 *            for(int i = 0; i < _list.size(); i++){
 *                _list[i](f);
 *                f += 0.23342;
 *            }
 *        }
 *
 *    private:
 *        vector<EventDelegate> _list;
 *};
 */

/*
 *void Benchmark1(unsigned int iterations);
 *void Benchmark2(unsigned int iterations);
 *void Benchmark3(unsigned int iterations);
 */

void Benchmark4(unsigned int iterations);

int main( void )
{
    //GameObj obj1, obj2, obj3;

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

/*
 *    auto d1 = delegate<void(float)>::create<GameObj, &GameObj::OnEvent>(&obj1);
 *    auto d2 = delegate<void(float)>::create<GameObj, &GameObj::OnEvent>(&obj2);
 *    auto d3 = delegate<void(float)>::create<GameObj, &GameObj::OnEvent>(&obj3);
 *
 *    EventManager emgr;
 *    emgr.AddListener(d1);
 *    emgr.AddListener(d2);
 *    emgr.AddListener(d3);
 *
 *    emgr.Call();
 *
 *    FEngine::Event e;
 *    e.SetEventId(5545);
 *    e.SetEventType("Hit");
 *    e.SetArg("damage", 20.0);
 *    e.SetArg("speed", 30.0);
 *    e.SetArg("happy", 100.0);
 *
 *
 *    map<string, double> args;
 *    args["damage"] = 20.0;
 *
 *    cout << e.GetArg("speed") << endl;
 */

    unsigned int iterations = 20;
    //Benchmark1(iterations);
    //Benchmark2(iterations);
    //Benchmark3(iterations);
    Benchmark4(iterations);
	
    return 0;
}

/*
 *
 *void Benchmark1(unsigned int iterations){
 *
 *    cout << "Benchmark 1" << endl;
 *    cout << "Creating " << iterations << " events" << endl;
 *
 *    long int time = 0;
 *    long int newtime = 0;
 *
 *    const long int num = high_resolution_clock::period::num;
 *    const long int den = high_resolution_clock::period::den;
 *    time = high_resolution_clock::now().time_since_epoch().count();
 *
 *    unsigned int count = 0;
 *    do{
 *        FEngine::Event e;
 *        e.SetEventName("Game Started");
 *        e.SetEventType("Hit");
 *        e.SetArg("damage", 20.0);
 *        e.SetArg("speed", 30.0);
 *        e.SetArg("happy", 100.0);
 *
 *        double temp = e.GetArg("damage");
 *        temp = e.GetArg("speed");
 *        temp = e.GetArg("happy");
 *        // HUGE panelty time wise:
 *        temp = e.GetArg("unknown");
 *
 *        count++;
 *    }while(count < iterations);
 *
 *    newtime = high_resolution_clock::now().time_since_epoch().count();
 *    double dt = (newtime - time) * 1.0 * num / den;
 *
 *    cout << "Elapsed time:  " << dt*1000 << " (msec)" << endl;
 *}
 *
 *void Benchmark2(unsigned int iterations){
 *    cout << "Benchmark 2" << endl;
 *    cout << "Creating " << iterations << " events" << endl;
 *
 *    long int time = 0;
 *    long int newtime = 0;
 *
 *    const long int num = high_resolution_clock::period::num;
 *    const long int den = high_resolution_clock::period::den;
 *    time = high_resolution_clock::now().time_since_epoch().count();
 *
 *
 *    unsigned int count = 0;
 *    do{
 *        map<string, double> args;
 *
 *        args["damage"] = 20.0;
 *        args["speed"] = 30.0;
 *        args["happy"] = 100.0;
 *
 *        double temp = args["damage"];
 *        temp = args["speed"];
 *        temp = args["happy"];
 *        // HUGE panelty time wise:
 *        temp = args["unknown"];
 *
 *        count++;
 *    }while(count < iterations);
 *
 *    newtime = high_resolution_clock::now().time_since_epoch().count();
 *    double dt = (newtime - time) * 1.0 * num / den;
 *
 *    cout << "Elapsed time:  " << dt*1000 << " (msec)" << endl;
 *
 *}
 *
 *void Benchmark3(unsigned int iterations){
 *    cout << "Benchmark 3" << endl;
 *    cout << "Creating " << iterations << " events" << endl;
 *
 *    EventManager mgr;
 *    GameObj obj1, obj2, obj3;
 *    auto d1 = EventDelegate::create<GameObj, &GameObj::OnEvent>(&obj1);
 *    auto d2 = EventDelegate::create<GameObj, &GameObj::OnEvent>(&obj2);
 *    auto d3 = EventDelegate::create<GameObj, &GameObj::OnEvent>(&obj3);
 *
 *    mgr.AddListener("gamestart", d1);
 *    mgr.AddListener("gamestart", d2);
 *    mgr.AddListener("gamestart", d3);
 *
 *
 *    for(int i = 0; i < iterations; i++){
 *        Event e;
 *        e.SetEventType("gamestart");
 *        e.SetEventName("Random Event");
 *        e.SetArg("health", 100+i);
 *        mgr.EnQueue(e);
 *    }
 *
 *    long int time = 0;
 *    long int newtime = 0;
 *
 *    const long int num = high_resolution_clock::period::num;
 *    const long int den = high_resolution_clock::period::den;
 *    time = high_resolution_clock::now().time_since_epoch().count();
 *
 *
 *    unsigned int count = 0;
 *    do{
 *        
 *        mgr.Update(0.0f);
 *
 *        count++;
 *    }while(count < iterations);
 *
 *    newtime = high_resolution_clock::now().time_since_epoch().count();
 *    double dt = (newtime - time) * 1.0 * num / den;
 *
 *    cout << "Elapsed time:  " << dt*1000 << " (msec)" << endl;
 *
 *}
 *
 */

 
void Benchmark4(unsigned int iterations){
     cout << "Benchmark 3" << endl;
     cout << "Creating " << iterations << " events" << endl;
 
     EventManager mgr;
     GameObj obj1, obj2, obj3;
     auto d1 = EventDelegate::create<GameObj, &GameObj::OnEvent>(&obj1);
     auto d2 = EventDelegate::create<GameObj, &GameObj::OnEvent>(&obj2);
     auto d3 = EventDelegate::create<GameObj, &GameObj::OnEvent>(&obj3);
 
     mgr.AddListener("gamestart", d1);
     mgr.AddListener("gamestart", d2);
     mgr.AddListener("gamestart", d3);
 
 
     for(int i = 0; i < iterations; i++){
         EventPtr e = make_shared<Event>();
         e->SetEventType("gamestart");
         e->SetEventName("Random Event");
         e->SetArg("health", 100+i);
         mgr.EnQueue(e);
     }
 
     long int time = 0;
     long int newtime = 0;
 
     const long int num = high_resolution_clock::period::num;
     const long int den = high_resolution_clock::period::den;
     time = high_resolution_clock::now().time_since_epoch().count();
 
 
     unsigned int count = 0;
     do{
         
         mgr.Update(0.0f);
 
         count++;
     }while(count < iterations);
 
     newtime = high_resolution_clock::now().time_since_epoch().count();
     double dt = (newtime - time) * 1.0 * num / den;
 
     cout << "Elapsed time:  " << dt*1000 << " (msec)" << endl;

}
