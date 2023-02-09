class Solution {
public:
    string convert(string s, int numRows) {
        // if(numRows==1){
        //     return s;
        // }
        // string res;
        // int cycle=numRows*2-2;
        // for(int i=0;i<s.size();i+=cycle){
        //     res.push_back(s[i]);
        // }
        vector<string>res(numRows,"");
        int i=0;
        int n=s.size();
        while(i<n){
            for(int j=0;j<numRows && i<n;j++){
                res[j].push_back(s[i++]);   
            }
             
            for(int j=numRows-2;j>=1&&i<n;j--){
                res[j].push_back(s[i++]);
            }
        }
        string ans ="";
        for(auto it: res){
            ans+=it;
        }
        return ans;
    }
};



//  this isa good questions
// 6th feb 20203 bh
