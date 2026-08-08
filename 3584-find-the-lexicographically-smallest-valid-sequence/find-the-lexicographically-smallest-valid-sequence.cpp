class Solution {
public:
    vector<int>ans;
    bool recFun(string &word1, string &word2, int i, int j, int k, vector<vector<vector<int>>>& dp){
        if(j==word2.length()) return true;
        if(i==word1.length()) return false;

        if(dp[i][j][k] != -1){
            return dp[i][j][k];
        }
        //Choise 1 ----> Both character matches
        if(word1[i] == word2[j]){
            ans.push_back(i);
            if(recFun(word1, word2, i+1, j+1, k, dp)){
                return dp[i][j][k] = true;
            }
            ans.pop_back();
        }

        //Choise 3 ----> Take i
        if(!k){
            ans.push_back(i);
            if(recFun(word1, word2, i+1, j+1, 1, dp)){
                return dp[i][j][k] = true;
            }
            ans.pop_back();
        }
        //Choise 2-----> Don't Take i

        if(recFun(word1, word2, i+1, j, k, dp)){
            return dp[i][j][k] = true;
        }

        return dp[i][j][k] = false;
    }
    vector<int> dpMemo(string &word1, string &word2){
        vector<vector<vector<int>>>dp(word1.length(), vector<vector<int>>(word2.length(), vector<int>(2, -1)));
        recFun(word1, word2, 0, 0, 0, dp);
        return ans;
    }
    vector<int> validSequence(string word1, string word2) {
        // return dpMemo(word1, word2); //TLE Comes in this method
        //Youtube Solution
        int n = word1.length();
        int m = word2.length();
        int right = 0;
        int i = n-1;
        int j = m-1;
        vector<int>rightSideMatch(n);
        while(i>=0){
            if(j>=0 && word1[i] == word2[j]){
                right++;
                j--;
            }
            rightSideMatch[i] = right;
            i--;
        }

        vector<int>seq;
        bool changePower = true;

        i = 0;
        j = 0;

        while(i<n && j<m){
            if(word1[i] == word2[j]){
                seq.push_back(i);
                j++;
            }
            else if(changePower && i+1<n && rightSideMatch[i+1]>=m-j-1){
                changePower = false;
                seq.push_back(i);
                j++;
            }
            i++;
        }
        return (j==m) ? seq : vector<int>();

    }
};