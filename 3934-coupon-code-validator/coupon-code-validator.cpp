class Solution {
public:
    bool checkCode(string i){
        if(i.empty()) return false;
        for(char c:i){
            if(!isalnum(c) && c!='_'){
                return false;
            }
        }
        return true;
    }
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        vector<pair<string,string>>result;
        for(int i=0;i<code.size();i++){
            if((checkCode(code[i])) && (businessLine[i]=="electronics" || businessLine[i]=="grocery" || businessLine[i]=="pharmacy" || businessLine[i]=="restaurant") && (isActive[i])){
                result.push_back({businessLine[i],code[i]});
            }
        }
        sort(result.begin(),result.end());
        vector<string>result2;
        for(int i=0;i<result.size();i++){
            result2.push_back(result[i].second);
        }
        return result2;
    }
};