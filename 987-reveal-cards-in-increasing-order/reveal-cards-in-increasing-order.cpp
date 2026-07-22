class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        queue<int>q;
        int i = 0;
        int n = deck.size();
        vector<int>arr = deck;
        sort(arr.begin(), arr.end());
        for(int i=0;i<n;i++){
            q.push(i);
        }
        int index = 0;
        vector<int>ans(n);
        while(!q.empty()){
            int idx = q.front();
            q.pop();
            ans[idx] = arr[index++];
            if(!q.empty()){
                int ele = q.front();
                q.pop();
                q.push(ele);
            }
        }
        return ans;
    }
};