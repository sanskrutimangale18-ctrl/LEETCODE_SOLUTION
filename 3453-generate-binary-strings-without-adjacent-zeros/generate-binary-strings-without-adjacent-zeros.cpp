class Solution {
public:
    void validS(int lastPlace, int n, vector<string>&ans, string ourAns){
        if(n==0){
            ans.push_back(ourAns);
            return;
        }

        if(lastPlace != 0){
            validS(0, n-1, ans, ourAns + '0');
            validS(1, n-1, ans, ourAns + '1');
        }
        else{
            validS(1, n-1, ans, ourAns + '1'); 
        }  
    }

    vector<string> validStrings(int n) {
        vector<string>ans;
        string ourAns = "";
        validS(1, n, ans, ourAns);

        return ans;
    }
};