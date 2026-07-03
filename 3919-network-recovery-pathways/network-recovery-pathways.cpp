class Solution {
public:
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        int n = online.size();
        if (!online[0] || !online[n - 1]) return -1;

        vector<vector<pair<int, int>>> g(n);
        int l = 0, r = 0;

        for (const auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            if (online[u] && online[v]) {
                g[u].push_back({v, w});
                r = max(r, w);
            }
        }

        auto check = [&](int mid) -> bool {
            vector<long long> dis(n, LLONG_MAX);
            priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> q;

            dis[0] = 0;
            q.push({0, 0});

            while (!q.empty()) {
                auto [d, u] = q.top();
                q.pop();

                if (d > k) return false;
                if (u == n - 1) return true;
                if (d > dis[u]) continue;

                for (const auto& [v, w] : g[u]) {
                    if (w >= mid && dis[v] > d + w) {
                        dis[v] = d + w;
                        q.push({dis[v], v});
                    }
                }
            }
            return false;
        };

        int ans = -1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (check(mid)) {
                ans = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return ans;
    }
};