class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<string, int>mp;
        int n = arr1.size();
        int m = arr2.size();
        for(int i=0;i<n;i++){
            string str = to_string(arr1[i]);
            string temp = "";
            for(int j=0;j<str.size();j++){
                temp += str[j];
                mp[temp]++;
            }
        }
        int ans = INT_MIN;
        for(int i=0;i<m;i++){
            string str = to_string(arr2[i]);
            string temp = "";
            for(int j=0;j<str.size();j++){
                temp += str[j];
                if(mp.find(temp) != mp.end()){
                    int len = temp.length();
                    ans = max(ans, len);
                }
            }
        }
        return ans == INT_MIN ? 0 : ans;

    }
};