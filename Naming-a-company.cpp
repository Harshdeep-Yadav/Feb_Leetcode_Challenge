
class Solution {
public:
    long long distinctNames(vector<string>& d) {
       unordered_set<string>s(d.begin(),d.end());
       unordered_map<char,unordered_map<char,int>>mp;
        for(auto it : s){
            string st=it;
            char prev=st[0];
            for(char i='a';i<='z';i++){
                st[0]=i;
                if(s.find(st)==s.end())
                    ++mp[i][prev];
            }
        }
        long long ans=0;
        for(auto it: s){
            string st=it;
            char prev=st[0];
             for(char i='a';i<='z';i++){
                 st[0]=i;
                  if(s.find(st)==s.end()){
                      ans+=mp[prev][i];
                  }
             }
        }
        return ans;
    }
};