class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        int m=matrix[0].size();
        int row,col;
        int start=0,end=n*m-1;
        while(start<=end)
        {
            int mid=start+(end-start)/2;
            row=mid/m;
            col=mid%m;
            if(matrix[row][col]==target)
            return 1;
            else if(matrix[row][col]<target)
            start=mid+1;
            else
            end=mid-1;
        }
        return 0;
    }
};