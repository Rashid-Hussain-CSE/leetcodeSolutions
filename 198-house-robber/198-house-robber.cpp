class Solution {
public:
    int help(vector<int>& nums, int i,vector<int>& dp){
        if(i>=nums.size()) return 0;
        
        if(dp[i]!=-1) return dp[i];
        int ans1 = nums[i] + help(nums,i+2,dp);
        int ans2 = help(nums,i+1,dp);
        return dp[i]=max(ans1,ans2);
    }
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(),-1);
        return help(nums,0,dp);
    }
};