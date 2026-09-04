class Solution {
public:
    bool valid(int i,int j,int n,int m)
    {
        return i>=0&&i<n&&j>=0&&j<m;
    }
    void dfs(int i,int j,vector<vector<char>>& grid,vector<vector<int>>&visited,int n,int m)
    {
        visited[i][j]=1;
        if(valid(i+1,j,n,m)&&visited[i+1][j]==0&&grid[i+1][j]=='1')
        dfs(i+1,j,grid,visited,n,m);

        if(valid(i,j+1,n,m)&&visited[i][j+1]==0&&grid[i][j+1]=='1')
        dfs(i,j+1,grid,visited,n,m);

        if(valid(i-1,j,n,m)&&visited[i-1][j]==0&&grid[i-1][j]=='1')
        dfs(i-1,j,grid,visited,n,m);

        if(valid(i,j-1,n,m)&&visited[i][j-1]==0&&grid[i][j-1]=='1')
        dfs(i,j-1,grid,visited,n,m);


    }
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>visited(n,vector<int>(m,0));
        int count=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]=='1' && visited[i][j]==0)
                {
                    dfs(i,j,grid,visited,n,m);
                    count++;

                }
               
            }
        }
        return count;
        
    }
};