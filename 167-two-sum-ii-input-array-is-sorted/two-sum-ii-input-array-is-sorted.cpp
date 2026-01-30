class Solution {
public:
    int binarySearch(vector<int>& numbers, int target, int point, int start, int end){
        while(start<=end){
            int mid = start + ((end-start)>>1);
            if(numbers[mid]+point==target){
                return mid;
            }
            else if(numbers[mid]+point>target){
                end = mid-1;
            }
            else{
                start = mid+1;
            }
        }
        return -1;
    }
    vector<int> twoSum(vector<int>& numbers, int target) {
        int sum = 0;
        for(int i=0;i<numbers.size();i++){
            sum = numbers[i];
            int j = numbers.size()-1;
            int point2 = binarySearch(numbers, target, sum, i+1, j);
            if(point2!=-1){
                return {i+1, point2+1};
            }
        }
        return {-1, -1};
    }
};