// Source : https://leetcode.com/problems/bulls-and-cows/
// Author : Calinescu Valentin, Hao Chen
// Date   : 2015-11-04

/*************************************************************************************** 
 * 299. Bulls and Cows [Medium]
 * You are playing the following Bulls and Cows game with your friend: You write a 
 * 4-digit secret number and ask your friend to guess it. Each time your friend guesses
 * a number, you give a hint. The hint tells your friend how many digits are in the
 * correct positions (called "bulls") and how many digits are in the wrong positions
 * (called "cows"). Your friend will use those hints to find out the secret number.
 * 
 * For example:
 * 
 * Secret number:  "1807"
 * Friend's guess: "7810"
 * Hint: 1 bull and 3 cows. (The bull is 8, the cows are 0, 1 and 7.)
 * Write a function to return a hint according to the secret number and friend's guess,
 * use A to indicate the bulls and B to indicate the cows. In the above example, your
 * function should return "1A3B".
 * 
 * Please note that both secret number and friend's guess may contain duplicate digits,
 * for example:
 * 
 * Secret number:  "1123"
 * Friend's guess: "0111"
 * In this case, the 1st 1 in friend's guess is a bull, the 2nd or 3rd 1 is a cow, and
 * your function should return "1A1B".
 * You may assume that the secret number and your friend's guess only contain digits,
 * and their lengths are always equal.
 * 
 * Credits:
 * Special thanks to @jeantimex for adding this problem and creating all test cases.
 *               
 ***************************************************************************************/
 
class Solution {
public:
    string getHint(string secret, string guess) {
        return getHint02(secret, guess);
        return getHint01(secret, guess);
    }

    // 0 ms, faster than 100.00% of C++, 8.9 MB, less than 45.23% of C++
    string getHint01(string secret, string guess) {
        int appears_in_secret[10] = {0}, appears_in_guess[10] = {0}, bulls[10] = {0};
        int total_bulls = 0, total_cows = 0;
        for(int i = 0; i < secret.size(); i++)
            appears_in_secret[secret[i] - '0']++;
        for(int i = 0; i < guess.size(); i++)
        {
             if(secret[i] == guess[i])
                 bulls[secret[i] - '0']++;
             appears_in_guess[guess[i] - '0']++;
        }
        for(int i = 0; i <= 9; i++)
        {
            total_bulls += bulls[i];
            total_cows += min(appears_in_secret[i], appears_in_guess[i]) - bulls[i];
        }
        return to_string(total_bulls) + "A" + to_string(total_cows) + "B";
    }

    // Another implemntation - to save more space
    // 4 ms, faster than 98.83% of C++, 8.9 MB, less than 36.17% of C++ 
    string getHint02(string secret, string guess) {
        
        const int digital_num = 10;
        int secret_stat[digital_num]={0};
        
        int bull = 0;
        for(int i=0; i<secret.size(); i++) {
            //both number & location are matched, count bull
            if ( secret[i] == guess[i] ) {
                bull++;
                continue;
            }
            //otherwise, count the unmatched digits.
            secret_stat[secret[i]-'0']++;
        }
        
        int cow = 0;
        for(int i=0; i<guess.size(); i++) {
            //deal with duplication - decrease the digits count if cow is found.
            if ( secret[i] != guess[i] && secret_stat[guess[i]-'0']-- > 0 ) {
                cow++;
            }
        }
        
        return to_string(bull) + "A" + to_string(cow) + "B";
    }
    // unordered_map
    // 8 ms, faster than 72.66% of C++, 9.2 MB, less than 10.47% of C++
    string getHint03(string secret, string guess) {
        int sz = secret.size();
        vector<char> guess2;
        int A=0,B=0;
        unordered_map<char,int> mymap;
        for(int i = 0;i<sz;i++){
            if(secret[i] == guess[i]){
                A++;
            }
            else{
                mymap[secret[i]] ++;
                guess2.push_back(guess[i]);
            }
        }        
        
        for(int i = 0;i<guess2.size();i++){
            if(mymap.find(guess2[i]) != mymap.end() ){
                if( mymap[guess2[i]] >0 ){
                    mymap[guess2[i]]--;
                    B++;
                }                
            }
        }
        return to_string(A)+"A"+to_string(B)+"B";
        
    }
};
