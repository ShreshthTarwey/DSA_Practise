class Solution {
public:
    void solve(vector<int>& freq, vector<int>& quantity, int idx, bool &ans){
        //Base Case
        if(idx>=quantity.size()){
            ans = true;
            return;
        }

        for(int i=0;i<freq.size();i++){
            if(freq[i]>=quantity[idx]){
                freq[i]-=quantity[idx];
                solve(freq, quantity, idx+1, ans);
                freq[i]+= quantity[idx]; //Backtracking
            }
            else{
                continue;
            }
        }

    }
    bool solve2(vector<int>& freq, vector<int>& quantity, int idx){
        if(idx==quantity.size()) return true;
        for(int i=0;i<freq.size();i++){
            if(freq[i]>=quantity[idx]){
                freq[i]-= quantity[idx];
                if(solve2(freq, quantity, idx+1)){
                    return true;
                }
                freq[i] += quantity[idx];
            }
        }
        return false;
    }
    bool canDistribute(vector<int>& nums, vector<int>& quantity) {
        // unordered_map<int, int>mp; //not using MAP to reduce TC
        // bool ans = false;
        // for(int i=0;i<nums.size();i++){
        //     mp[nums[i]]++;
        // }
        // sort(quantity.rbegin(), quantity.rend());
        // vector<int>freq;
        // for(auto it:mp){
        //     freq.push_back(it.second);
        // }
        // solve(freq, quantity, 0, ans);
        // return ans;

        // method2--------------------------------
        unordered_map<int, int>mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        vector<int>freq;
        for(auto it:mp){
            freq.push_back(it.second);
        }
        sort(quantity.rbegin(), quantity.rend());
        return solve2(freq,quantity,0);
    }
};