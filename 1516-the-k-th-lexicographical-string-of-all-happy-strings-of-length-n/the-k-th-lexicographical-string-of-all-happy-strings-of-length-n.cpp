class Solution {
public:
    void recFun(string &str, int n, int k, vector<char>& list, int &counter, vector<string>& arr){
        if(str.length()==n){
            counter++;
            arr.push_back(str);
            return;
        }
        if(counter == k) return;
        for(int i=0;i<3;i++){
            if(!str.empty() && list[i] == str.back()){
                continue;
            }
            str.push_back(list[i]);
            recFun(str, n, k, list, counter, arr);
            str.pop_back();
        }
    }
    string getHappyString(int n, int k) {
        string str = "";
        string res = "";
        vector<char>list = {'a', 'b', 'c'};
        int counter = 0;
        vector<string>arr;
        recFun(str, n, k, list, counter, arr);
        if(arr.size()<k) return "";
        return arr[k-1];
    }
};