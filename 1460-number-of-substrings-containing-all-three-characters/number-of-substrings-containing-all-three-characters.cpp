class Solution {
public:
    bool isValid(vector<int>& freq){
        for(auto &it: freq){
            if(it==0) return false;
        }
        return true;
    }
    int numberOfSubstrings(string s) {
        int l = 0;
        int r = 0;
        vector<int>freq(3, 0);
        int n = s.length();
        int total = 0;
        while(r<s.length()){
            freq[s[r]-'a']++;
            while(isValid(freq)){
                total += n - r;
                freq[s[l]-'a']--;
                l++;
            }
            r++;
        }
        return total;
    }
};