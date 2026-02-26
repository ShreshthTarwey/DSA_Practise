class Solution {
public:
    int bruteForceWrongAnswer(string s){
         long long num = 0;
        long long power = 0;
        for(int i=s.length()-1;i>=0;i--){
            if(s[i] == '1'){
                num += pow(2, power);
            }
            power++;
        }
        int steps = 0;
        while(num!=1){
            if(num%2==0){
                num/=2;
            }
            else{
                num+=1;
            }
            steps++;
        }
        return steps;
    }
    int numSteps(string s) {
        // return bruteForceWrongAnswer(s);
        //Correct solution
        long long num = 0;
        int carry = 0;
        int step = 0;
        for(int i=s.length()-1;i>0;i--){
            int currentBit = (s[i] - '0') + carry;
            if(currentBit == 1){
                step += 2;
                carry = 1;
            }
            else{
                step+=1;
            }
        }
        return step + carry;
    }
};