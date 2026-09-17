class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        int a=original.size();
        vector<vector<int>>mat;
        if(a!= m*n){
            return mat;
        }

        int rows=m, cols=n;
        mat.resize(rows);

        for(int i=0;i <rows; i++){
            mat[i].resize(cols,0);
        }

        for(int i=0;i< m*n; i++){
            mat[i/n][i%n]=original[i];
        }
        return mat;
    }
};