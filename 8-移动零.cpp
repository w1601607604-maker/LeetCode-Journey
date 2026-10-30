class Solution {
public:
  void moveZeroes(vector<int> &nums) {
    int l = 0;
    int r = 0;
    int s = nums.size();
    for (; r < s; r++) {
      if (nums[r] != 0) {
        nums[l++] = nums[r];
      }
    }
    for (; l < s; l++) {
      nums[l] = 0;
    }
  }
};