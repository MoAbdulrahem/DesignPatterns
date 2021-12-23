#ifndef _SINGLETON_H_
#define _SINGLETON_H_

// Lazy Creation - The object is created once it is needed
// This implementation is not thread-safe

class Singleton {
  public:
    static Singleton* get_instance();
  private:
    Singleton() = default; 
    static Singleton *unique_instance;

};

/*
This implementation relies on making the constructor private, so that no objects can be instantiated from outside the class.
As well as a static variable and a static method:
The static variable is decalred as private and would hold a reference to the one and only object of the singleton.
The static method is declared as public and would be used as a global point of access to the sigleton instance.
*/

inline Singleton* Singleton::get_instance(){
  if (unique_instance == nullptr){
    unique_instance = new Singleton();
  }
  return unique_instance;
}

#endif // _SINGLETON_H_