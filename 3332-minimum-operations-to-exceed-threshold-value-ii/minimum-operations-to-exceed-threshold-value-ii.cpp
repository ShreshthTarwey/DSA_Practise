class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int count = 0;
        priority_queue<long long, vector<long long>, greater<long long>>pq;
        for(auto &it : nums){
            pq.push(it);
        }
        while(pq.size()>1){
            if(pq.top()>=k){
                break;
            }
            int x = pq.top();
            pq.pop();
            int y = pq.top();
            pq.pop();
            pq.push(1ll *min(x, y) * 2 + max(x, y));
            count++;
        }
        return count;
    }
};