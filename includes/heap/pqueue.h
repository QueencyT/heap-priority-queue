#ifndef PQUEUE_H 
#define PQUEUE_H 

#include "../../includes/heap/heap.h"
#include "../../includes/heap/info.h"

using namespace std;  
template <typename T>
class PQueue
{
public:
    PQueue(){}

    bool push(const T& value, int p){ //what is the boolean for? what is int p for --> priority?
        info<T> insertedInfo(value, p, timeEntered++); 
        _heap.insert(insertedInfo); 
        return true; 
   } 

    T pop(){
        info<T> mInfo = _heap.remove(); //going to return info<T> 
        return mInfo.item; 
    } 

    info<T> Pop_debug(){
        return _heap.remove(); 
    }

    bool is_empty() const {
        return _heap.is_empty();
    }

    int size() const {
        return _heap.size();
    }

    void print_tree() const{
        _heap.print_tree(cout); 
    }

    friend ostream& operator <<(ostream& outs, const PQueue<T>& print_me){
        outs<<print_me._heap;
        return outs;
    }

    bool verify() const{
       return _heap.verify(); 
    }

private:
    Heap<info<T>> _heap;
    int timeEntered = 0; //new field?
};
#endif
