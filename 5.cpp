class Solution {
public:
  vector<vector<int>> threeSum(vector<int> &nums) {
    vector<vector<int>> result;
    sort(nums.begin(), nums.end());
    //定1挪2
    for (int i = 0; i < nums.size(); i++) {
      int l = i + 1;
      int r = nums.size() - 1;
      if (nums[i] > 0) {
        break;
      }
      if (i > 0 && nums[i] == nums[i - 1]) {
        continue;
      }
      while (l < r) {
        int sum = nums[l] + nums[r] + nums[i];

        if (sum == 0) {
          result.push_back({nums[i], nums[l], nums[r]});
          //在 l和r 向中间移动寻找下一组答案前，必须跳过重复的数字
          //这里前面要加上l < r ，防止在循环内部越界
          //用while而不是if，直接多次判断
          while (l < r && nums[l] == nums[l + 1])
            l++;
          while (l < r && nums[r] == nums[r - 1])
            r--;

          //移动，找下一组
          l++;
          r--;
        } else if (sum < 0) {
          l++;
        } else {
          r--;
        }
      }
    }
    return result;
  }
};