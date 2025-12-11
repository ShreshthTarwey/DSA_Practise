class Solution {
public:
    int solve(string &a, string &b, int i, int j){
        //Base Case
        if(i>=a.length()){
            return b.length() - j;
        }
        if(j>=b.length()){
            return a.length() - i;
        }

        int ans = 0;

        //match
        if(a[i] == b[j]){
            i++;
            j++;
            ans = solve(a,b,i,j);
        }

        //Not match

        else{
            //insert
            //i wale kai pahale insert krr dia, but i whi rhega
            int option1 = 1 + solve(a,b,i,j+1);
            //remove
            int option2 = 1 + solve(a,b,i+1,j);

            //replace
            int option3 = 1 + solve(a,b,i+1,j+1);

            ans = min(option1,min(option2,option3));
        }
        return ans;

    }
    int minDistance(string word1, string word2) {
        // vector<int>dp(word1.length(), vector<int>(word2.length(), -1));
        // return solve(word1, word2, 0, 0, dp);

        // -------------------------------TSBULSTION-----------------------------------

        int m = word1.length(); int n  = word2.length();
        if(m==0) return n; if(n==0) return m;

        int a[m+1][n+1];
        for(int j=0;j<=n;j++) a[0][j] = j;
        for(int i=0;i<=m;i++) a[i][0] = i;
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(word1[i-1]==word2[j-1]) a[i][j] = a[i-1][j-1];
                else a[i][j] = 1+min(a[i][j-1], min(a[i-1][j] , a[i-1][j-1]));
            }
        }
        return a[m][n];


    }
};