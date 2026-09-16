class Solution {
public:
    int countGoodNumbers(long long n) {
        const long long Mod= 1000000007;
        long long even, odd;
        if(n % 2 == 0){
            even = n/2;
            odd = n/2;
        }
        else{
            odd= n/2;
            even= odd +1;
        }

        long long o= 4, e=5;
        long long ans1=1, ans2=1;
        while(even >0){
            int bit= even & 1;
            if( bit == 1){
                ans1= (ans1*e)% Mod;
            }
            even= even >> 1;
            e=(e*e)% Mod;
        }

        while(odd >0){
            int bit= odd & 1;
            if( bit == 1){
                ans2= (ans2*o)% Mod;
            }
            odd= odd >> 1;
            o=(o*o)% Mod;
        }

        long long ans= (ans1*ans2)% Mod;

        return (int)ans;


    }
};