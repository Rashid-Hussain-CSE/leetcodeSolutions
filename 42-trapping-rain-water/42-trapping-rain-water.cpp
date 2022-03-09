class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        vector<int> leftMax(n),rightMax(n);
        int lm=0,rm=0;
        for(int i=0;i<n;i++){
            leftMax[i]=lm;
            lm=max(lm,height[i]);
        }
        for(int i=n-1;i>=0;i--){
            rightMax[i]=rm;
            rm=max(rm,height[i]);
        }
        int water=0;
        for(int i=0;i<n;i++){
            if(min(leftMax[i],rightMax[i])>height[i])
                water+=min(leftMax[i],rightMax[i])-height[i];
            //else
                
        }
        return water;
    }
};