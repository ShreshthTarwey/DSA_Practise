class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        // vector<int>pairXor;
        unordered_set<int>st;
        int n = nums.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                int val = nums[i] ^ nums[j];
                if(!st.contains(val)){
                    st.insert(val);
                }
                // pairXor.push_back(val);
            }
        }
        unordered_map<int, int>mp;
        for(int i=0;i<n;i++){
            for(int j : st){
                int val = j ^ nums[i];
                mp[val]++;
            }
        }
        return mp.size();
    }
};