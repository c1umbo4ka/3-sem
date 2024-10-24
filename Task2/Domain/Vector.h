#include <iostream>

template <typename T>
class Vector {
private:
    T* data;                  
    std::size_t size;         
    std::size_t capacity;     

    
    void resize();

public:
    Vector();                
    ~Vector();               

    void push_back(const T& value);   
    void pop_back();                  
    T& back() const;                  
};