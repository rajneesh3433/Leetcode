class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=n*n;
        vector<int> visited(m+1,0);
        vector<int>ans;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                visited[grid[i][j]]++;
                if(visited[grid[i][j]]==2)
                ans.push_back(grid[i][j]);

            }
        }
        for(int i=1;i<=m;i++)
        {
            if(visited[i]==0)
            ans.push_back(i);
        }
        return ans;
    }

};