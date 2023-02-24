class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        int mini=INT_MAX;
        int diff=INT_MAX;
        priority_queue<int>pq;// max heap
        for(auto it : nums){
            if(it%2!=0) it*=2;
            mini=min(mini,it);
            pq.push(it);
        }
        while(pq.top()%2==0){
            int val=pq.top(); // max value
            pq.pop();
            diff=min(diff,val-mini); // updating the mini value
            mini=min(mini,val/2);
            pq.push(val/2);
        }
        return min(diff,pq.top()-mini);
    }
};