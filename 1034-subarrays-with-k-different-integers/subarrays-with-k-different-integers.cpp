class Solution {
public:
    int atMost(vector<int>& nums, int k){
        unordered_map<int, int>mp;
        int i=0;
        int j=0;
        int count = 0;
        while(j<nums.size()){
            mp[nums[j]]++;
            if(mp.size()<=k){
                count += (j-i+1);
            }
            else if(mp.size()>k){
                while(i<=j && mp.size()>k){
                    mp[nums[i]]--;
                    if(mp[nums[i]]==0){
                        mp.erase(nums[i]);
                    }
                    i++;
                }
                if(mp.size()<=k){
                    count+=(j-i+1);
                }
            }
            j++;
        }
        return count;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atMost(nums, k) - atMost(nums, k-1);
    }
};