class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char>st;
        for(int i=0;i<num.length();i++){
            while(!st.empty() && k && st.top()>num[i]){
                // if(num[i]==0 && st.size()==1) break;
                st.pop();
                k--;
            }
            st.push(num[i]);
        }
        while(k && !st.empty()){
            st.pop();
            k--;
        }
        string res = "";
        while(!st.empty()){
            res+=st.top();
            st.pop();
        }
        reverse(res.begin(), res.end());
        int i=0;
        while(i<res.length() && res[i]=='0'){
            i++;
        }
        res = res.substr(i);
        if(res.empty()) return "0";
        return res;

    }
};