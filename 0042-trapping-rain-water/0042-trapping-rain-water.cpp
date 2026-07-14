class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        int maxleft=0,maxright=0,maxheight=height[0],water=0,index=0;
        for(int i=1;i<n;i++){
           if(height[i]>maxheight){
            maxheight=height[i];
            index=i;
           }
        }
        for(int i=0;i<index;i++){
            if(maxleft>height[i])
            water+=(maxleft-height[i]);
            else
            maxleft=height[i];
        }
        for(int i=n-1;i>index;i--){
            if(maxright>height[i])
            water+=(maxright-height[i]);
            else
            maxright=height[i];
        }
        return water;
    }
};