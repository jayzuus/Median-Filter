#ifndef median_hpp
#define median_hpp

#include <string>
#include <vector>
#include <cmath>
#include <queue>
#include <stdio.h>

using namespace std;

struct calculateMedian {
private:
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
public:
    /**
     Default constructor;
     **/
    calculateMedian();
    
    /**
     Add number to queue
     @param number - number which will be added to Min/Max Queue
     **/
    void addNumber(int number);
    
    /**
     Rebalance max and min heap
     **/
    void reBalanceQueue();
    
    /**
     Get median from Min and Max Heap
     **/
    int getMedian(); 
};

#endif /* median_hpp */
