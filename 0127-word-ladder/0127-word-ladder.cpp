class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string > dist(wordList.begin(),wordList.end());
        if(!dist.count(endWord)) return 0;
        queue<pair<string,int>>q;
        q.push({beginWord,1});
        while(!q.empty())
        {
            string node=q.front().first;
            int step=q.front().second;
            q.pop();

            if(node==endWord)
            return step;

            for(int i=0;i<node.size();i++)
            {
                string temp=node;
                for(char c='a';c<='z';c++)
                {
                    temp[i]=c;
                    if(dist.count(temp))
                    {
                        q.push({temp,step+1});
                        dist.erase(temp);
                    }
                }
            }
        }
        return 0;
    }
};