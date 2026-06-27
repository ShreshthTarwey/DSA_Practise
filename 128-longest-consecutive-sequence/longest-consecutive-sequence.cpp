class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>st;
        for(auto &it: nums){
            st.insert(it);
        }
        int ans = 0;
        int count = 0;
        for(auto &it: st){
            if(st.find(it-1)==st.end()){ //It can be starting of sequence
                int num = it;
                while(st.find(num) != st.end()){
                    count++;
                    num++;
                }
                ans = max(ans, count);
            }
            count = 0;
        }
        return ans;
    }
};