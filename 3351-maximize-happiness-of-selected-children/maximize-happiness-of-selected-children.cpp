class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        int decNum = 0;
        sort(happiness.rbegin(), happiness.rend());
        long long sum = 0;
        int index = 0;
        for(int i=0;i<k;i++){
            if(happiness[index] == 0){
                index++;
                k--;
                continue;
            }
            if(happiness[index]-decNum<=0){
                index++;
                k--;
                continue;
            }
            sum+=happiness[index]-decNum;
            happiness[index] = 0;
            index++;
            decNum++;
        }
        return sum;

    }
};