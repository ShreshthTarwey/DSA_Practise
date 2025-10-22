class Solution {
public:
    int simpleGreedy(vector<int>& prices){
        int ans = INT_MIN;
        int minn = INT_MAX;
        for(int i=0;i<prices.size();i++){
            ans = max(ans,prices[i]-minn);
            minn = min(minn,prices[i]);
        }
        return ans>=0 ? ans : 0;
    }
    void recursiveMethod(vector<int>& prices, int &ans, int &minn, int i){
        //Base Case
        if(i==prices.size()){
            return;
        }

        //Akk khud sai krr rhe
        ans = max(ans,prices[i]-minn);
        minn = min(prices[i],minn);
        recursiveMethod(prices,ans,minn,i+1);
    }
    int maxProfit(vector<int>& prices) {
        // using simple greedy approach
        // return simpleGreedy(prices);
        // using dynamic programming



        // //Code  for tabulation
        // int minn = prices[0];
        
        // vector<int>dp(prices.size(),0);
        // // dp[0] = prices[0];
        // for(int i=1;i<prices.size();i++){
        //     dp[i] = max(dp[i-1],prices[i]-minn);
        //     minn = min(minn, prices[i]);
        // }
        // return dp[prices.size()-1];

        //Using Simple recursion ---------------------------------
        int ans = INT_MIN;
        int minn = INT_MAX;
        recursiveMethod(prices,ans,minn,0);
        if(ans<0) return 0;
        return ans;
    }
};