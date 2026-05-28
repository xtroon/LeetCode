class Solution {
public:
    bool dfs(vector<vector<char>>& board, string& word, int i, int j, int idx){

        //base cases
        if(idx >= word.size()) return true;

        if(i<0 || j<0 || i>=board.size() || j>=board[0].size() || board[i][j] != word[idx]){
            return false;
        }

        // if we here mean that element exists
        char temp = board[i][j];  // store it for later
        board[i][j] = '*'; // mark it marked

        bool valid = dfs(board, word, i+1, j, idx+1) ||
                     dfs(board, word, i-1, j, idx+1) ||
                     dfs(board, word, i, j+1, idx+1) ||
                     dfs(board, word, i, j-1, idx+1);

        board[i][j] = temp;
        return valid;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();

        // first check if it even exist
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(dfs(board, word, i, j, 0)){
                    return true;
                }
            }
        }

        return false;
    }
};