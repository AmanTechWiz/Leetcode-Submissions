class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
      int N = board.size();
        int M = board[0].size();
        int i,j;

        for(i=0; i<N; i++){
            for(j=0; j<M; j++){
                if(board[i][j] == word[0]){
                    if(func(0,i,j,board,word)){
                        return true;
                    }
                }
            }
        }
        return false;
    }

    bool func(int index , int i, int j, vector<vector<char> >& board, string word){
        // base case
        if(index == word.length()){
            return true;
        }

        if(i<0 || j < 0 || i>=board.size() || j>=board[0].size() || board[i][j] != word[index]){
            return false;
        }

        bool ans = false;
        char x = board[i][j];
        board[i][j] = ' ';

        // moving the pointer :

        // cases - top , down , left , right

      ans |=  func(index+1,i-1,j,board,word);
      ans |= func(index+1,i+1,j,board,word);
      ans |= func(index+1,i,j-1,board,word);
      ans |= func(index+1,i,j+1,board,word);

      board[i][j] = x;
      return ans;
    }
};