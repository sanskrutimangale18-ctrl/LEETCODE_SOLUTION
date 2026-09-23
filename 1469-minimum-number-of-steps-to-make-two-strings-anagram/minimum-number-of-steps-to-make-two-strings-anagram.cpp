class Solution {
public:
    int minSteps(string s, string t) {
        vector<int>freq(26);
        int n= (int)s.size();

        for(int i=0; i<n; i++){
            freq[s[i] - 'a']++;
        }

        int count=0;
        for(int i=0; i<n; i++){

            if(freq[t[i] - 'a'] == 0){
                count++;
            }
            else{
                freq[t[i] - 'a']--;
            }
        }
        return count;
    }
};