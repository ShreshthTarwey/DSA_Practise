class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int count = 0;
        int i = 0;
        int j = 0;
        int n = s.length();
        string ans = "";
        while(j<n){
            if(s[j] == '1'){
                count++;
            }
            while(count>k || (i<j && s[i] == '0')){
                if(s[i] == '1'){
                    count--;
                }
                i++;
            }
            if(count == k){
                string temp = s.substr(i, j-i+1);
                if(ans == "" || temp.length()<ans.length() || (ans.length() == temp.length() && temp<ans)){
                    ans = temp;
                }
            }
            j++;
        }
        return ans;
    }
};