class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = (int)nums.size();
        int left = 0, sum = 0, minLength = INT_MAX;

        for(int right = 0; right < n; right++){
            sum += nums[right];

            while(sum >= target){
                minLength = min(minLength, right - left + 1);
                sum -= nums[left];
                left++;
            }
        }
        return minLength <= n && minLength >=1 ? minLength: 0;
    }
};