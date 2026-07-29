class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char>st;
        stack<char>gt;
        for(int i=0;i<s.size();i++){
            if(s[i]=='#'){
                if(st.size()>0)
                st.pop();
            }
            
            else
            st.push(s[i]);
        }
        for(int i=0;i<t.size();i++){
            if(t[i]=='#'){
                if(gt.size()>0)
                gt.pop();
            }
            else
            gt.push(t[i]);
        }
        if(st==gt)
        return 1;
        else
        return 0;
    }
};