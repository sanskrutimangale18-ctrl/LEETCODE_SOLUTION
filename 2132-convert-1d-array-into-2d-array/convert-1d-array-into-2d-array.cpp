class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        int a= original.size();
        if(a!= m*n){
            return {};
        }

        vector<vector<int>>mat(m, vector<int>(n));

        for(int i=0;i< m*n; i++){
            mat[i/n][i%n]=original[i];
        }
        return mat;
    }
};