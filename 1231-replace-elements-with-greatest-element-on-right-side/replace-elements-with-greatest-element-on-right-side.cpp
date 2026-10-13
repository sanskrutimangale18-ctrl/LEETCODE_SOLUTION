class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        vector<int>ans;
        int n = (int)arr.size();
        for(int i = 0; i < n; i++){
            if(i == n-1){
                ans.push_back(-1);
                break;
            }
            int Max_num = INT_MIN;
            for(int j= i+1; j < n; j++){
                Max_num = max(Max_num, arr[j]);
            }
            ans.push_back(Max_num);
        }
        return ans;
    }
};