class Solution {
public:
    pair<int, int> getCoordinates(int x, int n) {
        int row = (n - 1) - (x - 1) / n;
        int col = (x - 1) % n;
        if ((row % 2 == 0 && n % 2 == 0) || (row % 2 != 0 && n % 2 != 0)) {
            col = (n - 1) - col;
        }
        return {row, col};
    }
    int snakesAndLadders(vector<vector<int>>& board) {
        queue<int> q;
        int n = board.size();
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        q.push(1);
        visited[n - 1][0] = true;
        int steps = 0;
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                int node = q.front();
                q.pop();
                if (node == n * n) {
                    return steps;
                }
                for (int k = 1; k <= 6; k++) {
                    int val = node + k;
                    if (val > n * n) {
                        break;
                    }
                    auto p = getCoordinates(val, n);
                    val = board[p.first][p.second] == -1
                              ? val
                              : board[p.first][p.second];
                    if (visited[p.first][p.second])
                        continue;
                    visited[p.first][p.second] = true;
                    q.push(val);
                }
            }
            steps++;
        }
        return -1;
    }
};