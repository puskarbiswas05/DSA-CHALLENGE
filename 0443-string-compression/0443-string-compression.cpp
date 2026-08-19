class Solution {
public:
    int compress(vector<char>& chars) {
       int idx=0;
       int i=0;
       for(i=0;i<chars.size();i++){
        char ch=chars[i];
        int count =0;
        while(i<chars.size() && chars[i]==ch){
            count++;
            i++;
        }
        if(count==1){
            chars[idx]=ch;
            idx++;
        }
        else{
            chars[idx]=ch;
            idx++;
            string str=to_string(count);
            for(int j=0;j<str.size();j++){
                chars[idx]=str[j];
                idx++;
            }
        }
       
       i--;
       }
       chars.resize(idx);
       return idx;
    }
    
};