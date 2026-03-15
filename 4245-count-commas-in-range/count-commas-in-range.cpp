class Solution {
public:
    int countCommas(int n) {
        int commas = 0;
        for(int i=1;i<=n;i++){
            string num = to_string(i);
            int len = num.length();
            commas += (len-1)/3;
        }
        return commas;
    }
};