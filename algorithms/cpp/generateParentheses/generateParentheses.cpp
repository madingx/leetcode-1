// Source : https://oj.leetcode.com/problems/generate-parentheses/
// Author : Hao Chen,Mading
// Date   : 2017-11-15
// 
// Latest Edition
// Editor : Mading
// Date   : 2017-11-15

/********************************************************************************** 
* 22. Generate Parentheses
* 
* Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
* 
* For example, given n = 3, a solution set is:
* 
* "((()))", "(()())", "(())()", "()(())", "()()()"
* 
*               
**********************************************************************************/

#include <stdlib.h>
#include <iostream>
#include <vector>
using namespace std;


void generator(vector<string>& result, int left, int right, string s);
vector<string> generateParenthesis(int n) {
    
    vector<string> result;
    string s;
    generator(result, n, n, s);
    return result;
}

void generator(vector<string>& result, int left, int right, string s){
    if (left==0 && right==0){
        result.push_back(s);
        return;
    }
    if (left>0){
        generator(result, left-1, right, s+'(');
    }
    if (right>0 && right>left){
        generator(result, left, right-1, s+')');
    }
}
    
void printResult(vector<string>& result)
{
    for(int i=0; i<result.size(); i++){
        cout << result[i] <<endl;
    }
}

int main(int argc, char** argv) 
{
    int n=3;
    if (argc>1){
        n = atoi(argv[1]);
    }
    vector<string> r = generateParenthesis(n);
    printResult(r);
    return 0;
}



/*** Solution by Mading *******************/
class Solution {
public:
    void rec(vector<char> &p,vector<string> &res,string str){
        static vector<char> tmp;
        if(tmp.empty() && p.empty()){
            res.push_back(str);
            return;
        }
        if(!p.empty()){
            char a = p.back();
            p.pop_back();
            tmp.push_back(a);
            rec(p,res,str+"(");
            p.push_back(a);
            tmp.pop_back();
            
        }
        if(!tmp.empty()){
            char a = tmp.back();
            tmp.pop_back();
            rec(p,res,str+")");
            tmp.push_back(a);
        }
        return;
        
    }
    
    
    vector<string> generateParenthesis(int n) {
        vector<char> p(n,'(');
        vector<string> res;
        rec(p,res,"");
        return res;
        
        
    }
};