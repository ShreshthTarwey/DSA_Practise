class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {

        int zero = 0;
        int one = 0;
        int two = 0;

        for (int x : stones) {
            int rem = x % 3;

            if (rem == 0)
                zero++;
            else if (rem == 1)
                one++;
            else
                two++;
        }

        if (zero % 2 == 0) {
            if (one == 0 || two == 0)
                return false;

            return true;
        }

        if (one > two + 2)
            return true;

        if (two > one + 2)
            return true;

        return false;
    }
};