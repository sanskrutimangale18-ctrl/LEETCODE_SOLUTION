class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int sumG=0, sumC = 0;
        int n = (int)gas.size();
        for(int i=0; i< n; i++){
            sumG +=gas[i];
            sumC +=cost[i];
        }

        if(sumG < sumC)
            return -1;

        int ans = 0, HG = 0;
        for(int i=0; i<n; i++){
            HG = HG +gas[i]-cost[i];

            if(HG < 0){
                HG =0;
                ans = (i + 1) % n;
            }
        }

        return ans;

    }
};