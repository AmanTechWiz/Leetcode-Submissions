class Solution {
public:
    void solveSudoku(vector<vector<char> >& board) {
        solve(board);
    }
    
    bool solve(vector<vector<char>>& board){
        //your code goes here

        int n = 9;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(board[i][j] == '.'){
                    for(char digit = '1'; digit <= '9'; digit++){
                        if(rulescheck(board,digit,i,j)){
                            board[i][j] = digit;
                            if(solve(board)){
                                return true;
                            }else{
                                board[i][j] = '.';
                            }
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }

    bool rulescheck(vector<vector<char>>& board,char digit, int row, int col){
        for(int i=0; i<9; i++){
            if(board[i][col] == digit || board[row][i] == digit) return false;
        }

        int startRow = (row / 3) * 3;
        int startCol = (col / 3) * 3;

        for(int i = startRow ; i<startRow + 3; i++){
            for(int j = startCol ; j<startCol + 3; j++){
                if(board[i][j] == digit) return false; // digit found
            }
        }

        return true ; // all good
    }
};