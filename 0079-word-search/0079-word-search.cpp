class Solution {
public:

    bool valid(int i, int j, int n, int m)
    {
        return i >= 0 && i < n && j >= 0 && j < m;
    }

    bool find(vector<vector<char>>& board,
              string& word,
              int i, int j,
              int index,
              int n, int m)
    {
      
        if(index == word.size())
            return true;

       
        if(!valid(i,j,n,m) || board[i][j] != word[index])
            return false;

        
        board[i][j] = '#';

      
        if(find(board,word,i+1,j,index+1,n,m))
            return true;

        if(find(board,word,i-1,j,index+1,n,m))
            return true;

        if(find(board,word,i,j+1,index+1,n,m))
            return true;

        if(find(board,word,i,j-1,index+1,n,m))
            return true;

       
        board[i][j] = word[index];

        return false;
    }

    bool exist(vector<vector<char>>& board, string word)
    {
        int n = board.size();
        int m = board[0].size();

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(board[i][j] == word[0])
                {
                    if(find(board,word,i,j,0,n,m))
                        return true;
                }
            }
        }

        return false;
    }
};