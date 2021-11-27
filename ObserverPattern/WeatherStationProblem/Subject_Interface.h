#ifndef _Subject_H_
#define _Subject_H_

class Observer; //Forward declaration until we define the observer interface

class Subject {
public:
    virtual ~Subject() = default;
    virtual void register_observer(Observer *o) = 0;
    virtual void remove_observer(Observer *o) = 0;
    virtual void notify() = 0;
};

#endif