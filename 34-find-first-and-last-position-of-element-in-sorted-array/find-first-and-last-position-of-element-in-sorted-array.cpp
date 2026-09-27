class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if((int)nums.size() == 0)
            return {-1, -1};

        if((int)nums.size() == 1){
            if(nums[0] == target)
                return {0, 0};
            else
                return {-1, -1};
        }

        int left = binary_search(nums, target, true);
        int right = binary_search(nums, target, false);

        return {left, right};
    }

private:
    int binary_search(vector<int>&nums, int target, bool is_left){
        int n = (int)nums.size();
        int low = 0, high = n-1, mid, temp;
        bool is_found = false;
        
        while(low <= high){
            mid = low + (high - low)/2;
            if(nums[mid] == target){
                is_found = true;
                temp = mid;
                if(is_left){
                    high = mid - 1;
                }
                else{
                    low = mid + 1;
                }
            }
            else if(nums[mid] < target){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }

        if(is_found){
            return temp;
        }
        else{
            return -1;
        }
    }
};