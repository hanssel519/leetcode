class Solution {
public:
    int findNumbers(vector<int>& nums) {
      int count = 0, num;
        for (size_t i = 0; i < nums.size(); i++) {
          int digit = 0;
          num = nums[i];
          while (num > 0) {
            digit++;
            num/=10;
            if(num == 0)break;
          }
          if ((digit%2) == 0) {
            count++;
          }
        }
        return count;
    }
};
