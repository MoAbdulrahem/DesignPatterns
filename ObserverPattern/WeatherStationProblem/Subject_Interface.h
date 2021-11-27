#ifndef _Subject_H_
#define _Subject_H_

class Observer; //Forward declaration until we define the observer interface

class Subject {
public:
    virtual ~Subject() = default;
    virtual register_observer(Observer *o) = 0;
    virtual remove_observer(Observer *o) = 0;
    virtual notify() = 0;
};

#endif