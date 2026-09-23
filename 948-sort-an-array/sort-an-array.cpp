class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        int n= nums.size();
        mergeSort(nums, 0, n-1);
        return nums;
    }

private:
    void merge(vector<int>&nums, int low, int mid, int high){
        int i=low, j= mid +1, size = high - low + 1;
        vector<int>temp;

        while(i <=mid && j<=high){
            if(nums[i] <= nums[j]){
                temp.push_back(nums[i]);
                i++;
            }
            else{
                temp.push_back(nums[j]);
                j++;
            }
        }

        while(i<=mid){
            temp.push_back(nums[i]);
            i++;
        }

        while(j<=high){
            temp.push_back(nums[j]);
            j++;
        }

        for(int x=0; x< size;x++){
            nums[x + low] = temp[x];
        }
    }

    void mergeSort(vector<int>&nums, int low, int high){
        if(low >= high)
            return;

        int mid = low + (high - low)/2;
        mergeSort(nums, low, mid);
        mergeSort(nums, mid + 1, high);
        merge(nums, low, mid, high);
    }
};