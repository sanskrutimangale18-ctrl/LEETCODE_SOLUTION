class Solution {
public:
    int reverse(int x) {
        int sum =0, temp=x;
    while(temp!= 0){
        int digit= temp % 10;
        if(sum < INT_MIN/10 || sum > INT_MAX/10)
            return 0;
        sum=sum*10 + digit ;
        temp/=10;
    }
    return sum;
    }
};