class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>>mat(n, vector<int>(n));
        int num=1;
        int srow=0, scol=0, erow=n-1, ecol= n-1;
        while(srow <= erow && scol <= ecol){
            for(int j=scol; j<=ecol; j++){
                mat[srow][j]=num++;
            }

            for(int i=srow+1; i<=erow; i++){
                mat[i][ecol]=num++;
            }

            for(int j=ecol-1; j>=scol; j--){
                mat[erow][j]=num++;
            }

            for(int i=erow-1; i>=srow+1; i--){
                mat[i][scol]=num++;
            }

            srow++, erow--, scol++, ecol--;
        }
        return mat;
    }
};