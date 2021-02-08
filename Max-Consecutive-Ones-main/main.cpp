class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int max = 0, count = 0;
        for (int i = 0; i < nums.size(); i++) {
          if(nums[i] == 1){
            count++;
          }else{
            max = (count > max)?count:max;
            count = 0;
          }
        }
        max = (count > max)?count:max;
        return max;
    }
};
