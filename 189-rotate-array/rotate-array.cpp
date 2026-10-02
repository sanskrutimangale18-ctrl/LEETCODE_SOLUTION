class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        reverse(nums.begin(), nums.end());

        int n= (int)nums.size();
        reverse(nums.begin(), nums.begin() +(k % n));
        reverse(nums.begin() + (k % n), nums.end());
    }
};