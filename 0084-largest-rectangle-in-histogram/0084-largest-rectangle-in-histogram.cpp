class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        vector<int>right(heights.size());
        vector<int>left(heights.size());
        stack<int>st;
        for(int i=0;i<heights.size();i++){
            while(!st.empty() && heights[st.top()]>heights[i]){
                right[st.top()]=i;
                st.pop();
            }
            st.push(i);
        }
        while(st.size()>0){
            right[st.top()]=heights.size();
            st.pop();
        }
        for(int i=heights.size()-1;i>=0;i--){
            while(!st.empty() && heights[st.top()]>heights[i]){
                left[st.top()]=i;
                st.pop();
            }
            st.push(i);
        }
        while(st.size()>0){
            left[st.top()]=-1;
            st.pop();
        }
        int ans=0;
        for(int i=0;i<heights.size();i++){
            ans=max(ans,heights[i]*(right[i]-left[i]-1));
        }
        return ans;
    }
};