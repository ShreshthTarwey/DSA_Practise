class Solution {
public:
    unordered_map<string, int>dp;
    bool recFun(string &main, unordered_map<string, int>& mp, int L, int R, vector<char>& arr, string futMain){
        //Base Case
        if(main.length() == 1) return true;
        if(dp.count(main) && futMain.empty()) return dp[main];
        if(futMain.length() == main.length()-1){
            return dp[main] = recFun(futMain, mp, 0, 1, arr, "");
        }
        // if(L>=main.length() || R>=main.length()){
        //     return false;
        // }


        // string furMain = "";
        for(int i=0;i<arr.size();i++){



            string temp = "";
            temp+= main[L];
            temp+= main[R];
            temp+=arr[i];
            if(mp.find(temp)!=mp.end()){
                bool result = recFun(main, mp, L+1, R+1, arr, futMain+arr[i]);
                //Backtrack
                if(!result){
                    continue;
                }
                else{
                    return dp[main] = true;
                }
            }
        }
        return dp[main] = false;
    }
    bool pyramidTransition(string bottom, vector<string>& allowed) {
        unordered_map<string, int>mp;
        for(int i=0;i<allowed.size();i++){
            mp[allowed[i]]++;
        }
        vector<char>arr = {'A', 'B', 'C', 'D', 'E', 'F'};
        return recFun(bottom, mp, 0,1, arr,"");

    }
};