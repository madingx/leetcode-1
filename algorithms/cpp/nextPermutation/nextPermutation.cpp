// Source : https://oj.leetcode.com/problems/next-permutation/
// Author : Hao Chen
// Date   : 2014-08-21

/********************************************************************************** 
* 
* Implement next permutation, which rearranges numbers into the lexicographically next 
* greater permutation of numbers.
* 
* If such arrangement is not possible, it must rearrange it as the lowest possible order 
* (ie, sorted in ascending order).
* 
* The replacement must be in-place, do not allocate extra memory.
* 
* Here are some examples. Inputs are in the left-hand column and its corresponding outputs 
* are in the right-hand column.
*
*   1,2,3 → 1,3,2
*   3,2,1 → 1,2,3
*   1,1,5 → 1,5,1
*               
**********************************************************************************/

/*
 * Take a look the following continuous permutation, can you find the patern?
 *
 *    1 2 3 4
 *    1 2 4 3
 *    1 3 2 4
 *    1 3 4 2
 *    1 4 2 3
 *    1 4 3 2
 *    2 1 3 4
 *    ...
 *
 * The pattern can be descripted as below:
 *
 *    1) from n-1 to 0, find the first place [i-1] which nums[i-1] < nums[i]
 *    2) from n-1 to i, find the first number from n-1 to i which >= nums[i-1]
 *    3) swap the 2) nums with the nums[i-1]
 *    4) sort the sub-array [i, n) //actuall sort is fine as well
 * 
 * For example:
 * 
 *     1 4 3 2   <-- 1) find the first place which nums[i-1] < nums[i]
 *     ^
 * 
 *     1 4 3 2   <-- 2) find the first number from n-1 to i which >= nums[i-1]
 *     ^     ^  
 * 
 *     2 4 3 1   <-- 3) swap them
 *     ^     ^
 * 
 *     2 4 3 1   <-- 4) sort
 *       ^   ^
 *
 *     2 1 3 4   
 * 
 * Edge Case:
 *
 *     4 3 2 1, the next permutation is 1 2 3 4
 */

#include <stdio.h>
#include <stdlib.h>

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//Runtime: 12 ms, faster than 100.00% of C++ online submissions for Next Permutation.
void nextPermutation(vector<int> &nums) {

    if(nums.size()<=1) return;

    for(int i = nums.size()-1; i>0; i--) {
        if (nums[i-1] < nums[i]){//increase
            int j = nums.size()-1;
            while( nums[i-1] >= nums[j]) {
                //pass;
                j--;
            }
            //swap
            int tmp = nums[j];
            nums[j] = nums[i-1];
            nums[i-1] = tmp;
            //sort works as well
            //sort(nums.begin()+i, nums.end()); 
            reverse(nums.begin()+i, nums.end()); 
            return; 
        }
        //edge case: 4 3 2 1
        if (i == 1 ){ //all decrease
            //sort works as well
            //sort(nums.begin(), nums.end());
            reverse(nums.begin(), nums.end());
            return;
        }
    }

}


void printVector(vector<int> &nums) {
    for(int i=0; i<nums.size(); i++) {
        cout << nums[i] << " ";
    } 
    cout <<endl;
}
bool isBeginVector(vector<int> &nums) {
    for(int i=0; i<nums.size(); i++) {
        if(nums[i] != i+1) {
            return false;
        }
    } 
    return true;
}

int main(int argc, char** argv)
{
    int n = 4;
    if (argc>1){
        n = atoi(argv[1]);
    }
    vector<int> nums;
    for(int i=1; i<=n; i++){
        nums.push_back(i);
    }
    
    while(true){
        printVector(nums);
        nextPermutation(nums);
        if(isBeginVector(nums)){
            break;
        }
    }
    return 0;
}
