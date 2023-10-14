#ifndef HEAP_H 
#define HEAP_H 
#include <iostream>
#include <iomanip>

using namespace std; 
template <typename T>
class Heap
{
public:
    Heap():_how_many(0){
        
    }

    void insert(const T& insert_me){
        int index = _how_many; 
        _heap[index] = insert_me; //should be one after the last item inserted //inserting 
        T parent = _heap[parent_index(index)];  
       

        while(index != 0 && parent < insert_me){ //as long as we're not root and parent is less than us
            swap_with_parent(index); //swapping child with parent //so now we're parent 
            index = parent_index(index); //index updated to parent index //our index
            parent = _heap[parent_index(index)]; 
        }
        _how_many++; 
    }   //insert into the heap 

    T remove(){
        T popped = _heap[0]; //cause we want to remove largest
        _heap[0] = _heap[_how_many - 1]; //should be last element    //now time to sink 
        int index = 0; 
        T leftChild = _heap[left_child_index(index)], rightChild = _heap[right_child_index(index)], curr = _heap[index];  
        _how_many--;
        while((leftChild > curr || rightChild > curr) && !is_leaf(index)){ //at least one child -> so not leaf   
            index = big_child_index(index); 
            swap_with_parent(index); 
            leftChild = _heap[left_child_index(index)]; 
            rightChild = _heap[right_child_index(index)]; //no need to update curr
        } 

        return popped; //the first ele in the array should be the largest
    }                        //remove and return top value  //so far working 

    T top(){
        return _heap[0]; 
    }//return the value at the top of heap

    bool is_empty() const{
        return (_how_many == 0); 
    }

    int size() const{
        return _how_many; 
    }

    int capacity() const{
        return capacity; 
    }

    friend ostream& operator << (ostream& outs, const Heap<T>& print_me){
        print_me.print_tree(outs);
        return outs;
    }

    bool verify() const{
       return verify(0); 
    }                //true if tree is verified to be a heap

    T *heap_array(){
        T* copyArray = new T; 
        T* copyWalker = copyArray; 
        for(int i = 0; i < _how_many; i++, copyWalker++){
            *copyWalker = _heap[i]; 
        }
        return copyArray; 
    }        
       
    //returns a copy of underlying array: 
    //  don't forget to delete when done

private:
    static const int CAPACITY = 1000;
    T _heap[CAPACITY]; //static array
    int _how_many; //num used

    void print_tree(ostream& outs = cout) const{
        print_tree(0, 0, outs); 
    }

    void print_tree(int root, int level = 0, ostream& outs = cout) const{
        //right most node first -->
        if(root < _how_many){ //don't want level++ , or ++level 
            print_tree(right_child_index(root), level + 1, outs); 
            outs<<setw(level * 4)<<_heap[root]<<endl; 
            print_tree(left_child_index(root), level + 1, outs);//bc will affect this
        }
    }

    bool verify(int root) const{
        bool valid = true; //if empty tree do we want to return true? 
        //if at leaf, exit
        if(!is_leaf(root)){ //root < _how_many && left_child_index(root) < _how_many && right_child_index(root) < _how_many
            if((right_child_index(root) < _how_many && _heap[root] < _heap[right_child_index(root)]) || (left_child_index(root) < _how_many && _heap[root] < _heap[left_child_index(root)])){//make sure not out of bounds
                valid = false; 
                return valid; 
            }
            else{
                valid = true; 
            }
            valid = verify(right_child_index(root)); 
            valid = (valid && verify(left_child_index(root))); //work
        }
        return (valid); 
        //recursive func to verify that parent is always bigger than child 
    }

    bool is_root(int i) const {
        return i==0;
    }

    bool is_leaf(int index) const{
        if(index >= _how_many || (right_child_index(index) >= _how_many && left_child_index(index) >= _how_many)){
            return true; 
        }
        return false; //
    }

    int parent_index(int i) const{
        if(is_root(i)){
            return 0; //no parent so we are root
        }
        else{
            return (i-1)/2; 
        }
    }

    int left_child_index(int i)const {
        return 2*i + 1;
    }

    int right_child_index(int i) const {
        return 2*i + 2;
    }
    
    // i is index of the parent in this case? 
    //what if 0
    int big_child_index(int i) const{
        int rightChildIndex = right_child_index(i), leftChildIndex = left_child_index(i); 
        if(_heap[rightChildIndex] > _heap[leftChildIndex]){
            return rightChildIndex; 
        }
        return leftChildIndex; 
    }

    //int i --> index of the child?
    void swap_with_parent(int i){
        T child = _heap[i]; //child
        _heap[i] = _heap[parent_index(i)];  //child == parent 
        _heap[parent_index(i)] = child; //parent == child
    }
};

#endif
