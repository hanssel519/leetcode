class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int num = nums.size();
        vector<int> square(num);
        int left_pt = 0, right_pt = num-1, sq_pt = num-1;
        int left_sq, right_sq;
        while(left_pt <right_pt){
            left_sq = nums[left_pt]*nums[left_pt];
            right_sq = nums[right_pt]*nums[right_pt];
            if(left_sq >right_sq){
                square[sq_pt] = left_sq;
                left_pt++;
            }else{
                square[sq_pt] = right_sq;
                right_pt--;
            }
            sq_pt--;
        }
        square[sq_pt] =  nums[left_pt]*nums[left_pt];
        return square;
    }
};
