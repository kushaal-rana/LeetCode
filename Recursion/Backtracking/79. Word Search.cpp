
class Solution
{
public:
    vector<vector<int>> directions = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    bool dfs(int i, int j, int idx, string &word, vector<vector<char>> &board, vector<vector<int>> &visited, int n, int m)
    {
        if (idx == word.size())
            return true;
        if (i < 0 || j < 0 || i >= n || j >= m || visited[i][j] == -1)
            return false;

        if (board[i][j] != word[idx]) // if they match then only we move else return
            return false;
        visited[i][j] = -1;
        for (auto &dir : directions)
        {
            int newX = dir[0] + i;
            int newY = dir[1] + j;
            // if(newX>=0 && newX<n && newY>=0 && newY<m && visited[newX][newY]==0){
            if (dfs(newX, newY, idx + 1, word, board, visited, n, m))
            {
                return true;
            }
            // }
        }
        visited[i][j] = 0;
        return false;
    }
    bool exist(vector<vector<char>> &board, string word)
    {
        int n = board.size();
        int m = board[0].size();
        int idx = 0;
        vector<vector<int>> visited(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (board[i][j] == word[idx] && dfs(i, j, idx, word, board, visited, n, m) == true)
                {
                    return true;
                }
            }
        }
        return false;
    }
};