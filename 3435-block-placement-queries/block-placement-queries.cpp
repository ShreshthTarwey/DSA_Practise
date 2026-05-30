class Solution {
public:
    struct SegTree {
        int n;
        vector<int> tree;

        SegTree(int n) : n(n), tree(4 * n + 4, 0) {}

        void update(int node, int l, int r, int idx, int val) {
            if (l == r) {
                tree[node] = val;
                return;
            }

            int mid = (l + r) >> 1;

            if (idx <= mid)
                update(node * 2, l, mid, idx, val);
            else
                update(node * 2 + 1, mid + 1, r, idx, val);

            tree[node] = max(tree[node * 2], tree[node * 2 + 1]);
        }

        int query(int node, int l, int r, int ql, int qr) {
            if (ql > r || qr < l) return 0;
            if (ql <= l && r <= qr) return tree[node];

            int mid = (l + r) >> 1;

            return max(
                query(node * 2, l, mid, ql, qr),
                query(node * 2 + 1, mid + 1, r, ql, qr)
            );
        }
    };

    vector<bool> getResults(vector<vector<int>>& queries) {
        const int MX = 50000;

        set<int> pos = {0, MX};

        for (auto &q : queries) {
            if (q[0] == 1) pos.insert(q[1]);
        }

        SegTree st(MX + 1);

        int prevPos = 0;
        for (int p : pos) {
            if (p != 0) {
                st.update(1, 0, MX, p, p - prevPos);
            }
            prevPos = p;
        }

        vector<bool> ans;

        for (int i = (int)queries.size() - 1; i >= 0; i--) {
            auto &q = queries[i];

            if (q[0] == 2) {
                int x = q[1];
                int sz = q[2];

                int pre = *prev(pos.upper_bound(x));

                int best = st.query(1, 0, MX, 0, pre);
                best = max(best, x - pre);

                ans.push_back(best >= sz);
            } else {
                int x = q[1];

                auto it = pos.find(x);
                int l = *prev(it);
                int r = *next(it);

                st.update(1, 0, MX, r, r - l);
                st.update(1, 0, MX, x, 0);

                pos.erase(it);
            }
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};