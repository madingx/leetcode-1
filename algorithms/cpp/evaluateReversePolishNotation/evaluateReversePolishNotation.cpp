// Source : https://leetcode.com/problems/evaluate-reverse-polish-notation/
// Author : Hao Chen
// Date   : 2014-06-16

/********************************************************************************** 
* 150. Evaluate Reverse Polish Notation [Medium]
* Evaluate the value of an arithmetic expression in Reverse Polish Notation.
* 
* Valid operators are +, -, *, /. Each operand may be an integer or another expression.
* 
* Some examples:
* 
*   ["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
*   ["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6
* 
*               
**********************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string>
#include <vector>
#include <iostream>
using namespace std;

// 12 ms, faster than 98.18% of C++, 11.6 MB, less than 50.49% of C++
class Solution {
public:
    int evalRPN(vector<string> &tokens) {
        int i =0;
        bool err = false;
        vector<int> exp;
        for (int i=0; i<tokens.size() && !err; i++ ){
            if (isNum(tokens[i])) {
                exp.push_back(value);
            } else if( isOp(tokens[i])==true ) {
                if (exp.size() < 2) {
                    return 0; //ERROR
                }
                int lhs, rhs;
                rhs = exp.back();
                exp.pop_back();
                lhs = exp.back();
                exp.pop_back();

                int evlValue;
                if (tokens[i]=="+"){
                    evlValue = lhs + rhs;    
                }else if (tokens[i]=="-"){
                    evlValue = lhs - rhs;
                }else if (tokens[i]=="*"){
                    evlValue = lhs * rhs;
                }else if (tokens[i]=="/"){
                    evlValue = lhs / rhs;
                }

                exp.push_back(evlValue);

            }else {
                return 0; //ERROR 
            }
        }

        if (exp.size()==1){
            return exp.back();
        }
        return 0;        

    }

private:
    long value;

    bool isOp(string &op) {
        return (op=="+" || op=="-" || op=="*" || op=="/");
    }

    bool isNum(string &num) {
        char *end;
        value = strtol(num.c_str(), &end, 10); 
        if (end == num.c_str() || *end != '\0' || errno == ERANGE){
            return false;
        }
        return true;
    }
};

// 8 ms, faster than 99.90% of C++, 11.7 MB, less than 20.51% of C++ 
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> mystack;
        for( auto op : tokens){
            if( op[op.size()-1] >= '0' && op[op.size()-1] <= '9' ){
                mystack.push(atoi(op.c_str()));
            }
            else{
                int n = mystack.top();
                mystack.pop();
                int m = mystack.top();
                mystack.pop();
                int k = 0;
                if(op == "+") k = m+n;
                else if(op == "*") k = m*n;
                else if(op == "-") k = m-n;
                else if(op == "/") k = m/n;
                mystack.push(k);
            }
        }
        return mystack.top();
    }
};

int main()
{
    Solution s;
    char exps[5][3] = {"42", "9", "6", "-", "+"};
    vector<string> expression;

    cout << "Expression: \n    ";
    for (int i=0; i<5; i++){
        expression.push_back(exps[i]);
        cout << exps[i] << " ";
    }
    cout << endl;
    cout << s.evalRPN(expression)<<endl;;

    char exps2[5][3] =  {"2", "1", "+", "3", "*"};
    expression.clear();

    cout << "Expression: \n    ";
    for (int i=0; i<5; i++){
        expression.push_back(exps2[i]);
        cout << exps2[i] << " ";
    }
    cout << endl;
    cout << s.evalRPN(expression)<<endl;



    return 0;
}
