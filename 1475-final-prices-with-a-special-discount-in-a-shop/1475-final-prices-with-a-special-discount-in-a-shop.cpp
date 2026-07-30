class Solution {
public:
    vector<int> finalPrices(vector<int>& arr) {
        
        vector<int> ans=arr;
        stack<int> st;

for (int i = 0; i < arr.size(); i++) {
    if (st.size() == 0) {
        st.push(i);
    } else {
        while (st.size() > 0 && arr[st.top()] >= arr[i]) {
            ans[st.top()] = arr[st.top()]-arr[i];
            st.pop();
        }
        st.push(i);
    }
}

return ans;
    }
};