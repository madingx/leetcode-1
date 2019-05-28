// Source : https://leetcode.com/problems/maximum-frequency-stack/
// Author : Mading
// Date   : 2019-05-28

/********************************************************************************** 
 * 895. Maximum Frequency Stack [Hard]
 * Implement FreqStack, a class which simulates the operation of a stack-like data structure.

 * FreqStack has two functions:

 * push(int x), which pushes an integer x onto the stack.
 * pop(), which removes and returns the most frequent element in the stack.
 * If there is a tie for most frequent element, the element closest to the top of the stack is removed and returned.
 

 * Example 1:

 * Input: 
 * ["FreqStack","push","push","push","push","push","push","pop","pop","pop","pop"],
 * [[],[5],[7],[5],[7],[4],[5],[],[],[],[]]
 * Output: [null,null,null,null,null,null,null,5,7,5,4]
 * Explanation:
 * After making six .push operations, the stack is [5,7,5,7,4,5] from bottom to top.  Then:

 * pop() -> returns 5, as 5 is the most frequent.
 * The stack becomes [5,7,5,7,4].

 * pop() -> returns 7, as 5 and 7 is the most frequent, but 7 is closest to the top.
 * The stack becomes [5,7,5,4].

 * pop() -> returns 5.
 * The stack becomes [5,7,4].

 * pop() -> returns 4.
 * The stack becomes [5,7].
 

 * Note:

 * Calls to FreqStack.push(int x) will be such that 0 <= x <= 10^9.
 * It is guaranteed that FreqStack.pop() won't be called if the stack has zero elements.
 * The total number of FreqStack.push calls will not exceed 10000 in a single test case.
 * The total number of FreqStack.pop calls will not exceed 10000 in a single test case.
 * The total number of FreqStack.push and FreqStack.pop calls will not exceed 150000 across all test cases.
 *               
 **********************************************************************************/


// 236 ms, faster than 95.94% of C++, 75 MB, less than 47.55% of C++
class FreqStack {
    unordered_map<int, int> freq;
    unordered_map<int, stack<int>> m;
    int maxfreq = 0;
public:
    FreqStack() {
    }

    void push(int x) {
        maxfreq = max(maxfreq, ++freq[x]);
        m[freq[x]].push(x);
    }

    int pop() {
        int x = m[maxfreq].top();
        m[maxfreq].pop();
        if (!m[freq[x]--].size()) maxfreq--;
        return x;
    }
};



// 688 ms, faster than 5.64% of C++, 116.8 MB, less than 7.17% of C++
class FreqStack {
    unordered_map<int,int> freqmap;
    stack<int> freqstack;
    stack<int> tmpstack;
    stack<int> mystack;
    int maxfreq;
public:
    FreqStack() {
        maxfreq = INT_MAX;
        freqmap[maxfreq] = 0;
    }
    
    void push(int x) {
        freqmap[x]++;
        if(freqmap[x] >= freqmap[maxfreq]){
            maxfreq = x;
        }
        freqstack.push(maxfreq);
        mystack.push(x);        
    }
    
    int pop() {
        int top = freqstack.top();
        while( !mystack.empty() ){
            int x = mystack.top();
            mystack.pop();
            freqstack.pop();
            freqmap[x]--;
            if(x == top)break;
            tmpstack.push(x);            
        }
        maxfreq = freqstack.empty() ? INT_MAX : freqstack.top();
        while( !tmpstack.empty() ){
            int x = tmpstack.top();
            tmpstack.pop();
            push(x);
        }
        return top;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 */