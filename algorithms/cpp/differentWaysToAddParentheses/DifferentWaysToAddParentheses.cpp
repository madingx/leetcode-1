// Source : https://leetcode.com/problems/different-ways-to-add-parentheses/
// Author : Hao Chen
// Date   : 2015-08-15

/********************************************************************************** 
 * 241. Different Ways to Add Parentheses [Medium]
 * Given a string of numbers and operators, return all possible results from computing 
 * all the different possible ways to group numbers and operators. The valid operators 
 * are +, - and *.
 * 
 * Example 1
 * Input: "2-1-1". 
 *      ((2-1)-1) = 0
 *      (2-(1-1)) = 2
 * Output: [0, 2]
 * 
 * Example 2
 * Input: "2*3-4*5" 
 *      (2*(3-(4*5))) = -34
 *      ((2*3)-(4*5)) = -14
 *      ((2*(3-4))*5) = -10
 *      (2*((3-4)*5)) = -10
 *      (((2*3)-4)*5) = 10
 * Output: [-34, -14, -10, -10, 10] 
 * 
 * Credits:Special thanks to @mithmatt for adding this problem and creating all test 
 * cases.
 *               
 **********************************************************************************/

// 4 ms, faster than 88.76% of C++, 8.9 MB, less than 96.75% of C++
unordered_map<char, function<int(int, int)>> const kOpsMap = {
    {'+', [](int a, int b) { return a + b; }},
    {'-', [](int a, int b) { return a - b; }},
    {'*', [](int a, int b) { return a * b; }}
};

class Solution {
public:
    static vector<int> diffWaysToCompute(string const& input) {
        int const input_sz = input.size();
        vector<int> nums;
        vector<char> ops;
        // tokenize the input
        for (int offset = 0; offset < input_sz; ) {
            nums.push_back(parseNum(offset, input));
            if (offset < input_sz)
                ops.push_back(input[offset++]);
        }
        int const sz = nums.size();
        // mem[b][e - b] -- possible results (with multiplicity) from
        // evaluating sub-expression starting at nums[b] and ending
        // at nums[e] (inclusive)
        vector<vector<vector<int>>> mem(sz);
        for (int b = 0; b < sz; ++b) {
            mem[b] = vector<vector<int>>(sz - b);
            mem[b][0].push_back(nums[b]);
        }
        computePossibleResults(mem, nums, ops, 0, sz - 1);
        auto const& res = mem[0][sz - 1];
        return vector<int>(res.cbegin(), res.cend());
    }
private:
    static int parseNum(int& offset, string const& input) {
        int res = 0;
        while (offset < input.size()) {
            auto const c = input[offset];
            if (c < '0' || c > '9') break;
            res *= 10;
            res += (c - '0');
            ++offset;
        }
        return res;
    }
    static void computePossibleResults(vector<vector<vector<int>>>& mem, vector<int> const& nums, vector<char> const& ops, int b, int e) {
        auto& res = mem[b][e - b];
        if (!res.empty()) return;
        for (int s = b; s < e; ++s) {  // s + 1 <= e
            auto const& op = kOpsMap.at(ops[s]);
            computePossibleResults(mem, nums, ops, b, s);
            computePossibleResults(mem, nums, ops, s + 1, e);
            for (auto const l : mem[b][s - b])
                for (auto const r : mem[s + 1][e - s - 1])
                    res.push_back(op(l, r));
        }     
    }
};




// 0 ms, faster than 100.00% of C++, 9.5 MB, less than 90.65% of C++
class Solution {
public:
    bool isOperator(char ch){
        return (ch=='+' || ch=='-' || ch=='*');
    }

    //Divide & Conque  - recursive way
    vector<int> diffWaysToCompute(string input) {
        //if the result has been cacluated, then just get it from the cache and return 
        static map< string, vector<int> > cache;
        if ( cache.find(input) != cache.end() ){
            return cache[input];
        }

        vector<int> result; 
        for (int i=0; i<input.size(); i++){
            char ch = input[i];
            if (isOperator(ch)){
                //split the input to two parts, left part and right part 
                //And recursively invoke this function.
                string left  = input.substr(0, i);
                string right = input.substr(i+1);
                vector<int> lv = diffWaysToCompute(left);
                vector<int> rv = diffWaysToCompute(right);

                //merge two result to one
                for(int li=0; li<lv.size(); li++) {
                    for(int ri=0; ri<rv.size(); ri++) {
                        switch(ch){
                            case '+' : result.push_back(lv[li] + rv[ri]); break;
                            case '-' : result.push_back(lv[li] - rv[ri]); break;
                            case '*' : result.push_back(lv[li] * rv[ri]); break;
                        }
                    }
                }

            }
        }
        //if we cannot find the "operator" in input, 
        //which means, it is a number, just put the number into the result. 
        if (result.size()==0) {
            result.push_back(atoi(input.c_str()));
        }

        //cache the result, key = input, value = result;
        cache[input] = result;

        return result;
    }

};