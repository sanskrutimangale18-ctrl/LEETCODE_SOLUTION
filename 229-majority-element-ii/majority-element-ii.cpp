class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n=(int)nums.size();
        int count1=0, count2=0;
        int can1, can2;
        for(int i=0; i<n; i++){
            if(nums[i] == can1){
                count1++;
            }
            else if(nums[i] == can2)
                count2++;
            else{
                if(count1==0){
                    can1=nums[i];
                    count1++;
                }
                else if(count2==0){
                    can2=nums[i];
                    count2++;
                }
                else{
                    count1--;
                    count2--;
                }
            }
        }

        int c1=0, c2=0;
        for(int i=0; i<n; i++){
            if(nums[i] == can1)
                c1++;
            else if(nums[i] == can2)
                c2++;
        }
        
        vector<int>ans;
        if(c1 > n/3){
            ans.push_back(can1);
        }

        if(c2 > n/3){
            ans.push_back(can2);
        }
        return ans;
    }
};