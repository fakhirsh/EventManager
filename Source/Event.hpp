
#pragma once

#include <string>
#include <map>

using namespace std;

namespace FEngine{

    /*
     * The Event object. Right now event type is a string. A dictionary of
     *   arguments with key as string and values as ONLY doubles.
     */

    class Event{
        public:
            Event();
            ~Event();
            
            void SetArg(string key, double value); 
            double GetArg(string key);

            void SetEventType(const string & type);
            string GetEventType();

            void SetEventId(unsigned int id);
            unsigned int GetEventId();

        private: 
            string _eventType;
            unsigned int _eventId;
            map<string, double> _args;
    };

};
