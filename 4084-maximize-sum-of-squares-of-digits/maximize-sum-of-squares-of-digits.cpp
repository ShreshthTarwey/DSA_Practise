class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        string result = "";
        int count = 0;
        int s = 0;
        for(int i=0;i<num;i++){
            for(int j=9;j>=0;j--){
                if(s+j<=sum){
                    s += j;
                    result += to_string(j);
                    break;
                }
            }
            if(result.size() == num){
                break;
            }
        }
        return s==sum ? result : "";
    }
};