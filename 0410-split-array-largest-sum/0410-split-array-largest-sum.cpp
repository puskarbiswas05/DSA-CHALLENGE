class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        long long start=0,end=0,mid,ans=0;
        for(int i=0;i<nums.size();i++){
            start=max(start,(long long)nums[i]);
            end+=nums[i];
        }
        while(start<=end){
            mid=start+(end-start)/2;
            long long sum=0;
            int count=1;
            for(int i=0;i<nums.size();i++){
                sum+=nums[i];
                if(sum>mid){
                    count++;
                    sum=nums[i];
                }
            }
            if(count<=k){
                ans=mid;
                end=mid-1;
            }
            else{
                start=mid+1;
            }
        }
        return (int)ans;
    }
};