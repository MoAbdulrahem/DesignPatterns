#ifndef __SINGLETON_H_
#define __SINGLETON_H_

// Eager-Creation: The object is created at the start of run-time, regardless of whether its functionality is required or not.
// this implementation is thread safe

class Singleton {
  public:
    static Singleton* get_instance();
  
  private:
   Singleton() = default;
   static Singleton* unique_instance;
};

Singleton* Singleton::get_instance() {
  return unique_instance;
}

// This line would be executed when the compiler includes this file, so it's guranteed to be executed before any threads access the singleton instance.
Singleton* Singleton::unique_instance = new Singleton();

#endif //__SINGLETON_H_