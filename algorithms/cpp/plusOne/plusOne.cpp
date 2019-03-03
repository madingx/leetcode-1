// Source : https://leetcode.com/problems/plus-one/
// Author : Hao Chen
// Date   : 2014-06-21
//
// Latest Edition
// Editor : Mading
// Date   : 2019-03-03

/********************************************************************************** 
* 66. Plus One
* Given a non-empty array of digits representing a non-negative integer, plus one to the integer.
* The digits are stored such that the most significant digit is at the head of the list, and each
* element in the array contain a single digit.
* You may assume the integer does not contain any leading zero, except the number 0 itself.

* Example 1:
* Input: [1,2,3]
* Output: [1,2,4]
* Explanation: The array represents the integer 123.

* Example 2:
* Input: [4,3,2,1]
* Output: [4,3,2,2]
* Explanation: The array represents the integer 4321.
*               
**********************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

//4 ms  8.5 MB
vector<int> plusOne(vector<int>& digits) {
       for(int i = digits.size()-1;i>=0;i--){
           if(digits[i] == 9){
               digits[i] = 0;
               if(i == 0){
                   digits.insert(digits.begin(),1);
                   break;
               }
           }
           else {
               digits[i] += 1;
               break;
           }
       }
        return digits;
    }

//8 ms  8.7 MB
vector<int> plusOne(vector<int> &digits) {
    int carry=1;
    vector <int> v;
    while(digits.size()>0){
        int x = digits.back();
        digits.pop_back();
        x = x + carry;
        v.insert(v.begin(), x%10);
        carry = x/10;
    }
    if (carry>0){
        v.insert(v.begin(), carry);
    }
    return v;

}

void printVector(vector<int>& v)
{
    cout << "{ ";
    for(int i=0; i<v.size(); i++){
        cout << v[i] << " ";
    }
    cout << "} " << endl;
}


int main()
{
    int a[]={9,9,9};
    vector<int> d(&a[0], &a[0]+sizeof(a)/sizeof(int));
    vector<int> v = plusOne(d);
    printVector(v);
    return 0;
}
