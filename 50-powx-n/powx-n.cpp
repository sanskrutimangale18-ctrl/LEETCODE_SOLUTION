class Solution {
public:
    double myPow(double x, int n) {
        double ans=1;
        long long int temp = n;
        if(n>0)
            temp = temp;
        else
            temp= -temp;

        while(temp > 0){
            int a=temp & 1;
            if(a == 1){
                ans*=x;
            }
            x= x*x;
            temp = temp>>1;
        }

        if(n < 0)
            return 1/ans;
        else
            return ans;
    }
};