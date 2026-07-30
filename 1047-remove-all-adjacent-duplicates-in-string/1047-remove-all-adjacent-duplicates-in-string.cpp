class Solution {
public:
    string removeDuplicates(string &arr){
        stack<char>s;
        for(int i=0;i<arr.size();i++){
            if(s.size()==0)
            s.push(arr[i]);
            else if(s.top()==arr[i])
            s.pop();
            else
            s.push(arr[i]);
        }
        string str;
        while(s.size()>0){
            str.push_back(s.top());
            s.pop();
        }
        reverse(str.begin(),str.end());
        return str;
    }
};