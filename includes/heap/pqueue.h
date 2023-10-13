#ifndef PCQUEUE_H 
#define PGQUEUE_H 

#include "../../includes/heap/heap.h"
#include "../../includes/heap/info.h"

using namespace std;  
template <typename T>
class PQueue
{
public:
    PQueue(){}
    bool push(const T& value, int p); 
    T pop(); 
    info<T> Pop_debug();

    bool is_empty() const {
        return _heap.is_empty();
    }

    int size() const {
        return _heap.size();
    }

    void print_tree() const; 
    friend ostream& operator <<(ostream& outs, const PQueue<T>& print_me){
        outs<<print_me._heap;
        return outs;
    }

    bool verify() const{
        _heap.verify(); 
    }

private:
    Heap<info<T>> _heap;

};

template <typename T>
bool PQueue<T>::push(const T& value, int p){ //what is the boolean for? what is int p for --> priority?
    info<T> insertedInfo(value, p); 
   _heap.insert(insertedInfo); 
   return true; 
} 
template<typename T> 
T PQueue<T>::pop(){
    info<T> mInfo = _heap.remove(); //going to return info<T> 
    return mInfo.item; 
}

template<typename T>
info<T> PQueue<T>::Pop_debug(){
    //?
}

template<typename T>
void PQueue<T>::print_tree() const{
    _heap.print_tree(cout); 
}

#endif
