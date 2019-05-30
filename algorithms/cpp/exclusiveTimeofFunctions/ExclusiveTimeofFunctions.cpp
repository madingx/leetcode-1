// Source : https://leetcode.com/problems/exclusive-time-of-functions/
// Author : Mading
// Date   : 2019-05-29

/********************************************************************************** 
 * 636. Exclusive Time of Functions [Medium]
 * On a single threaded CPU, we execute some functions.  
 * Each function has a unique id between 0 and N-1.

 * We store logs in timestamp order that describe when a function is entered or exited.

 * Each log is a string with this format: "{function_id}:{"start" | "end"}:{timestamp}".
 * For example, "0:start:3" means the function with id 0 started at the beginning of timestamp 3.
 * "1:end:2" means the function with id 1 ended at the end of timestamp 2.

 * A function's exclusive time is the number of units of time spent in this function.  
 * Note that this does not include any recursive calls to child functions.

 * Return the exclusive time of each function, sorted by their function id.
 * Example 1:
                  |fun1 start   ********************************  fun1 end|
    |fun0 start **---------------------------------------------------------**** fun0 end|
    0             1             2             3             4             5             6
 * Input:
 * n = 2
 * logs = ["0:start:0","1:start:2","1:end:5","0:end:6"]
 * Output: [3, 4]
 * Explanation:
 * Function 0 starts at the beginning of time 0, then it executes 2 units of time and reaches the end of time 1.
 * Now function 1 starts at the beginning of time 2, executes 4 units of time and ends at time 5.
 * Function 0 is running again at the beginning of time 6, and also ends at the end of time 6, thus executing for 1 unit of time. 
 * So function 0 spends 2 + 1 = 3 units of total time executing, and function 1 spends 4 units of total time executing.
 

 * Note:
 * 1 <= n <= 100
 * Two functions won't start or end at the same time.
 * Functions will always log when they exit.
 * 
 **********************************************************************************/


// 32 ms, faster than 74.50% of C++， 11.4 MB, less than 81.04% of C++
class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> res(n);
        stack<int> threadstack;
        int begin = 0;
        for(int i = 0; i<logs.size(); i++){
            int a = logs[i].find(':');
            int funid = atoi( string(logs[i],0,a).c_str() );
            int timestamp = 0;
            if(logs[i][a+1] == 's'){
                timestamp = atoi(string(logs[i],a+7,logs[i].size()-a-7).c_str());
                if( !threadstack.empty()){  
                    int preid = threadstack.top();
                    res[preid] += timestamp - begin;
                    begin = timestamp;
                }
                threadstack.push(funid);
            }
            else if(logs[i][a+1] == 'e'){
                timestamp = atoi(string(logs[i],a+5,logs[i].size()-a-5).c_str());
                if( !threadstack.empty()){
                    threadstack.pop();
                    res[funid] += timestamp - begin + 1;
                    begin = timestamp + 1;
                }
            }
            
        }
        return res;
    }
};