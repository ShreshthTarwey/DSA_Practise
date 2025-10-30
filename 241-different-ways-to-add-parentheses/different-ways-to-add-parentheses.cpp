class Solution {
public:
    vector<int> diffWaysToCompute(string exp) {
        vector<int> res;
        for (int i = 0; i < exp.length(); i++) {
            if (exp[i] == '+' || exp[i] == '-' || exp[i] == '*') {
                vector<int> left= diffWaysToCompute(exp.substr(0,i));
                vector<int> right = diffWaysToCompute(exp.substr(i+1));
                for(int x: left){
                    for(int y : right){
                        if(exp[i] == '+') res.push_back(x+y);
                        if(exp[i] == '-') res.push_back(x-y);
                        if(exp[i] == '*') res.push_back(x*y);
                    }
                }
            }
        }
        if(res.empty()) res.push_back(stoi(exp));
        return res;
    }
};