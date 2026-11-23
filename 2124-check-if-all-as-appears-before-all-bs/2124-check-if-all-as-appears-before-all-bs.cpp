class Solution {
public:
    bool checkString(string s) {
        for(int i=1;i<s.size();i++){
            if(s[i]=='a' && s[i-1]=='b'){
                return 0;
            }
        }
        return 1;
    }
};