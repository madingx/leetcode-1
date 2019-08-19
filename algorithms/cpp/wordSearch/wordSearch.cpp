// Source : https://leetcode.com/problems/word-search/
// Author : Hao Chen,Mading
// Date   : 2014-07-19

/********************************************************************************** 
* 79. Word Search [Medium]
* Given a 2D board and a word, find if the word exists in the grid.
* 
* The word can be constructed from letters of sequentially adjacent cell, 
* where "adjacent" cells are those horizontally or vertically neighboring. 
* The same letter cell may not be used more than once.
* 
* Example:
* board =
* [
*   ['A','B','C','E'],
*   ['S','F','C','S'],
*   ['A','D','E','E']
* ]
* Given word = "ABCCED", return true.
* Given word = "SEE", return true.
* Given word = "ABCB", return false.
* 
*               
**********************************************************************************/


/********** solution from  Discuss ***********************************************/
//https://leetcode.com/problems/word-search/discuss/27675/My-19ms-accepted-C%2B%2B-code
//24 ms 10.7 MB
class Solution {
    public:
        bool exist(vector<vector<char> > &board, string word) {
            m=board.size();
            n=board[0].size();
            for(int x=0;x<m;x++)
                for(int y=0;y<n;y++)
                {
                    if(isFound(board,word.c_str(),x,y))
                        return true;
                }
            return false;
        }
    private:
        int m;
        int n;
        bool isFound(vector<vector<char> > &board, const char* w, int x, int y)        {
            if(x<0||y<0||x>=m||y>=n||board[x][y]=='\0'||*w!=board[x][y])
                return false;
            if(*(w+1)=='\0')
                return true;
            char t=board[x][y];
            board[x][y]='\0';
            if(isFound(board,w+1,x-1,y)||isFound(board,w+1,x+1,y)||isFound(board,w+1,x,y-1)||isFound(board,w+1,x,y+1))
                return true; 
            board[x][y]=t;
            return false;
        }
    };




//solution 1
//336 ms    163.6 MB
bool exist(vector<vector<char>>& board, string word) {
    int row = board.size();
    int col = board[0].size();
    vector<vector<bool>> visited(row, vector<bool>(col, false));
    //从不同的位置开始出发，然后通过深搜寻找结果
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (dfs(board, word, 0, i, j, visited)) {
                return true;
            }
        }
    }
    return false;
}
bool dfs(vector<vector<char>>& board, string word, int index, int x, int y, vector<vector<bool>>& visited) {
    //终止条件
    if (index == word.size()) {
        return true;
    }
    //越界
    if (x < 0 || y < 0 || x >= board.size() || y >= board[0].size()) {
        return false;
    }
    //已经访问
    if (visited[x][y]) {
        return false;
    }
    //不相等
    if (board[x][y] != word[index]) {
        return false;
    }
    visited[x][y] = true;
    bool result = dfs(board, word, index + 1, x - 1, y, visited) || dfs(board, word, index + 1, x + 1, y, visited) || dfs(board, word, index + 1, x, y - 1, visited) || dfs(board, word, index + 1, x, y + 1, visited);//分别为上下左右地搜索.
    visited[x][y] = false; //准备回溯,设置回未访问状态.
    return result;
}



//solution 2
//368 ms  232 MB
//Recursive backtracking algorithm
bool exist(vector<vector<char> > &board, string word, int idx, int row, int col, vector< vector<int> > &mask) {
    int i = row;
    int j = col;
    if (board[i][j] == word[idx] && mask[i][j]==0 ) {
        mask[i][j]=1; //mark the current char is matched
        if (idx+1 == word.size()) return true;
        //checking the next char in `word` through the right, left, up, down four directions in the `board`.
        idx++; 
        if (( i+1<board.size()    && exist(board, word, idx, i+1, j, mask) ) ||
            ( i>0                 && exist(board, word, idx, i-1, j, mask) ) ||
            ( j+1<board[i].size() && exist(board, word, idx, i, j+1, mask) ) ||
            ( j>0                 && exist(board, word, idx, i, j-1, mask) ) )
        {
             return true;
        }
        mask[i][j]=0; //cannot find any successful solution, clear the mark. (backtracking)
    }
    return false;
}


bool exist(vector<vector<char> > &board, string word) {
    if (board.size()<=0 || word.size()<=0) return false;
    int row = board.size();
    int col = board[0].size();

    for(int i=0; i<board.size(); i++) {
        for(int j=0; j<board[i].size(); j++){
            if ( board[i][j]==word[0]  ){
                if( exist(board, word, 0, i, j) ){
                    return true;
                }
            }
        }
    }
    return false;
}



vector< vector<char> > buildBoard(char b[][5], int r, int c) {
    vector< vector<char> > board;
    for (int i=0; i<r; i++){
        vector<char> v(b[i], b[i]+c);
        cout << b[i] << endl;
        board.push_back(v);
    }
    cout << "----------" << endl;    
    return board;
}

int main(int argc, char** argv)
{
    string s;
    char b[3][5] ={ "ABCE", "SFCS", "ADEE" };
    vector< vector<char> > board = buildBoard(b, 3, 4);

    s = "SEE";
    cout << s << ":" << exist(board, s) << endl; 

    s = "ABCCED";
    cout << s << ":" << exist(board, s) << endl; 

    s = "ABCB";
    cout << s << ":" << exist(board, s) << endl; 


    if (argc>1){
        s = argv[1];
        cout << s << ":" << exist(board, s) << endl; 
    }

    cout << endl << "----------" << endl;    
    char b1[3][5] ={ "CAA", "AAA", "BCD" };
    board = buildBoard(b1, 3, 3);

    s = "AAB";
    cout << s << ":" << exist(board, s) << endl; 


    cout << endl << "----------" << endl;    
    char b2[3][5] ={ "ABCE", "SFES", "ADEE" };
    board = buildBoard(b2, 3, 4);

    s = "ABCESEEEFS";
    cout << s << ":" << exist(board, s) << endl; 

    cout << endl << "----------" << endl;    
    char b3[3][5] ={ "aaaa", "aaaa", "aaaa" };
    board = buildBoard(b3, 3, 4);

    s = "aaaaaaaaaaaaa";
    cout << s << ":" << exist(board, s) << endl; 

    return 0;
}
