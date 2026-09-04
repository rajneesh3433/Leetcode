class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>maxi(n);
        vector<int>mini(n);
        if(n==1)
        {
           return 0;
        }
        maxi[0]=nums[0];
        mini[n-1]=nums[n-1];
        for(int i=1;i<n;i++)
        {
            maxi[i]=max(maxi[i-1],nums[i]);
        }
        for(int j=n-2;j>=0;j--)
        {
            mini[j]=min(mini[j+1],nums[j]);
        }
        int ans=-1;
        for(int i=0;i<n;i++)
        {
            if(maxi[i]-mini[i]<=k)
            {
                ans=i;
                break;
            }
        }
        return ans;
    }
};