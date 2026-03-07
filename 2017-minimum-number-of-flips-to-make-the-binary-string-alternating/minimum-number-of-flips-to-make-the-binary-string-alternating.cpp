class Solution {
public:
    int method1(string& s) {
        int n = s.length();
        s = s + s;
        int m = s.length();
        string opt1 = "";
        string opt2 = "";
        int num = 0;
        for (int i = 0; i < m; i++) {
            opt1 += (num + '0');
            num = (num == 1 ? 0 : 1);
            opt2 += (num + '0');
        }
        int f1 = 0;
        int f2 = 0;
        int i = 0;
        int j = 0;
        int ans = INT_MAX;
        while (j < m) {

            if (s[j] != opt1[j])
                f1++;
            if (s[j] != opt2[j])
                f2++;

            if (j - i + 1 > n) {
                if (s[i] != opt1[i])
                    f1--;
                if (s[i] != opt2[i])
                    f2--;
                i++;
            }

            if (j - i + 1 == n) {
                ans = min(ans, min(f1, f2));
            }

            j++;
        }
        return ans <= 0 ? 0 : ans;
    }
    int minFlips(string s) { return method1(s); }
};