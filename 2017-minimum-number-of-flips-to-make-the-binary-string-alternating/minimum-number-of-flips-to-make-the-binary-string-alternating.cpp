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
    int method2(string &s){
        int n = s.length();
        // s = s + s;
        // int m = s.length();
        string opt1 = "";
        string opt2 = "";
        int num = 0;
        for (int i = 0; i < 2*n; i++) {
            opt1 += (num + '0');
            num = (num == 1 ? 0 : 1);
            opt2 += (num + '0');
        }
        int f1 = 0;
        int f2 = 0;
        int i = 0;
        int j = 0;
        int ans = INT_MAX;
        while (j < 2*n) {

            if (s[j%n] != opt1[j])
                f1++;
            if (s[j%n] != opt2[j])
                f2++;

            if (j - i + 1 > n) {
                if (s[i%n] != opt1[i])
                    f1--;
                if (s[i%n] != opt2[i])
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
    int method3(string &s){
        int n = s.length();
        int flip1 = 0;
        int flip2 = 0;
        int i = 0;
        int j = 0;
        int ans = INT_MAX;
        while(j<2*n){
            char expectedChar1 = (j%2==0 ? '0' : '1');
            char expectedChar2 = (j%2==0 ? '1' : '0');
            if(s[j%n] != expectedChar1){
                flip1++;
            }
            if(s[j%n] != expectedChar2){
                flip2++;
            }
            if(j-i+1>n){
                char c1 = (i%2==0 ? '0' : '1');
                char c2 = (i%2==0 ? '1' : '0'); 
                if(s[i%n] != c1){
                    flip1--;
                }
                if(s[i%n] != c2){
                    flip2--;
                }
                i++;
            }
            if(j-i+1 == n){
                ans = min(ans, min(flip1, flip2));
            }
            j++;
        }
        return ans;
    }
    int minFlips(string s) { 
        // return method1(s); //T.C-> O(n), S.C->O(2*n)
        // return method2(s); //T.C-> O(n), S.C->O(n)
        return method3(s); //T.C-> O(n), S.C->O(1)
        
    }
};