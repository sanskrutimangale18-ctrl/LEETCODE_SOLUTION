class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<string>board(n, string(n, '.'));
        vector<vector<string>>solution;
        possible_solution(board, solution, 0, n);
        return solution;
    }

private:
    bool isSafe(vector<string>&board, int row, int col){
        int n= board.size();
        //vertical
        for(int i=0; i< row; i++){
            if (board[i][col] == 'Q')
                return false;
        }

        //horizontal
        for(int j=0; j< col; j++){
            if(board[row][j] == 'Q'){
                return false;
            }
        }

        //diagonal left
        for(int i=row, j=col; i>=0 && j>=0; i--, j--){
            if(board[i][j] == 'Q')
                return false;
        }

        //diagonal right
        for(int i=row, j=col; i>=0 && j<n; i--, j++){
            if(board[i][j] == 'Q')
                return false;
        }  

        return true;      
    }

    void possible_solution(vector<string>&board, vector<vector<string>>&final_ans, int row, int n){
        if(row == n){
            final_ans.push_back(board);
            return;
        }
        for(int i=0; i<n; i++){
            if(isSafe(board, row, i)){
                board[row][i] = 'Q';
                possible_solution(board, final_ans, row + 1, n);
                board[row][i] = '.';
            }
        }
    }
};