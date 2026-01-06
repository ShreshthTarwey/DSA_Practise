class Solution {
public:
    vector<int> solve(string s){
        vector<int>result;
        for(int i=0;i<s.length();i++){
            if(s[i]=='-' || s[i] == '+' || s[i] == '*'){
                vector<int>leftResult = solve(s.substr(0, i));
                vector<int>rightResult = solve(s.substr(i+1));

                for(auto it: leftResult){
                    for(auto jt: rightResult){
                        if(s[i]=='-'){
                            result.push_back(it-jt);
                        }
                        else if(s[i]=='+'){
                            result.push_back(it+jt);
                        }
                        else{
                            result.push_back(it*jt);
                        }
                    }
                }
                
            }
        }
        if(result.empty()){
                    result.push_back(stoi(s));
                }
                return result;
    }
    vector<int> diffWaysToCompute(string expression) {
        return solve(expression);
    }
};