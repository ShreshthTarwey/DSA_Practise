class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,double>>cars;
        for(int i=0;i<position.size();i++){
            double time = (double)(target - position[i])/(double)speed[i];
            cars.push_back({position[i], time});
        }
        sort(cars.begin(), cars.end(), greater<>());

        stack<pair<int, double>>st;

        for(int i=0;i<cars.size();i++){
            double time = cars[i].second;
            if(st.empty() || time>st.top().second){
                st.push(cars[i]);
            }
        }
        return st.size();
    }
};