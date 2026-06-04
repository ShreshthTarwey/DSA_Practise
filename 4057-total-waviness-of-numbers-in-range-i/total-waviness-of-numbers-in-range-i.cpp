class Solution {
public:
    int findWaviness(string &s){
        int score = 0;
        for(int i=1;i<s.length()-1;i++){
            if(i-1<0 || i+1>=s.length()){
                continue;
            }
            if(s[i-1]>s[i] && s[i+1]>s[i]){
                score++;
            }
            else if(s[i-1]<s[i] && s[i+1]<s[i]){
                score++;
            }
        }
        return score;
    }
    int totalWaviness(int num1, int num2) {
        int score = 0;
        for(int i=num1;i<=num2;i++){
            string str = to_string(i);
            score += findWaviness(str);
        }
        return score;
    }
};