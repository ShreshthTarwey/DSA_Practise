class Solution {
public:
    vector<bool> sieveOfErath(int n) {
        vector<bool> isPrime(n + 1, true);
        if (n >= 0) {
            isPrime[0] = false;
        }
        if (n >= 1)
            isPrime[1] = false;

        for (int i = 2; i * i <= n; i++) {
            if (isPrime[i]) {
                for (int j = i * i; j <= n; j += i) {
                    isPrime[j] = false;
                }
            }
        }
        return isPrime;
    }
    int minJumps(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, vector<int>> mp;
        int maxElement = *max_element(nums.begin(), nums.end());
        // Filling the unorderedmap
        for (int i = 0; i < n; i++) {
            mp[nums[i]].push_back(i);
        }
        vector<bool> isPrime = sieveOfErath(maxElement);
        vector<bool> visited(n, false);
        queue<int> q;
        q.push(0);
        visited[0] = true;
        int steps = 0;
        unordered_set<int> seen;
        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                int i = q.front();
                if (i == n - 1) {
                    return steps;
                }
                q.pop();
                if (i - 1 >= 0 && !visited[i - 1]) {
                    q.push(i - 1);
                    visited[i - 1] = true;
                }
                if (i + 1 < n && !visited[i + 1]) {
                    q.push(i + 1);
                    visited[i + 1] = true;
                }

                if (!isPrime[nums[i]]) {
                    continue;
                }

                // Seen wala part
                if (seen.count(nums[i])) {
                    continue;
                }
                seen.insert(nums[i]);
                for (int multiple = nums[i]; multiple <= maxElement;
                     multiple += nums[i]) {
                    if (!mp.contains(multiple)) {
                        continue;
                    }
                    for (int& j : mp[multiple]) {
                        if (!visited[j]) {
                            visited[j] = true;
                            q.push(j);
                        }
                    }
                }
            }
            steps++;
        }
        return steps;
    }
};