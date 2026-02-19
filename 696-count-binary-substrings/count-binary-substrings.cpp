class Solution {
public:
    int countBinarySubstrings(string s) {
        vector<int>temp;
        int count = 0;
        for(int i=0;i<s.length();i++){
            if(s[i] == '0'){
                while(i<s.length() && s[i]=='0'){
                    count++;
                    i++;
                }
                i--;
                temp.push_back(count);
                count = 0;
            }
            else{
                while(i<s.length() && s[i]=='1'){
                    count++;
                    i++;
                }
                i--;
                temp.push_back(count);
                count = 0;
            }
        }
        int ans = 0;
        for(int i=0;i<temp.size()-1;i++){
            ans += min(temp[i], temp[i+1]);
        }
        return ans;
    }
};