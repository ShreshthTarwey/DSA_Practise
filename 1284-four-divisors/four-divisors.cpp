class Solution {
public:
    int isFourDivisor(int num){
        int sum = num + 1;
        int count = 2;
        for(int i=2; i*i<=num;i++){
            if(i*i==num){
                count+=1;
                sum+=i;
                continue;
            }
            if(num%i == 0){
                sum += i;
                sum += (num/i);
                count+=2;
                if(count>4){
                    // cout<<"Ret0 triggered for num"<<num<<" with div"<<i<<endl;
                    return 0;
                }
            }
        }       
        if(count == 4){
            // cout<<num<<" "<<sum<<" ";
            return sum;
        }
        else{
            return 0;
        }

    }
    int sumFourDivisors(vector<int>& nums) {
        int sum = 0;
        for(auto it: nums){
            sum += isFourDivisor(it);
        }
        return sum;
    }
};