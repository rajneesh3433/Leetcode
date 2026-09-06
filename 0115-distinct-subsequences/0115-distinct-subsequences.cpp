class Solution {
public:

    int find(string s,int n,string t,int m,vector<vector<int>>&dp)
    {
        if(m==0)
        return 1;
        if(n==0)
        return 0;

        if(dp[n][m]!=-1)
        return dp[n][m];

        if(s[n-1]!=t[m-1])
        return dp[n][m]=find(s,n-1,t,m,dp);
        else
        return dp[n][m]=find(s,n-1,t,m-1,dp)+find(s,n-1,t,m,dp);
    }
    int numDistinct(string s, string t) {
        int n=s.size();
        int m=t.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return find(s,n,t,m,dp);
    }
};