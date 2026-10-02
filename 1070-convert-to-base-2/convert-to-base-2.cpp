class Solution {
public:
    string baseNeg2(int n) {
        if(n == 0){
            return "0";
        }
        int temp = n;
        string str = "";
        while(temp != 0){
            int rem = temp % -2;
            temp = temp /-2;
            if(rem < 0){
                rem += 2;
                temp += 1;
            }
            str += to_string(rem);
        }

        reverse (str.begin(), str.end());
        return str;
        
    }
};