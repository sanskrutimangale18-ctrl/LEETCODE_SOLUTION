class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        queue<int> q;
        int n = (int)tickets.size();
        for(int i=0 ; i<n; i++){
            q.push(i);
        }

        int count = 0;
        while(tickets[k] != 0){
            count++;
            int temp = q.front();
            tickets[temp]--;
            q.pop();
            if(tickets[temp] > 0){
                q.push(temp);
            }
        }

        return count;
    }
};