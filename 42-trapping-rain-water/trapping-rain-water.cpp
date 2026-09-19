class Solution {
public:
    int trap(vector<int>& height) {
        if(height.size() == 1)
            return 0;

        int n=(int)height.size();
        int left=0, right=n-1, leftMax=0, rightMax=0;
        int water=0;

        while(left < right){
            if(height[left] < height[right]){
                if(leftMax > height[left]){
                    water += (leftMax - height[left]);
                    left++;
                }
                else{
                    leftMax = height[left];
                    left++;
                }
            }
            else{
                if(rightMax > height[right]){
                    water +=(rightMax - height[right]);
                    right--;
                }
                else{
                    rightMax = height[right];
                    right--;
                }
            }
        }

        return water;        
    }
};