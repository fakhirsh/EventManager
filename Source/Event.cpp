
#include "Event.hpp"

namespace FEngine{

    Event::Event(){
        _eventType = "invalid";
        _eventId = -1;
    }
    
    Event::~Event(){
    
    }
    
    void Event::SetArg(string key, double value){
        _args[key] = value;
    }
    
    double Event::GetArg(string key){
        return _args[key];
    }

    void Event::SetEventType(const string & type){
        _eventType = type;
    }
    
    string Event::GetEventType(){
        return _eventType;
    }

    void Event::SetEventId(unsigned int id){
        _eventId = id;
    }
    
    unsigned int Event::GetEventId(){
        return _eventId;
    }

};
