class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
         //your code goes here
        vector<vector<string>> answer;
        vector<string> board (n,string(n,'.'));
        func(0,board,answer);
        return answer;
    }

    void func(int col,vector<string>&board, vector<vector<string>>&answer){
        // base case
        if(col == board.size()){
            answer.push_back(board);
            return;
        }

        for(int row=0; row < board.size(); row++){
            if(CanPlace(board,row,col)){
                board[row][col] = 'Q';
                func(col+1,board,answer);
                board[row][col] = '.';
            }
        }
    }

    bool CanPlace(vector<string>& board, int row, int col) {
        int r = row, c = col;

        // Check upper left diagonal
        while (r >= 0 && c >= 0) {
            if (board[r][c] == 'Q') return false;
            r--;
            c--;
        }

        // Reset to the original position
        r = row;
        c = col;

        // Check left side
        while (c >= 0) {
            if (board[r][c] == 'Q') return false;
            c--;
        }

        // Reset to the original position
        r = row;
        c = col;

        // Check lower left diagonal
        while (r < board.size() && c >= 0) {
            if (board[r][c] == 'Q') return false;
            r++;
            c--;
        }

        // If no queens are found, it's safe
        return true;
    
    }
};