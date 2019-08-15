// Source : https://leetcode.com/problems/pancake-sorting/
// Author : Mading
// Date   : 2019-08-15

/*************************************************************************************** 
 * 969. Pancake Sorting [Medium]
 * Given an array A, we can perform a pancake flip: We choose some positive integer 
 * k <= A.length, then reverse the order of the first k elements of A.  We want to
 * perform zero or more pancake flips (doing them one after another in succession) 
 * to sort the array A.

 * Return the k-values corresponding to a sequence of pancake flips that sort A.  
* Any valid answer that sorts the array within 10 * A.length flips will be judged as correct.
 

 * Example 1:
 * Input: [3,2,4,1]
 * Output: [4,2,4,3]
 * Explanation: 
 * We perform 4 pancake flips, with k values 4, 2, 4, and 3.
 * Starting state: A = [3, 2, 4, 1]
 * After 1st flip (k=4): A = [1, 4, 2, 3]
 * After 2nd flip (k=2): A = [4, 1, 2, 3]
 * After 3rd flip (k=4): A = [3, 2, 1, 4]
 * After 4th flip (k=3): A = [1, 2, 3, 4], which is sorted. 

 * Example 2:
 * Input: [1,2,3]
 * Output: []
 * Explanation: The input is already sorted, so there is no need to flip anything.
 * Note that other answers, such as [3, 3], would also be accepted.
 

 * Note:
 * 1 <= A.length <= 100
 * A[i] is a permutation of [1, 2, ..., A.length]
 ***************************************************************************************/


// 4 ms, faster than 97.48% of C++, 8.7 MB, less than 83.33% of C++
class Solution {
public:
    void flipp(vector<int>& A, int start, int end)
    {
        while(start<end)
        {
            swap(A[start],A[end]);
            start++;
            end--;
        }
    }
    
    vector<int> pancakeSort(vector<int>& A) 
    {
        vector<int> v;
        vector<int> temp(A.size(),0);
        for(int i=0;i<A.size();i++)
            temp[i]=A[i];
        sort(temp.begin(),temp.end());
        
        
        while(A.size()!=1)
        {
            int index=-1;
            int max=INT_MIN;
            for(int i=0;i<A.size();i++)
            {
                if(A[i]>max)
                {
                    max=A[i];
                    index=i;
                }
            }
            v.push_back(index+1);
            flipp(A,0,index);
            v.push_back(A.size());
            flipp(A,0,A.size()-1);
            A.pop_back();
            temp.pop_back(); 
        }
        return v;
        
    }
};