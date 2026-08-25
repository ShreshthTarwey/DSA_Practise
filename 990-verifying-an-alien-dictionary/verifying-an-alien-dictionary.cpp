class Solution {
public:
    bool check(vector<int>& orderChar, string str1, string str2){
        int i=0;
        int j=0;
        // if(str1.length() > str2.length()){
        //     return false;
        // }
        int n = str1.length();
        int m = str2.length();
        int minLen = min(n, m);
        for(int i=0;i<minLen;i++){
            if(str1[i] != str2[i]){
                if(orderChar[str1[i] - 'a'] > orderChar[str2[i] - 'a']){
                    return false;
                }
                return true;
            }
        }
        return n<=m;
}
    bool isAlienSorted(vector<string>& words, string order) {
        vector<int>orderChar(26, 0);
        for(int i=0;i<order.length();i++){
            orderChar[order[i]-'a'] = i;
        }
        for(int i=0;i<words.size()-1;i++){
            if(!check(orderChar, words[i], words[i+1])){
                return false;
            }
        }
        return true;
    }
};