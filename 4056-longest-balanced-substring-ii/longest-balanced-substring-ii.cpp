class Solution {
public:
    void fun1(string &s, int &ans){
        int n = s.length();
        int maxAns = 1;
        char prev = s[0];
        int count = 1;
        for(int i=1;i<n;i++){
            if(s[i]==prev){
                count++;
                maxAns = max(maxAns, count);
            }
            else{
                prev = s[i];
                count = 1;
            }
        }
        ans = max(ans, maxAns);
    }
    void fun2(string &s, int &ans, char c1, char c2){
        unordered_map<int, int>mp;
        int count1 = 0;
        int count2 = 0;
        int maxAns = INT_MIN;
        for(int i=0;i<s.length();i++){
            if(s[i]==c1){
                count1++;
            }
            else if(s[i]==c2){
                count2++;
            }
            else{
                count1 = 0;
                count2 = 0;
                mp.clear();
            }
            if(count1 == count2){
                maxAns = max(maxAns, count1+count2);
            }
            else if(mp.find(count1-count2)!=mp.end()){
                maxAns = max(maxAns, i-(mp[count1-count2]));
            }
            else{
                mp[count1-count2] = i;
            }
        }
        ans = max(maxAns, ans);
    }
    void fun3(string &s, int &ans){
        unordered_map<string, int>mp;
        int maxAns = 0;
        int count1 = 0;
        int count2 = 0;
        int count3 = 0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='a'){
                count1++;
            }
            if(s[i]=='b'){
                count2++;
            }
            if(s[i]=='c'){
                count3++;
            }
            string temp = "";
            temp += to_string(count1-count2) + ","+ to_string(count1-count3);
            if(count1 == count2 && count1 == count3){
                maxAns = max(maxAns, count1+count2+count3);
            }
            else if(mp.find(temp)!=mp.end()){
                maxAns = max(maxAns, i-mp[temp]);
            }
            else{
                mp[temp] = i;
            }
        }
        ans = max(maxAns, ans);
    }
    int longestBalanced(string s) {
        if(s.length()==1) return 1;
        int ans = 0;
        //Case 1:- Only one repeating character gives the longest answer
        fun1(s, ans);
        //Case 2:- When 2 charaters are giving the long answer
        fun2(s, ans, 'a', 'b');
        fun2(s, ans, 'b', 'c');
        fun2(s, ans, 'c', 'a');
        //Case 3:- When all 3 characters are giving the longest answer
        fun3(s, ans);

        return ans;
    }
};