// Source : https://leetcode.com/problems/additive-number/
// Author : Hao Chen
// Date   : 2015-11-22

/*************************************************************************************** 
 * 306. Additive Number [Medium]
 * Additive number is a positive integer whose digits can form additive sequence.
 * 
 * A valid additive sequence should contain at least three numbers. Except for the 
 * first two numbers, each subsequent number in the sequence must be the sum of the 
 * preceding two.
 * 
 * For example:
 * "112358" is an additive number because the digits can form an additive sequence: 1, 
 * 1, 2, 3, 5, 8.
 * 1 + 1 = 2, 1 + 2 = 3, 2 + 3 = 5, 3 + 5 = 8
 * "199100199" is also an additive number, the additive sequence is: 1, 99, 100, 199.
 * 1 + 99 = 100, 99 + 100 = 199
 * 
 * Note: Numbers in the additive sequence cannot have leading zeros, so sequence 1, 2, 
 * 03 or 1, 02, 3 is invalid.
 * 
 * Given a string represents an integer, write a function to determine if it's an 
 * additive number.
 * 
 * Follow up:
 * How would you handle overflow for very large input integers?
 * 
 * Credits:Special thanks to @jeantimex for adding this problem and creating all test 
 * cases.
 *               
 ***************************************************************************************/

// 0 ms, faster than 100.00% of C++, 8.4 MB, less than 25.60% of C++
class Solution {
public:
    bool isAdditiveNumber(string num) {
        int len = num.size();
        
        for(int i=1; i<len/2+1; i++) {
            string n1 = num.substr(0, i);
            if ( n1.size()>1 && n1[0] == '0') break;
            for(int j=i+1; j<len; j++) {
                string n2 = num.substr(i, j-i);
                if ( n2.size()>1 && n2[0] == '0') break;
                string n3 = num.substr(j);
                if (isAdditiveNumberHelper(n1, n2, n3)) return true;
            }
        }
        return false;
    }
    
private:
    bool isAdditiveNumberHelper(string& n1, string& n2, string& n3){
        string add = StringAdd(n1, n2);
        
        if (add.size() > n3.size()) return false;
        
        if (add == n3 ) return true;
        
        //split the n3 to 2 parts, and keep going.
        string cut = n3.substr(0, add.size());
        if (add == cut) {
            string rest = n3.substr(add.size());
            return isAdditiveNumberHelper(n2, add, rest);
        }
        return false;
    }


    string StringAdd(string n1, string n2) {
        
        if (n1.size() < n2.size()) {
            string tmp = n1;
            n1 = n2;
            n2 = tmp;
        }
        
        int carry=0;
        string result;
        for (int i=n1.size()-1, j=n2.size()-1; i>=0; i--, j--) {

            int n = n1[i] - '0' + carry;
            if ( j >= 0) {
                n += n2[j] - '0';
            } 
            char ch = n % 10 + '0';
            carry = n/10;
            result = ch + result;
        }
        if (carry>0) result = (char)(carry+'0') + result;
        return result;
        
    }
};


// 0 ms, faster than 100.00% of C++, 8.5 MB, less than 11.48% of C++
class Solution {
public:
    // Returns true if 'str' does not have any leading 0s.
    bool isValid(const string& str) {
        if (str.size() > 1 && str[0] == '0') {
            return false;
        }
        return true;
    }
    
    // Tries to add a first and second numbers and checks if the
    // third number is in 'num'.
    bool isValidAddition(const int first_start,
                         const int first_len,
                         const int second_start,
                         const int second_len,
                         const string& num,
                         int& p_third_len) {
        int third_start = second_start + second_len;
        if (max(first_len, second_len) > num.size() - third_start) {
            return false;
        }
        string first_num_str = num.substr(first_start, first_len);
        if (!isValid(first_num_str)) {
            return false;
        }
        string second_num_str = num.substr(second_start, second_len);
        if (!isValid(second_num_str)) {
            return false;
        }
        int64_t sum =
            (int64_t)stoi(first_num_str) + (int64_t)stoi(second_num_str);
        string sum_str = to_string(sum);
        if (sum_str.size() + third_start > num.size()) {
            return false;
        }
        if (sum_str != num.substr(third_start, sum_str.size())) {
            return false;
        }
        p_third_len = sum_str.size();
        return true;
    }
    
    // Attempts to split 'range' such that the additive property for num
    // is satisfied. Returns true if we have a valid split. False otherwise.
    bool checkForAdditives(const int range,
                           const string& num) {
        for (int index = 0; index < range - 1; ++index) {
            int first_start = 0;
            int first_len = index - 0 + 1;
            int second_start = index + 1;
            int second_len = range - second_start;
            
            int third_len;
            if (!isValidAddition(first_start, first_len,
                                 second_start, second_len,
                                 num, third_len)) {
                continue;
            }

            int third_start = second_start + second_len;
            bool all_valid = true;
            while (third_start + third_len < num.size()) {
                first_start = second_start;
                first_len = second_len;
                second_start = third_start;
                second_len = third_len;
                if (!isValidAddition(first_start, first_len,
                                     second_start, second_len,
                                     num, third_len)) {
                    all_valid = false;
                    break;
                }
                third_start = second_start + second_len;
            }
            if (all_valid) {
                return true;
            }
        }
        return false;
    }
    
    bool isAdditiveNumber(string num) {
        if (num.size() < 3) {
            return false;
        }
        // The intuition is as follows:
        // The string num denotes an array of digits. Let's take an index
        // k such that 1 <= k < n. Now for us to get a valid additive
        // number, there are two conditions to be met:
        // 1. We need to split the range [0, k] at l such that,
        // num[0, l] + num(l, k] == a number that starts from k + 1.
        // For example in "123", 1 + 2  = 3.
        // 2. This property needs to hold for the next numbers in num.
        // For example, in "1235", 1 + 2 = 3 (Condition 1 satistified)
        // and 2 + 3 = 5 (Condition 2 satisfied). While in "1236",
        // 1 + 2 = 3 but 2 + 3 != 6.
        
        // Given the above, we start with a range of 2 (k = 1) and try
        // to split the range such that the above two conditions are
        // satisfied. 'checkForAdditives' returns true if that's the case.
        for (int range = 2; range <= num.size(); ++range) {
            if (checkForAdditives(range, num)) {
                return true;
            }
        }
        return false;
    }
};