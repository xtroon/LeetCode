class Solution {
public:

    bool isSafe(int row, int col, int n, vector<string>& board){

        //check in row
        for(int i=col; i>=0; i--){
            if(board[row][i] == 'Q') return false;
        }

        // check upper left diagonal
        for(int i= row, j= col; i>=0 && j>=0; i--,j--){
            if(board[i][j] == 'Q') return false;
        }

        //check lower left
        for(int i= row, j= col; i<n && j>=0; i++,j--){
            if(board[i][j] == 'Q') return false;
        }

        return true;
    }

    void findQueens(int col, int n, vector<string>& board, vector<vector<string>>& ans){
        
        if(col == n){
            ans.push_back(board);
            return;
        }

        for(int i=0 ; i<n; i++){
            if(isSafe(i, col, n, board)){
                // mark as queen
                board[i][col] = 'Q';

                // recusive
                findQueens(col+1, n, board, ans);

                //backtrack
                board[i][col] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n);
        string s(n, '.');

        for(int i=0; i<n; i++){
            board[i] = s;
        }
        
        findQueens(0, n, board, ans);

        return ans;
    }
};