class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int maxElement = *max_element(costs.begin(), costs.end());
        vector<int>freq(maxElement+1, 0);
        for(auto &it: costs){
            freq[it]++;
        }
        int index = 0;
        int i = 0;
        while(i<freq.size()){
            if(!freq[i]){
                i++;
                continue;
            }
            costs[index++] = i;
            freq[i]--;
        }
        int ans = 0;
        index = 0;
        while(index<costs.size() && coins>=costs[index]){
            ans++;
            coins -= costs[index++];
        }
        return ans;
    }
};