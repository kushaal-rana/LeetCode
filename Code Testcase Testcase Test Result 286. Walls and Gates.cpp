286. Walls and Gates: You are given an m x n grid rooms initialized with these three possible values.
-1 A wall or an obstacle.
0 A gate.
INF Infinity means an empty room. We use the value 231 - 1 = 2147483647 to represent INF as you may assume that the distance to a gate is less than 2147483647.
Fill each empty room with the distance to its nearest gate. If it is impossible to reach a gate, it should be filled with INF.

Input: rooms = [[2147483647,-1,0,2147483647],[2147483647,2147483647,2147483647,-1],[2147483647,-1,2147483647,-1],[0,-1,2147483647,2147483647]]
Output: [[3,-1,0,1],[2,2,1,-1],[1,-1,2,-1],[0,-1,3,4]]
Example 2:

Input: rooms = [[-1]]
Output: [[-1]]

//Approach: MultiSource BFS:
class Solution {
public: 
      void wallsAndGates(vector<vector<int>> &rooms){
          int n = rooms.size();
        int m = rooms[0].size();
        queue<pair<int,int>> q;

        for(int i=0 ;i<n; i++){
            for(int j=0; j<m; j++){
                if(rooms[i][j] == 0){
                    q.push({i,j});
                }
            }
        }
        vector<vector<int>> dir = {{-1,0}, {0,-1}, {1,0}, {0,1}};
        int distance = 0;
        while(!q.empty()){
            int size = q.size();
            distance++;
            for(int i=0; i<size; i++){
                auto [x,y] = q.front();
                q.pop();
                for(auto d: dir){
                    int newI = x + d[0];
                    int newJ = y + d[1]; 
                    if(newI >=0 && newI<n && newJ>=0 && newJ<m && rooms[newI][newJ] == 2147483647){
                        rooms[newI][newJ] = distance; // or more intutive => rooms[x][y]+1;
                        q.push({newI,newJ});
                    }
                }
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cout<<rooms[i][j] << " ";
            }
            cout<<"\n";
        }
      }
};

