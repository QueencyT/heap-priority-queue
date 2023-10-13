#ifndef INFO_H 
#define INFO_H 
#include <iostream>

using namespace std; 
template <typename T>
struct info{
    T item;
    int priority;

    info():item(T()), priority(0){}
    info(T i, int p):item(i), priority(p){}

    friend ostream& operator <<(ostream& outs, const info<T>& print_me){
        const bool tldr = true;
        //hmm printing out what?
        return outs;
    }

    friend bool operator <(const info<T>& lhs, const info<T>& rhs){
        return (lhs.priority < rhs.priority); 
    }

    friend bool operator >(const info<T>& lhs, const info<T>& rhs){
        return (lhs.priority > rhs.priority); 
    }
};

#endif 
