class Solution {
public:
    bool checkOnesSegment(string s) {
        int count = 0;
        for(int i=0;i<s.length();i++){
            if(s[i] == '1'){
                count++;
                if(count==2) return false;
                while(i<s.length() && s[i]=='1'){
                    i++;
                }
                i--;
            }
        }
        return true;
    }
};