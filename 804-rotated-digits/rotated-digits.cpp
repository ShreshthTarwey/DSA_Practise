class Solution {
public:
    int rotatedDigits(int n) {
        int count = 0;
        for(int i=1;i<=n;i++){
            string str = to_string(i);
            if(str.find('3') != string::npos || str.find('4') != string::npos || str.find('7') != string::npos){
                continue;
            }
            if(str.find('2') == string::npos && str.find('5') == string::npos && str.find('6') == string::npos && str.find('9') == string::npos){
                continue;
            }
            count++;
        }
        return count;
    }
};