class Solution {
public:
    bool candistr(vector<int>& candies,int mid,long long k){
        long long count=0;
        for(int i=0;i<candies.size();i++){
            count+=candies[i]/mid;
            if(count>=k)
            return true;
        }
        return false;
    }
    int maximumCandies(vector<int>& candies, long long k) {
        long long maxc=0;
        long long total=0;
        for(int i=0;i<candies.size();i++){
            total+=candies[i];
            maxc=max(maxc,(long long)candies[i]);
        }
        if(total<k)
        return 0;
        int start=1;
        int end=maxc;
        int result=0;
        int mid;
        while(start<=end){
        mid=start+(end-start)/2;
        if(candistr(candies,mid,k)){
            result=mid;
            start=mid+1;
        }
        else{
            end=mid-1;
        }
    }
    return result;
    }
};