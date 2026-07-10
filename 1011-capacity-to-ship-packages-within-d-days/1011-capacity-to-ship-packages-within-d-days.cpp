class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {

    long long start=0,end=0,mid,ans;
        for(int i=0;i<weights.size();i++){
            start=max(start,(long long)weights[i]);
            end=end+weights[i];
        }
        while(start<=end){
            mid=start+(end-start)/2;
            long long pages=0;
            int count=1;
            for(int i=0;i<weights.size();i++){
                pages=pages+weights[i];
                if(pages>mid){
                    count++;
                    pages=weights[i];
                }
            }
            if(count<=days){
                ans=mid;
                end=mid-1;
            }
            else
            start=mid+1;
        }
        return (int)ans;
    }
};