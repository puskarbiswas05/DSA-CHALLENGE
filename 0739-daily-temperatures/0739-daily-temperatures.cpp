class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& arr) {
         vector<int>ans(arr.size(),0);
        stack<int>st;
        for(int i=0;i<arr.size();i++){
            if(st.size()<0){
                st.push(i);
            }
            else{
                while(st.size()>0 && arr[st.top()]<arr[i]){
                    ans[st.top()]=i-st.top();
                    st.pop();
                }
                st.push(i);
            }
        }
        return ans;
    }
    
};