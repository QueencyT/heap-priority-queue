#include "gtest/gtest.h"
#include <iostream>
#include <iomanip>
using namespace std;

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
  Heap<int> mHeap; 

  srand(time(0));
  for(int i = 0; i < 500; i++){
    int insert = rand() % 150; 
    mHeap.insert(insert); 
    if(!mHeap.verify()){
      cout<<"invalid tree: "<<endl; 
      break; 
    }
  }

  while(!mHeap.is_empty()){
    int popped = mHeap.remove(); 

    if(popped < mHeap.top()){
      cout<<"FAIL: expected popped to be greater than or equal to top "<<endl; 
      cout<<"popped: "<<popped<<endl; 
      cout<<"top: "<<mHeap.top()<<endl; 
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

