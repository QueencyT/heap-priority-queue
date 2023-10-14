#include "gtest/gtest.h"
#include <iostream>
#include <iomanip>
using namespace std;

#include "../../includes/heap/pqueue.h"
#include "../../includes/heap/heap.h"


bool test_print(bool debug){
  if(debug){
    Heap<int> mHeap; 
    int a[] = {20,31,17,-3,4,29,17, 3, 4,-9,45}; 

    for(int i = 0; i < 11; i++){
      mHeap.insert(a[i]); 
    }
    cout<<mHeap<<endl; 
  }
  return true; 
}

bool test_remove(bool debug){
  if(debug){
    Heap<int> mHeap; 
    int a[] = {15,10,14}; 

    for(int i = 0; i < 3; i++){
      mHeap.insert(a[i]); 
    }
    cout<<"before remove: "<<endl; 
    cout<<mHeap<<endl; 

    while(!mHeap.is_empty()){
      mHeap.remove(); 
      cout<<"after remove: "<<endl; 
      cout<<mHeap<<endl; 
      cout<<"--------------------"<<endl; 
    }
  }
}


bool test_verify(bool debug){
  if(debug){
    Heap<int> mHeap; 
    for(int i = 0; i < 10; i++){
      mHeap.insert(i); 
    }

    cout<<"tree: "<<endl; 
    cout<<mHeap<<endl; 
    cout<<"isValid: "<<mHeap.verify()<<endl; 
  }
  return true; 
}

bool test_runner(bool debug){
  PQueue<int> mQueue; 

  int arr[] = {94, 86, 92, 86, 74, 82, 86, 67, 66, 56, 72, 73, 74, 73, 70, 36, 
  40, 42, 39, 41, 28, 65, 72, 33, 66, 48, 54, 47, 65, 31, 54, 27, 17, 39, 39, 15, 38, 21, 24, 32}; 
 
  srand(time(0));
  for(int i = 0; i < 10; i++){
    mQueue.push(arr[i], rand() % 10); //rand() % 10 priority --> 10 being max priority
    if(!mQueue.verify()){
      cout<<"invalid tree: "<<endl; 
      break; 
    }
  }

  cout<<mQueue<<endl; 

  
  int i = 0; 
  while(!mQueue.is_empty()){
    info<int> popped = mQueue.Pop_debug(); 
    cout<<"popped: "<<popped<<endl; 
    cout<<"top: "<<mQueue.top()<<endl;
    cout<<mQueue<<endl; 
    cout<<"--------------------------------\n";
    i++; 
    if(popped < mQueue.top()){
      cout<<"FAIL: expected popped to be greater than or equal to top "<<endl; 
      cout<<"popped: "<<popped<<endl; 
      cout<<"top: "<<mQueue.top()<<endl; 
      break; 
    }
  }
  return true;
}


bool test_stub(bool debug = false)
{
  if (debug){
    cout << "testB:: test-sub() entering test_sub" << endl;
  }
  return true;
}

TEST(TEST_STUB, TestStub) {
  
  //EXPECT_EQ(0, <your individual test functions are called here>);

  EXPECT_EQ(1, test_stub(false));
}

TEST(TEST_HEAP, testRunner){
  EXPECT_EQ(1, test_runner(true)); 
}

TEST(TEST_HEAP, testPrint){
  EXPECT_EQ(1, test_print(false));
}

TEST(TEST_HEAP, testRemove){
  EXPECT_EQ(1, test_remove(false));
}

TEST(TEST_HEAP, testVerify){
  EXPECT_EQ(1, test_verify(false)); 
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  std::cout<<"\n\n----------running testB.cpp---------\n\n"<<std::endl;
  return RUN_ALL_TESTS();
}

