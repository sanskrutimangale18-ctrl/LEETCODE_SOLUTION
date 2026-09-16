class Solution {
public:
    int findComplement(int num) {
        int Count=0, c=0;

        for(int i=30; i>=0; i--){
            int temp= 1 << i;
            int bit= temp & num;
            if(bit == 0)
                Count++;
            else
                break;
        }

        for(int i= 31-Count; i< 32; i++){
            int b= 1<<i;
            c = c | b;
        }

        return ~(c | num);
    }
};