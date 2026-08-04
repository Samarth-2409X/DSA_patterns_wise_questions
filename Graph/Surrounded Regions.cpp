class Solution {
public:
    int m, n;
    
    vector<vector<int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    void dfs(vector<vector<char>>& board, int i, int j, vector<vector<int>>& visited){

        if(i < 0 || i >= m || j < 0 || j >= n || board[i][j] != 'O' || visited[i][j]){
            return;
        }

        visited[i][j] = 1;

        for(auto &dir: directions){
            int new_i = i + dir[0];
            int new_j = j + dir[1];

            dfs(board, new_i, new_j, visited);
        }
    }

    void solve(vector<vector<char>>& board) {
        m = board.size();
        n = board[0].size();

        vector<vector<int>> visited(m, vector<int>(n, 0));

        for(int j=0; j<n; j++){
            if(!visited[0][j] && board[0][j] == 'O'){
                dfs(board, 0, j, visited);
            }

            if(!visited[m-1][j] && board[m-1][j] == 'O'){
                dfs(board, m-1, j, visited);
            }
        }   


        for(int i=0; i<m; i++){
            if(!visited[i][0] && board[i][0] == 'O'){
                dfs(board, i, 0, visited);
            }


            if(!visited[i][n-1] && board[i][n-1] == 'O'){
                dfs(board, i, n-1, visited);
            }
        } 


        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(!visited[i][j] && board[i][j] == 'O'){
                    board[i][j] = 'X';
                }
            }
        }
    }
};