class Solution {
public:
    void recFun(vector<string>& ans, int hour, int min, int idx, int turnedOn, vector<int>& times){
        //Base Case
        if(turnedOn<=0){
            if(hour<=11 && min<=59){
                string temp = "";
                temp += to_string(hour) + ":";
                string temp2 = to_string(min);
                if(temp2.length()<=1){
                    temp+= "0"+temp2;
                }
                else{
                    temp+=temp2;
                }
                ans.push_back(temp);
            }
            return;
        }

        for(int i=idx;i<10;i++){
            if(i<=5){
                recFun(ans, hour, min+times[i], i+1, turnedOn-1, times);
            }
            else{
                recFun(ans, hour+times[i], min, i+1, turnedOn-1, times);
            }
        }
    }
    vector<string> readBinaryWatch(int turnedOn) {
        // return {};
        vector<string>ans;
        // string temp = "00:00";
        vector<int>times = {1,2,4,8,16,32,1,2,4,8};
        recFun(ans, 0, 0, 0, turnedOn, times);
        return ans;   
    }
};