class Solution {
public:
    int slidingWindow(string& s) {
        unordered_map<char, int> map;
        int start = 0;
        int end = 0;
        // int count = 0;
        int maxCount = 0;
        while (end < s.length() && start < s.length()) {
            if (map.find(s[end]) == map.end()) {
                map[s[end]] = end;
                // count++;
            } else {
                start = max(start,map[s[end]] + 1);
                map[s[end]] = end;
            }
            maxCount = max(maxCount, end - start + 1);
            end++;
        }
        return maxCount;
    }
    int slidingWindow2(string &s){
        int i = 0;
        int j = 0;
        int maxLen = 0;
        unordered_map<char,int>mp;
        while(j<s.length()){
            
            if(mp.find(s[j])!=mp.end()){
                while(mp.find(s[j])!=mp.end()){
                    mp[s[i]]--;
                    if(mp[s[i]]==0){
                        mp.erase(s[i]);
                    }
                    i++;
                }
            }
            else{
                mp[s[j]]++;
                j++;
                maxLen = max(maxLen,j-i);
            }
            
        }
        return maxLen;
    }
    int lengthOfLongestSubstring(string s) { 
        return slidingWindow(s); 
        // return slidingWindow2(s);
    }
};