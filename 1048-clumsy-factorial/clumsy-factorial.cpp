class Solution {
public:
    int clumsy(int n) {
        stack<int>s;
        s.push(n);
        n--;
        int op=0;
        while(n>0){
            if(op % 4 == 0){
                s.top()*=n;
            }
            else if(op % 4 == 1)
                s.top()/=n;

            else if(op % 4 == 2)
                s.push(n);
            else{
                s.push(-n);
            } 
            n--, op++; 
        }

        int ans=0;
        while(!(s.empty())){
            ans+=s.top();
            s.pop();
        }

        return ans;
    }
};