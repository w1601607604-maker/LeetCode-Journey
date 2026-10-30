class Solution {
public:
  int firstMissingPositive(vector<int> &nums) {
    int n = nums.size();

    for (int i = 0; i < n; i++) {
      // nums[i] 是"合法居民"(1..n)，且不在i-1的位置
      while (nums[i] > 0 && nums[i] <= n && nums[i] != nums[nums[i] - 1]) {
        swap(nums[i], nums[nums[i] - 1]);
      }
    }
    for (int i = 0; i < n; i++) {
      if (nums[i] != i + 1)
        return i + 1;
    }

    return n + 1;
  }
};