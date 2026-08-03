class Solution {
public:
    int m, n;

    vector<vector<int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    void DFS(vector<vector<int>>& heights, int i, int j, int prev, vector<vector<bool>>& visited){
        if(i < 0 || i >= m || j < 0 || j >= n || visited[i][j] == true){
            return;
        }

        if(heights[i][j] < prev){
            return; 
        }

        visited[i][j] = true;

        for(vector<int>& dir: directions){
            int new_i = i + dir[0];
            int new_j = j + dir[1];

            DFS(heights, new_i, new_j, heights[i][j], visited);
        }
        
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        m = heights.size();
        n = heights[0].size();

        vector<vector<int>> result;

        vector<vector<bool>> pacificVisited(m, vector<bool>(n, false));
        vector<vector<bool>> atlanticVisited(m, vector<bool>(n, false));

        for(int j=0; j<n; j++){
            DFS(heights, 0, j, INT_MIN, pacificVisited);
            DFS(heights, m-1, j, INT_MIN, atlanticVisited);
        }

        for(int i=0; i<m; i++){
            DFS(heights, i, 0, INT_MIN, pacificVisited);
            DFS(heights, i, n-1, INT_MIN, atlanticVisited);
        }


        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(atlanticVisited[i][j] && pacificVisited[i][j]){
                    result.push_back({i, j});
                }
            }
        }

        return result;
    }
};