class Solution {
public:
    string smallestPalindrome(string s) {
        map<char, int>mp;
        string str = "";
        for(char c: s){
            mp[c]++;
        }
        for(auto &it: mp){
            int num = it.second/2;
            char c = it.first;
            int i=0;
            string temp(num, c);
            str += temp;
        }
        string temp = str;
        for(auto &it: mp){
            int num = it.second;
            char c = it.first;
            if(num%2 != 0){
                str += c;
            }
        }
        reverse(temp.begin(), temp.end());
        str += temp;
        return str;

    }
};