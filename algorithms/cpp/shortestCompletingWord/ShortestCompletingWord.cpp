// Source : https://leetcode.com/problems/shortest-completing-word/
// Author : Mading
// Date   : 2019-09-08

/********************************************************************************** 
* 748. Shortest Completing Word [Easy]
* Find the minimum length word from a given dictionary words, 
* which has all the letters from the string licensePlate. 
* Such a word is said to complete the given string licensePlate

* Here, for letters we ignore case. For example, "P" on the 
* licensePlate still matches "p" on the word.

* It is guaranteed an answer exists. If there are multiple answers, 
* return the one that occurs first in the array.

* The license plate might have the same letter occurring multiple times. 
* For example, given a licensePlate of "PP", the word "pair" does not 
* complete the licensePlate, but the word "supper" does.

* Example 1:
* Input: licensePlate = "1s3 PSt", words = ["step", "steps", "stripe", "stepple"]
* Output: "steps"
* Explanation: The smallest length word that contains the letters "S", "P", "S", and "T".
* Note that the answer is not "step", because the letter "s" must occur in the word twice.
* Also note that we ignored case for the purposes of comparing whether a letter exists in the word.

* Example 2:
* Input: licensePlate = "1s3 456", words = ["looks", "pest", "stew", "show"]
* Output: "pest"
* Explanation: There are 3 smallest length words that contains the letters "s".
* We return the one that occurred first.
* Note:
* licensePlate will be a string with length in range [1, 7].
* licensePlate will contain digits, spaces, or letters (uppercase or lowercase).
* words will have a length in the range [10, 1000].
* Every words[i] will consist of lowercase letters, and have length in range [1, 15].  
**********************************************************************************/

// 28 ms, faster than 45.27% of C++, 15.8 MB, less than 40.00% of C++.
class Solution {
public:
    string shortestCompletingWord(string licensePlate, vector<string>& words) {
        unordered_map<char,int> dictmap;
        for(auto c:licensePlate){
            if(c >= 'A' && c <= 'Z') c += 32;
            if(c >= 'a' && c <= 'z' ) {
                dictmap[c]++;
            }
        }
        
        string minstr = words[0];
        int minlen = INT_MAX;
        for(auto word:words){
            unordered_map<char,int> dictmap2(dictmap);
            for(auto c:word){
                if(c >= 'A' && c <= 'Z') c += 32;
                if(dictmap2.count(c) > 0)dictmap2[c]--;
            }
            bool flag = true;
            for(auto d:dictmap2){
                if(d.second > 0){
                    flag = false;
                    break;
                }
            }
            if(flag){
                if(word.size() < minlen){
                    minstr = word;
                    minlen = word.size();
                }
            }
            
        }
        return minstr;
        
    }
};