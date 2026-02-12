class Solution {
public:
    bool isBalanced(unordered_map<char, int>& mp){
        int num = -1;
        for(auto it: mp){
            if(num ==  -1){
                num = it.second;
            }
            else{
                if(it.second != num){
                    return false;
                }
            }
        }
        return true;

    }
    int longestBalanced(string s) {
        unordered_map<char, int>mp;
        int ans = 0;
        for(int i=0;i<s.length();i++){
            int distinct = 0;
            int maxFreq = 0;
            for(int j=i;j<s.length();j++){
                mp[s[j]]++;
                // if(isBalanced(mp)){
                //     ans = max(ans, j-i+1);
                // } //Optmimzing this thing -------------------------------------------------------
                int len = j-i+1;
                if(mp[s[j]] == 1) distinct++;
                if(maxFreq<mp[s[j]]){
                    maxFreq = mp[s[j]];
                }
                if(len == maxFreq*distinct){
                    ans = max(ans, len);
                }
            }
            mp.clear();
        }
        return ans;
    }
};