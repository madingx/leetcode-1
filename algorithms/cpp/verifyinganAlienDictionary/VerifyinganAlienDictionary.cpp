// Source : https://oj.leetcode.com/problems/3sum-closest/
// Author : Mading
// Date   : 2019-09-14

/********************************************************************************** 
* 953. Verifying an Alien Dictionary [Easy]
* In an alien language, surprisingly they also use english lowercase letters, 
* but possibly in a different order. The order of the alphabet is some permutation of lowercase letters.

* Given a sequence of words written in the alien language, and the order of the alphabet, 
* return true if and only if the given words are sorted lexicographicaly in this alien language.

 * Example 1:
* Input: words = ["hello","leetcode"], order = "hlabcdefgijkmnopqrstuvwxyz"
* Output: true
* Explanation: As 'h' comes before 'l' in this language, then the sequence is sorted.

* Example 2:
* Input: words = ["word","world","row"], order = "worldabcefghijkmnpqstuvxyz"
* Output: false
* Explanation: As 'd' comes after 'l' in this language, then words[0] > words[1], hence the sequence is unsorted.

* Example 3:
* Input: words = ["apple","app"], order = "abcdefghijklmnopqrstuvwxyz"
* Output: false
* Explanation: The first three characters "app" match, and the second string is shorter (in size.) 
* According to lexicographical rules "apple" > "app", because 'l' > '∅', where '∅' is defined 
* as the blank character which is less than any other character (More info).
 

* Note:
* 1 <= words.length <= 100
* 1 <= words[i].length <= 20
* order.length == 26
* All characters in words[i] and order are english lowercase letters.
* 
*               
**********************************************************************************/

// 8 ms, faster than 58.60% of C++, 9.4 MB, less than 53.85% of C++.
class Solution {
public:
    unordered_map<char, int> m;
    bool isAlienSorted(vector<string>& words, string order) {
        for (int i = 0; i < order.size(); ++i)
            m[order[i]] = i;
        for (int i = 0; i < words.size() - 1; ++i) {
            if (!cmp(words[i], words[i + 1]))
                return false;
        }
        return true;
    }
    
    bool cmp(const string& left, const string& right) {
        for (int i = 0; i < min(left.size(), right.size()); ++i) {
            if (i == 0 && m[left[i]] < m[right[i]]) // only valid if the first two are in this order
                return true;
            else if (m[left[i]] > m[right[i]])
                return false;
            // if reach here, means all the previous characters in two strings are the same, so keep going
        }
        return left.size() <= right.size(); // if reach here, means all the characters in two strings are the same, then just compare if the length are valid: e.g. 'aa' has to be in front of 'aaa'
    }
};  