class Solution {
public:
    bool judgeCircle(string moves) {
        int i=0;
        int j=0;
        for(auto &it : moves){
            if(it=='U'){
                i-=1;
            }
            else if(it=='D'){
                i+=1;
            }
            else if(it=='L'){
                j-=1;
            }
            else{
                j+=1;
            }
        }
        return (i==0 && j==0);
    }
};