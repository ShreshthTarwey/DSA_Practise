class Solution {
public:
    bool checkStrings(string s1, string s2) {
        unordered_map<char, int>mpEven1, mpOdd1, mpEven2, mpOdd2;
        for(int i=0;i<s1.length();i++){
            if(i%2==0){
                mpEven1[s1[i]]++;
                mpEven2[s2[i]]++;
            }
            else{
                mpOdd1[s1[i]]++;
                mpOdd2[s2[i]]++;
            }
        }
        return (mpEven1 == mpEven2 && mpOdd1 == mpOdd2);
    }
};