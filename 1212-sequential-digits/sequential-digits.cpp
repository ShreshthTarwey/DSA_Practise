class Solution {
public:
    void recFun(int num, int low, int high, bool limit, vector<int>& result){
        if(num>high){
            return;
        }
        if(num>=low && num<=high){
            result.push_back(num);
        }
        if(limit){
            int digit = num%10;
            if(digit==9){
                return;
            }
            int temp = (10*num) + (digit+1)%10;
            recFun(temp, low, high, true, result);
        }
        else{
            for(int i=1;i<=9;i++){
                recFun(i, low, high, true, result);
            }
        }
    }
    vector<int> sequentialDigits(int low, int high) {
        vector<int>result;
        recFun(0, low, high, false, result);
        sort(result.begin(), result.end());
        return result;
    }
};