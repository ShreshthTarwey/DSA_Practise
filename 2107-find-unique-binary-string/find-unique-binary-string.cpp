class Solution {
public:
    string solve(unordered_map<string, int>& mp, string str, int n){
        if(str.length()==n){
            if(mp.find(str)==mp.end()){
                return str;
            }
            return "";
        }

        string pick = solve(mp, str+'0', n);
        string notPick = solve(mp, str+'1', n);
        if(pick.empty()) return notPick;
        return pick;
    }
    string findDifferentBinaryString(vector<string>& nums) {
        unordered_map<string, int>mp;
        for(auto it: nums){
            mp[it]++;
        }
        int n = nums[0].length();
        return solve(mp, "", n);
        return "";
    }
};