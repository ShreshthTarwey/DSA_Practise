class Solution {
public:
    vector<int> toggleLightBulbs(vector<int>& bulbs) {
        vector<bool>integers(100, false);
        vector<int>ans;
        for(int i=0;i<bulbs.size();i++){
            integers[bulbs[i]-1] = !integers[bulbs[i]-1];
        }
        for(int i=0;i<100;i++){
            if(integers[i])
                ans.push_back(i+1);
        }
        return ans;
    }
};