class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum1=nums[0];
        int maxsum=nums[0];
        for(int i=1;i<nums.size();i++)
        {
            sum1=max(nums[i],sum1+nums[i]);
            maxsum=max(maxsum,sum1);
        }
        return maxsum;
    }
};