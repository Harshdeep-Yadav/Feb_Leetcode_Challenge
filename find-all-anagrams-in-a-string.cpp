class Solution {
public:
//     bool isAnagram(string a,string b){
//         sort(a.begin(),a.end());
//         for(int i=0;i<a.size();i++){
//             if(a[i]!=b[i])
//                 return false;
//         }
//         return true;
//     }
     
//     vector<int> findAnagrams(string s, string p) {
//         vector<string>v;
//         vector<int>ans;
//         string x="";
//         for(int i=0;i<s.size();i++){
            
//             for(int j=i;j<i+p.size()&& j<s.size();j++){
//                 x+=s[j];
//             }
//                 if(x.size()==p.size()){
//                     v.push_back(x);
//                 }
//                 x="";
            
//         }
//         sort(p.begin(),p.end());
//         for(int i=0;i<v.size();i++){
//             if(isAnagram(v[i],p)){
//                 ans.push_back(i);
//             }
//         }
//         return ans;
//     }
    
    vector<int> findAnagrams(string s, string p) {
    vector<int> ans;
        vector<int> hash(26, 0);
        vector<int> phash(26, 0);
        int window = p.size();
        int len = s.size();
        if(len < window)
        {
            return ans;
        }
        int left = 0,right = 0;
        while(right < window)
        {
            phash[p[right] - 'a'] += 1;
            hash[s[right] - 'a'] += 1;
            right++;
        }
        right -=1;
        while(right < len)
        {
            if(phash == hash)
            {
                ans.push_back(left);
            }
            right+=1;
            if(right != len)
            {
                hash[s[right] - 'a'] += 1;
            }
            hash[s[left] - 'a'] -=1 ;
            left += 1;
        }
        return ans;
    }
};