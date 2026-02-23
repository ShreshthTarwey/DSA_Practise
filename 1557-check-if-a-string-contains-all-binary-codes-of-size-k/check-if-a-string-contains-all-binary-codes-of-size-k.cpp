class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int target = pow(2,k);
        int i=0;
        int j=0;
        unordered_map<string, int>mp;
        while(j<s.length()){
            if(j-i+1==k){
                mp[s.substr(i, j-i+1)]++;
                i++;j++;
                continue;
            }
            j++;
        }
        return mp.size()>=target;
    }
};