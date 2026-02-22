class Solution {
public:
    int binaryGap(int n) {
        int num1 = n;
        int left = -1;
        int right = -1;
        int maxAns = -1;
        //Finding first set bit from right
        int index = 0;
        while(num1){
            if((num1&1)){
               if(right==-1){
                right = index;
                left = index;
               }
               else{
                left = index;
                maxAns = max(maxAns, left-right);
                right = index;
               }
            }
            index++;
            num1 = num1>>1;
        }
        return (maxAns==-1 ? 0 : maxAns);
    }
};