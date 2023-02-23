class Solution {
public:
  
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int  n=profits.size();
        int i=0;
        vector<pair<int,int>>v(n);
        for(int i=0;i<n;i++){
            v[i]={profits[i],capital[i]};
        }
        sort(v.begin(),v.end(),[&](pair<int,int> a,pair<int,int> b){ return a.second<b.second;});
        priority_queue<int>pq;
        
        while(k--){
            while(i<n&&w>=v[i].second)
                pq.push(v[i++].first);
            if(!pq.empty()){
                w+=pq.top();
                pq.pop();
            }
        }
        return w;
    }
};
