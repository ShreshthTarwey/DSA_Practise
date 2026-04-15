class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int steps = 0;
        int ans = 0;
        int n = words.size();
        //Left to right
        int i=startIndex;
        while(true){
            if(words[i] == target){
                break;
            }
            if(steps == n){
                steps = INT_MAX;
                break;
            }
            steps++;
            i = (i+1)%(n);
        }

        //From right to left
        i = startIndex;
        int steps2 = 0;
          while(true){
            if(words[i] == target){
                break;
            }
            if(steps2 == n){
                steps2 = INT_MAX;
                break;
            }
            steps2++;
            i = (i-1 + n)%(n);
        }
        ans = min(steps, steps2);
        return ans == INT_MAX ? -1: ans;
    }
};