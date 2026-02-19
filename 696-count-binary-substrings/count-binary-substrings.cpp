class Solution {
public:
    int countBinarySubstrings(string s) {
        // vector<int>temp;
        // int count = 0;
        // for(int i=0;i<s.length();i++){
        //     if(s[i] == '0'){
        //         while(i<s.length() && s[i]=='0'){
        //             count++;
        //             i++;
        //         }
        //         i--;
        //         temp.push_back(count);
        //         count = 0;
        //     }
        //     else{
        //         while(i<s.length() && s[i]=='1'){
        //             count++;
        //             i++;
        //         }
        //         i--;
        //         temp.push_back(count);
        //         count = 0;
        //     }
        // }
        // int ans = 0;
        // for(int i=0;i<temp.size()-1;i++){
        //     ans += min(temp[i], temp[i+1]);
        // }
        // return ans;
        int prev = 0;
        int curr = 0;
        int ans = 0;
        for(int i=0;i<s.length();i++){
            if(s[i] == '0'){
                prev = curr;
                curr = 0;
                while(i<s.length() && s[i]=='0'){
                    curr++;
                    i++;
                }
                i--;
                ans += min(prev, curr);
            }
            else{
                prev = curr;
                curr = 0;
                while(i<s.length() && s[i] == '1'){
                    curr++;
                    i++;
                }
                i--;
                ans += min(prev, curr);
            }
        }
        return ans;
    }
};