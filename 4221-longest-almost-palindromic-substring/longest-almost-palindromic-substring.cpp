class Solution {
public:
    int expand(string &s, int i, int j, bool hasSkipped){
       //Phase 1:- expanding while valid
        while(i>=0 && j<s.length() && s[i] == s[j]){
            i--; j++;
        }
        int baseLength = j-i-1;
        //Phase 2:- Skipping first char
        int len1 = baseLength;
        if(i>=0){
            len1++;
            int l = i-1;
            int r = j;
            while(l>=0 && r<s.length() && s[l] == s[r]){
                l--; r++;
                len1+=2;
            }
        }

        int len2 = baseLength;
        if(j<s.length()){
            len2++;
            int l = i;
            int r = j+1;
            while(l>=0 && r<s.length() && s[l] == s[r]){
                l--; r++;
                len2+=2;
            }
        }
        return max(len1, len2);
    }
    int almostPalindromic(string s) {
        int ans = 0;
        for(int i=0;i<s.length();i++){
            int left = expand(s, i, i, false);
            int right = expand(s, i, i+1, false);
            ans = max({ans, left, right});
        }
        return ans;
    }
};