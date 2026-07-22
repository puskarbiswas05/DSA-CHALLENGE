class Solution {
public:
    string shortestPalindrome(string s) {
        string rev=s;
        string org=s;
        reverse(rev.begin(),rev.end());
        int size=s.size();
        s+='$';
        s+=rev;
        vector<int>lps(s.size(),0);
        int pre=0,suf=1;
        while(suf<s.size()){
            if(s[pre]==s[suf]){
                lps[suf]=pre+1;
                pre++;
                suf++;
            }
            else{
                if(pre==0){
                    lps[suf]=0;
                    suf++;
                }
                else{
                    pre=lps[pre-1];
                }
            }
        }
        return rev.substr(0,size-lps[s.size()-1])+org;
    }
    
};