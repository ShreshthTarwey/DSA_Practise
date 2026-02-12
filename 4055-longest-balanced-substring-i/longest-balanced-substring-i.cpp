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
            for(int j=i;j<s.length();j++){
                mp[s[j]]++;
                if(isBalanced(mp)){
                    ans = max(ans, j-i+1);
                }
            }
            mp.clear();
        }
        return ans;
    }
};