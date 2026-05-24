class Solution {
public:
    int recFun(vector<int>& arr, int idx, int d, vector<int>& dp){
        if(idx>=arr.size() || idx<0){
            return 0;
        }
        if(dp[idx] != -1) return dp[idx];
        int n = arr.size();
        int ans = 1;
        for(int i=1;i<=d;i++){
            if(idx+i<n){
                if(arr[idx]>arr[idx+i]){
                    ans = max(ans, 1 + recFun(arr, idx+i, d, dp));
                }
                else{
                    break;
                }
            }
            else{
                break;
            }
        }
        for(int i=1;i<=d;i++){
            if(idx-i>=0){
                if(arr[idx]>arr[idx-i]){
                    ans = max(ans, 1 + recFun(arr, idx-i, d, dp));
                }
                else{
                    break;
                }
            }
            else{
                break;
            }
        }
        return dp[idx] = ans;
    }
    int maxJumps(vector<int>& arr, int d) {
        int ans = INT_MIN;
        vector<int>dp(arr.size(), -1);
        for(int i=0;i<arr.size();i++){
            ans = max(ans, recFun(arr, i, d, dp));
        }
        return ans;
    }
};