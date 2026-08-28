class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> ans;
        sort(nums.begin(),nums.end());

        for(int i=1;i<nums.size();i++){
            if(nums[i]==nums[i-1]){
                ans.push_back(nums[i]);
            }
        }
        int e_sum=nums.size()*(nums.size()+1)/2;
        int a_sum=0;
        for(int i=0;i<nums.size();i++)
            a_sum+=nums[i];
        ans.push_back(e_sum - (a_sum - ans[0]));

        return ans;
    }
};