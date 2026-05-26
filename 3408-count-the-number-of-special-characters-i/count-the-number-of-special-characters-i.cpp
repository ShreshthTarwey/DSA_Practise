class Solution {
public:
    int numberOfSpecialChars(string word) {
        unordered_map<char, int>mp;
        for(auto &c: word){
            mp[c]++;
        }   
        int count = 0;
        for(auto &c: word){
            if(c>='a' && c<='z'){
                if(mp.find(c-32)!=mp.end()){
                    count++;
                    mp.erase(c);
                    mp.erase(c-32);
                }
            }
            else{
                if(mp.find(c+32) != mp.end()){
                    count++;
                    mp.erase(c);
                    mp.erase(c+32);
                }
            }
        }
        return count;
    }
};