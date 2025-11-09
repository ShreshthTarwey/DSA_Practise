class Solution {
public:
    bool solve(vector<int>& matchstick, vector<int>& sides, int i){
        //Base Case
        if(i==matchstick.size()){
            return (sides[0] == 0 && sides[1] == 0 && sides[2] == 0 && sides[3] == 0);
        }

        //Trying to fill current index matchstick into all Sides
        bool ans = false;
        for(int j=0;j<sides.size();j++){
            if(matchstick[i]<=sides[j]){
                sides[j]-=matchstick[i];
                ans = ans || solve(matchstick, sides, i+1);
                if(ans == true) return true;
                //Other wise current matchstick was unable to fit in the current side we will try it in next side

                sides[j]+=matchstick[i];

            }
        }
        return ans;
    }
    bool makesquare(vector<int>& matchsticks) {
        if(matchsticks.size()<4) return false;
        auto sum = accumulate(matchsticks.begin(), matchsticks.end(), 0);
        if(sum%4!=0) return false;

        vector<int>sides(4,(sum/4));
        // sorting the matchstick in decreasing order to dogdge the TLE, and reduce RE calls
        sort(matchsticks.rbegin(), matchsticks.rend());
        return solve(matchsticks, sides, 0);

    }
};