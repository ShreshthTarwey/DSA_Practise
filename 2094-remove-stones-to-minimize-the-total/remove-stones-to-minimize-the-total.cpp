class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int>pq;
        for(auto &it: piles){
            pq.push(it);
        }
        for(int i=0;i<k;i++){
            int x = pq.top() - floor(pq.top()/2.0);
            pq.pop();
            pq.push(x);
        }
        int ans = 0;
        while(pq.size()){
            ans += pq.top();
            pq.pop();
        }
        return ans;
    }
};