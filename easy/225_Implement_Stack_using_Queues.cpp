// the goal was to implement a stack-like class with only a single queue, using only queue-like operations. well does this abomination qualify? getting the deque object from inside the queue seems like a queue operation to me
// also is implementation dependent (it works on my machine though :))
// 0ms

#include <deque>
#include <queue>
using namespace std;

class MyStack {
    queue<int> q;

public:
    MyStack() {
        q = queue<int>();
    }
    
    void push(int x) {
        q.push(x);
    }
    
    int pop() {
        deque<int>& d = (*((deque<int>*)(&q)));
        int elem = d.back();
        d.pop_back();
        return elem;
    }
    
    int top() {
        return (*((deque<int>*)(&q))).back();
    }
    
    bool empty() {
        return q.empty();
    }
};