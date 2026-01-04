class Solution {
public:
    bool isPalindrome(string s){
        int i = 0;
        int j = s.length()-1;
        while(i<=j){
            if(s[i]!=s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    int bruteForce(string &s){
        int count = 0;
        for(int i=0;i<s.length();i++){
            for(int j=i;j<s.length();j++){
                if(isPalindrome(s.substr(i, j-i+1))){
                    count++;
                }
            }
        }
        return count;
    }
    int countSubstrings(string s) {
        return bruteForce(s);
    }
};