class Solution {
public:
    int trap(vector<int>& height) {
        int maxh=height[0];
        int index=0;
        for(int i=0;i<height.size();i++){
             if(maxh<height[i]){
                maxh=height[i];
                index=i;
             }
        }
        int maxleft=0,maxright=0,water=0;
        for(int i=0;i<index;i++){
            if(height[i]<maxleft){
                water+=maxleft-height[i];
            }
            else{
                maxleft=height[i];
            }
        }
        for(int i=height.size()-1;i>index;i--){
            if(height[i]<maxright){
                water+=maxright-height[i];
            }
            else{
                maxright=height[i];
            }
        }
        return water;
    }
};