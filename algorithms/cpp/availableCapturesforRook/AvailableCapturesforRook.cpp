// Source : https://leetcode.com/problems/available-captures-for-rook/
// Author : Mading
// Date   : 2019-04-13

/********************************************************************************** 
 * 999. Available Captures for Rook [Easy]

 * On an 8 x 8 chessboard, there is one white rook.  There also may be empty squares,
 * white bishops, and black pawns.  These are given as characters 'R', '.', 'B', 
 * and 'p' respectively. Uppercase characters represent white pieces, and lowercase
 * characters represent black pieces.

 * The rook moves as in the rules of Chess: it chooses one of four cardinal directions
 * (north, east, west, and south), then  * moves in that direction until it chooses to
 * stop, reaches the edge of the board, or captures an opposite colored pawn by moving
 * to the same square it occupies.  Also, rooks cannot move into the same square as 
 * other friendly bishops.

 * Return the number of pawns the rook can capture in one move.

 * Example 1:
 * Input: 
 * [[".",".",".",".",".",".",".","."],
 *  [".",".",".","p",".",".",".","."],
 *  [".",".",".","R",".",".",".","p"],
 *  [".",".",".",".",".",".",".","."],
 *  [".",".",".",".",".",".",".","."],
 *  [".",".",".","p",".",".",".","."],
 *  [".",".",".",".",".",".",".","."],
 *  [".",".",".",".",".",".",".","."]]
 * Output: 3
 * Explanation: 
 * In this example the rook is able to capture all the pawns.

 * Example 2:
 * Input: 
 * [[".",".",".",".",".",".",".","."],
 *  [".","p","p","p","p","p",".","."],
 *  [".","p","p","B","p","p",".","."],
 *  [".","p","B","R","B","p",".","."],
 *  [".","p","p","B","p","p",".","."],
 *  [".","p","p","p","p","p",".","."],
 *  [".",".",".",".",".",".",".","."],
    [".",".",".",".",".",".",".","."]]
 * Output: 0
 * Explanation: 
 * Bishops are blocking the rook to capture any pawn.

 * Example 3:
 * Input: 
 * [[".",".",".",".",".",".",".","."],
 *  [".",".",".","p",".",".",".","."],
 *  [".",".",".","p",".",".",".","."],
 *  ["p","p",".","R",".","p","B","."],
 *  [".",".",".",".",".",".",".","."],
 *  [".",".",".","B",".",".",".","."],
 *  [".",".",".","p",".",".",".","."],
 *  [".",".",".",".",".",".",".","."]]
 * Output: 3
 * Explanation: 
 * The rook can capture the pawns at positions b5, d6 and f5.
 

 * Note:
 * board.length == board[i].length == 8
 * board[i][j] is either 'R', '.', 'B', or 'p'
 * There is exactly one cell with board[i][j] == 'R'
 *               
 **********************************************************************************/

// 4 ms, faster than 100.00% of C++, 8.5 MB, less than 100.00% of C++ 
class Solution {
public:
    int findRook(vector<vector<char>>& board,int &m,int &n){
        for(m=0;m<board.size();m++){
            for(n=0;n<board[0].size();n++){
                if(board[m][n]=='R')return 1;
            }
        }
        return 0;
    }
    int numRookCaptures(vector<vector<char>>& board) {
        int m=0,n=0;
        int flag = findRook(board,m,n);
        if(flag==0)return 0;
        int cnt = 0;
        for(int i=m-1;i>=0;i--){
            if(board[i][n]=='p'){
                cnt++;
                break;
            }
            else if(board[i][n]=='B')break;
        }
        for(int i=m+1;i<board.size();i++){
            if(board[i][n]=='p'){
                cnt++;
                break;
            }
            else if(board[i][n]=='B')break;
        }
        for(int j=n-1;j>=0;j--){
            if(board[m][j]=='p'){
                cnt++;
                break;
            }
            else if(board[m][j]=='B')break;
        }
        for(int j=n+1;j<board[0].size();j++){
            if(board[m][j]=='p'){
                cnt++;
                break;
            }
            else if(board[m][j]=='B')break;
        }
        return cnt;
        
    }
};