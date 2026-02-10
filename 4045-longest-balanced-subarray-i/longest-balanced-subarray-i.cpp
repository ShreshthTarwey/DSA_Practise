class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        unordered_map<int, int>mp;
        int ans = 0;
        int n = nums.size();
        for(int i=0;i<n;i++){
            int oddCount = 0;
            int evenCount = 0;
            for(int j=i;j<n;j++){
                if(mp.find(nums[j])==mp.end()){
                    if((nums[j] & 1) == 0){
                        evenCount++;
                    }
                    else{
                        oddCount++;
                    }
                    mp[nums[j]]++;
                }
                if(evenCount == oddCount){
                    ans = max(ans, j-i+1);
                }
            }
            mp.clear();
        }
        return ans;
    }
};