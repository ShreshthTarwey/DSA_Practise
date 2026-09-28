class Solution {
public:
    int maxDepth(string s) {
        int ans = INT_MIN;
        int count = 0;
        int n = s.length();
        int i = 0;
        while(i<n){
            if(s[i] == '('){
                count++;
            }
            else if(s[i] == ')'){
                count--;
            }
            ans = max(ans, count);
            i++;
        }
        return ans;
    }
};