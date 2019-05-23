// Source : https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/
// Author : Mading
// Date   : 2019-05-23

/********************************************************************************** 
 * 421. Maximum XOR of Two Numbers in an Array [Medium]
 * Given a non-empty array of numbers, a0, a1, a2, … , an-1, where 0 ≤ ai < 231.
 * Find the maximum result of ai XOR aj, where 0 ≤ i, j < n.
 * Could you do this in O(n) runtime?

 * Example:
 * Input: [3, 10, 5, 25, 2, 8]
 * Output: 28
 * Explanation: The maximum result is 5 ^ 25 = 28.
 * 
 **********************************************************************************/


// https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/discuss/130427/()-92
// 60 ms, faster than 83.32% of C++, 30.1 MB, less than 51.80% of C++
struct TrieNode{
    int val;
    TrieNode *left;
    TrieNode *right;
    TrieNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:

    int findMaximumXOR(vector<int>& nums) {
        TrieNode* root = new TrieNode(0);


        //建树
        TrieNode* curNode = root;
        for(int i = 0; i < nums.size(); i++){
            for(int j = 31; j >= 0; j--) {
                int tmp = nums[i] & (1 << j);
                if(tmp == 0){
                    if(!curNode->right){
                        curNode->right = new TrieNode(0);
                    }
                    curNode = curNode->right;
                }else{
                    if(!curNode->left){
                        curNode->left = new TrieNode(1);
                    }
                    curNode = curNode->left;
                }
                //cout << curNode->val;
            }
            //cout << endl;
            curNode = root;
        }

        //匹配最大异或值
        int max = 0;
        for(int i = 0; i < nums.size(); i++){
            int res = 0;
            for(int j = 31; j >= 0; j--){
                int tmp = nums[i] & (1 << j);
                //cout << (1 << j) << "\t" << tmp << endl;
                if(curNode->left && curNode->right){
                    if(tmp == 0){
                        curNode = curNode->left;
                    }else {
                        curNode = curNode->right;
                    }    
                }else {
                    curNode = curNode->left == NULL ? curNode->right:curNode->left;
                }
                res += tmp ^ (curNode->val << j);
                //cout << curNode->val;
            }
            curNode = root;
            //cout << endl;
            max = max > res?max:res;
        }

        return max;
    }
};