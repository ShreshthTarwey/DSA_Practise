class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int count = 0;
        int i = 0;
        while(i<strs[0].length()){
            char c = strs[0][i];
            for(int j=0;j<strs.size();j++){
                if(strs[j][i]>=c){
                    c = strs[j][i];
                }
                else{
                    count++;
                    break;
                }
            }
            i++;
        }
        return count;
    }
};