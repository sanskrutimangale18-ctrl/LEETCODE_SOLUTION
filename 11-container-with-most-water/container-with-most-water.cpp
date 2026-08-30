class Solution {
public:
    int maxArea(vector<int>& height) {
        int l=0, r=height.size()-1, area=0;

        while(l<r){
            int d1= r-l;
            int d2= min(height[l],height[r]);
            int currArea=d1*d2;
            area= max(area, currArea);

            if(height[l]> height[r])
                r--;
            else
                l++;
        }
        return area;
    }
};