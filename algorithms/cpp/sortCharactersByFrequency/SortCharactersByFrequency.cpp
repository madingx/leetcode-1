// Source : https://leetcode.com/problems/sort-characters-by-frequency/
// Author : Mading
// Date   : 2019-05-15

/********************************************************************************** 
 * 451. Sort Characters By Frequency [Medium]
 * Given a string, sort it in decreasing order based on the frequency of characters.

 * Example 1:
 * Input:
 * "tree"
 * Output:
 * "eert"
 * Explanation:
 * 'e' appears twice while 'r' and 't' both appear once.
 * So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.

 * Example 2:
 * Input:
 * "cccaaa"
 * Output:
 * "cccaaa"
 * Explanation:
 * Both 'c' and 'a' appear three times, so "aaaccc" is also a valid answer.
 * Note that "cacaca" is incorrect, as the same characters must be together.

 * Example 3:
 * Input:
 * "Aabb"
 * Output:
 * "bbAa"
 * Explanation:
 * "bbaA" is also a valid answer, but "Aabb" is incorrect.
 * Note that 'A' and 'a' are treated as two different characters.
 **********************************************************************************/

// O(n^2) time
// 24 ms, faster than 50.24% of C++, 11.3 MB, less than 31.22% of C++
class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> m;
        for(int i = 0;i<s.size();i++){
            if(m.find(s[i]) != m.end()){
                m[s[i]]++;
            }
            else{
                m[s[i]] = 1;
            }
        }
        ostringstream sss;
        
        while(m.size()>0){
            int maxx = 0;
            unordered_map<char,int>::iterator it1=m.begin(),it2=m.begin();
            for(;it1!=m.end();it1++){
                if(it1->second>maxx){
                    maxx = it1->second;
                    it2 = it1;
                }
            }
            for(int i=0;i<it2->second;i++){
                sss<<it2->first;
            }            
            m.erase(it2);
        }
        return sss.str();
        
    }
};


// 24 ms, faster than 50.24% of C++, 18.5 MB, less than 6.43% of C++
class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> freq;
        vector<string> bucket(s.size()+1, "");
        string res;
        
        //count frequency of each character
        for(char c:s) freq[c]++;
        //put character into frequency bucket
        for(auto& it:freq) {
            int n = it.second;
            char c = it.first;
            bucket[n].append(n, c);
        }
        //form descending sorted string
        for(int i=s.size(); i>0; i--) {
            if(!bucket[i].empty())
                res.append(bucket[i]);
        }
        return res;
    }
};

// 16 ms, faster than 93.77% of C++, 11 MB, less than 51.07% of C++ 
class Solution {
public:
    string frequencySort(string s) {
        
        unordered_map<char,int> map;
        for(auto c : s)
            map[c]++;
        
        auto cmp = [](const pair<char,int> &lhs, const pair<char,int> &rhs)
        {
            return lhs.second < rhs.second || (lhs.second == rhs.second && lhs.first > rhs.first);
        };
        
        priority_queue<pair<char,int>,vector<pair<char,int>>,decltype(cmp)> pq(cmp);
        
        for(auto m : map)
        {
            pq.push(make_pair(m.first,m.second));
        }
        
        string ans = "";
        while(!pq.empty())
        {
            pair<char,int> top = pq.top();
            pq.pop();
            ans.append(top.second,top.first);
        }
        
        return ans;
        
    }
};