class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> mp1; // Target Map
        unordered_map<char, int> mp2;
        for (auto it : t) {
            mp1[it]++;
        }

        int l = 0;
        int r = 0;
        pair<int, int> p = {-1, -1};

        int minLen = INT_MAX;
        int formed = 0;
        int required = mp1.size();
        while (l < s.length() && r < s.length()) {
            if (mp1.find(s[r]) != mp1.end()) {
                mp2[s[r]]++;
                if(mp2[s[r]] == mp1[s[r]]){
                    formed++;
                }
                if (formed == required) {
                    if (minLen > (r - l + 1)) {
                        p.first = l;
                        p.second = r;
                        minLen = r - l + 1;
                    }
                    while (l <= r && (formed == required)) {
                        if(r-l+1<minLen){
                            p.first = l;
                            p.second = r;
                            minLen = r-l+1;
                        }
                        if(mp1.count(s[l])){
                            mp2[s[l]]--;
                            if(mp2[s[l]]<mp1[s[l]]){
                                formed--;
                            }
                        }
                        l++;
                    }
                    r++;
                    continue;
                }
            }
            r++;
        }
        if (p.first == -1) return "";
        return s.substr(p.first, p.second-p.first+1);
    }
};