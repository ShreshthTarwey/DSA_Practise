class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        long long MOD = 1000000000+7;
        for(auto it:queries){
            int l = it[0];
            int r = it[1];
            int v = it[3];
            int k = it[2];
            for(int i=l;i<=r;i+=k){
                nums[i] = (1LL*nums[i]*v)%MOD;
            }
        }
        int num = 0;
        for(auto it:nums){
            num = num^it;
        }
        return num;
    }
};