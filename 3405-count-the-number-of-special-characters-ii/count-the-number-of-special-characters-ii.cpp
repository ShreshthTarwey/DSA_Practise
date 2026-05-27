class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<int>lowerArr(26, -1);
        vector<int>upperArr(26, -1);
        int n = word.length();
        //Last Lowercase
        for(int i=n-1;i>=0;i--){
            char c = word[i];
            if(c>='a' && c<='z' && lowerArr[c-'a']==-1){
                lowerArr[c-'a'] = i;
            }
            else if(c>='A' && c<='Z'){
                upperArr[c-'A'] = i;
            }
        }
        int count = 0;
        for(int i=0;i<26;i++){
            if(lowerArr[i] != -1 && upperArr[i] != -1 && lowerArr[i]<upperArr[i]){
                count++;
            }
        }
        return count;
    }
};