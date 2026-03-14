class Solution {
public:
    void recFun(string& str, int n, int k, vector<char>& list, int& counter,
                string& res) {
        if (str.length() == n) {
            counter++;
            // arr.push_back(str);
            if (counter == k) {
                res = str;
                // return;
            }
            return;
        }

        for (int i = 0; i < 3; i++) {
            if (!str.empty() && list[i] == str.back()) {
                continue;
            }
            if (counter == k)
                return;
            str.push_back(list[i]);
            recFun(str, n, k, list, counter, res);
            str.pop_back();
        }
    }
    string getHappyString(int n, int k) {
        string str = "";
        string res = "";
        vector<char> list = {'a', 'b', 'c'};
        int counter = 0;
        // vector<string>arr;
        recFun(str, n, k, list, counter, res);
        // if(arr.size()<k) return "";
        // return arr[k-1];
        return res;
    }
};