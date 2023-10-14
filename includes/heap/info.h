#ifndef INFO_H 
#define INFO_H 
#include <iostream>

using namespace std; 
template <typename T>
struct info{
    T item;
    int priority;
    int timeStamp; //adding this?

    info():item(T()), priority(0){
        timeStamp = 0; 
    }
    info(T i, int p, int time):item(i), priority(p), timeStamp(time){}

    friend ostream& operator <<(ostream& outs, const info<T>& print_me){
        const bool tldr = true;
        if(tldr){
            outs<<"[p: "<<print_me.priority<<": t:"<<print_me.timeStamp<<"]"<<print_me.item<<endl; 
        }
        else{
            outs<<print_me.item<<endl; 
        }
        return outs;
    }

    //COMPARING ITEM AS WELL
    friend bool operator <(const info<T>& lhs, const info<T>& rhs){
        if(lhs.priority == rhs.priority){
            return (lhs.timeStamp > rhs.timeStamp); //won't be possible for timestamps to be equal so don't need to consider that
            //if enetered later, we consider smaller 
        }
        return (lhs.priority < rhs.priority); 
    }

    friend bool operator >(const info<T>& lhs, const info<T>& rhs){
         if(lhs.priority == rhs.priority){
            return (lhs.timeStamp < rhs.timeStamp); //won't be possible for timestamps to be equal so don't need to consider that
            //if enetered first, we consider greater 
        }
        return (lhs.priority > rhs.priority); //less than priority
    }
};

#endif 
