class Solution {
public:
  void rotate(vector<int> &nums, int k) {
    int n = nums.size();
    k %= n;
    reverse(nums.begin(), nums.end());
    // reverse左闭右开
    reverse(nums.begin(), nums.begin() + k); //交换前k个
    reverse(nums.begin() + k, nums.end());
  }
};