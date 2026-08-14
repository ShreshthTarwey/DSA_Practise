class Solution {
public:
    int maximumLengthSubstring(string s) {
        unordered_map<char, int>mp;
        int i=0;
        int j=0;
        int n = s.length();
        int ans = INT_MIN;
        while(j<n){
            if(mp[s[j]]==2){
                while(i<=j && mp[s[j]] == 2){
                    mp[s[i]]--;
                    i++;
                }
            }
            mp[s[j]]++;
            ans = max(ans, j-i+1);
            j++;
        }
        return ans;
    }
};