class Solution {
public:
    void reverseString(vector<char>& s) {
        stack<char>st;
        for(int i=0;i<s.size();i++){
            st.push(s[i]);
        }
        int i=0;
        while(st.size()>0){
            s[i]=st.top();
            i++;
            st.pop();
        }
        
    }
};