class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                if(board[i][j] != '.'){
                    if(!(isSafe(board, i, j))){
                        return false;
                    }
                }
            }
        }

        return true;
    }

private:
    bool isSafe(vector<vector<char>>& board, int row, int col){
        
        //horizontal
        for(int j=0; j<9; j++){
            if(j!=col){
                if(board[row][j] == board[row][col]){
                    return false;
                }
            }
        }
        
        //vertical
        for(int i=0;i<9; i++){
            if(i!=row){
                if(board[i][col] == board[row][col]){
                    return false;
                }
            }
        }

        //grid
        int srow=(row/3)*3, scol=(col/3)*3;

        for(int i=srow; i<=srow+2; i++){
            for(int j=scol; j<=scol+2; j++){
                if(i!=row && j!=col){
                    if(board[i][j] == board[row][col]){
                        return false;
                    }
                }
            }
        }

        return true;

    }
};