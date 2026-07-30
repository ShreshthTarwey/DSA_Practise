class Solution {
public:
    int minimumPushes(string word) {
        int n = word.length();
        int count = 0;
        int i = 1;
        while(n>0){
            if(n>=8)
                count += (8*i);
            else
                count += (n*i);
            n-=8;
            i++;
        }
        return count;
    }
};