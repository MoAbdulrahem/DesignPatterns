
#include <string>
#include <iostream>

// The Product Interface
class Product {
public:
    // virtual ~Product();
    virtual std:: string operation() const = 0;
};

// Concrete Products
class ConcreteProduct1 : public Product {
public:
    std::string operation() const override {
        return "Result of ConcreteProduct1\n";
    }
    ~ConcreteProduct1() = default;
};

class ConcreteProduct2 : public Product {
public:
    std::string operation() const override {
        return "Result of ConcreteProduct2\n";
    }
    ~ConcreteProduct2() = default;
};

// The Creator abstract class
class Creator {
public:
    virtual ~Creator(){};
    virtual Product* factoryMethod() const = 0; // The Factory method to be overridden by subclasses that implement this interface
    std::string someOperation() const {
        // the other methods of the superclass that make use of the factory method that would be implemented in the subclasses
        Product* product = this->factoryMethod();
        // now we can perform operations on the product without knowing the type of concrete product we got, just that it implements the product interface, and the details of the operations we are to perform on it
        std::string result = "The same creator just worked with product "+ product->operation();
        delete product;
        return result;
    }
};

// Implementing the concrete creators
class ConcreteCreator1 : public Creator {
    Product* factoryMethod() const override {
        return new ConcreteProduct1();
    }
};

class ConcreteCreator2 : public Creator {
    Product* factoryMethod() const override {
        return new ConcreteProduct2();
    }
};

// client code that makes use of the products
void ClientCode(Creator& creator){
    std::cout << "Client: I'm not aware of the creator class, but I know what I can do with it!\n"
    << creator.someOperation() << std::endl;
}

int main() {
    std::cout << "App launched with ConcreteCreator1\n";
    Creator* creator = new ConcreteCreator1;
    ClientCode(*creator);
    std::cout << std::endl;
    std::cout << "App launched with ConcreteCreator2\n";
    Creator* creator2 = new ConcreteCreator2;
    ClientCode(*creator2);

    delete creator;
    delete creator2;
    return 0;
}