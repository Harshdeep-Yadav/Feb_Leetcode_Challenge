class Solution {
public:
    unordered_map<char,int> mp;
    bool check(string a,string b){
        int n=min(a.size(),b.size());
        for(int i=0;i<n;i++){
            if(mp[a[i]]<mp[b[i]]){
                return true;
            }else if(mp[a[i]]>mp[b[i]]){
                return false;
            }
        }
        if(a.size()>b.size())
            return false;
        return true;
    }
    bool isAlienSorted(vector<string>& words, string order) {
        int n =order.size();
        for(int i=0;i<n;i++){
            mp[order[i]]=i;
        }
        for(int i=0;i<words.size()-1;i++){
            bool res=check(words[i],words[i+1]);
            if(res==false){
                return false;
            }
        }
        return true;
    }   
};