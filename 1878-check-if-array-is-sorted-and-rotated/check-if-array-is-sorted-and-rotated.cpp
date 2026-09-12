class Solution {
public:
    bool check(vector<int>& nums) {
        bool isSorted= true;
        int second;
        for(int i=1; i<nums.size(); i++){
            if(nums[i]< nums[i-1]){
                second= i;
                isSorted= false;
                break;
            }
        }

        if(isSorted)
            return true;
        else{
            vector<int>aux;
            for(int i=second; i<nums.size(); i++)
                aux.push_back(nums[i]);
            for(int i=0; i<second; i++)
                aux.push_back(nums[i]);
        
            for(int i=1; i<nums.size(); i++){
                if(aux[i]< aux[i-1])
                    return false;
            }
        }
        return true;
    }
};