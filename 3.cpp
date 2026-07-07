//不考虑时间复杂度
class Solution {
public:
  int longestConsecutive(vector<int> &nums) {
    if (nums.size() == 0)
      return 0;
    sort(nums.begin(), nums.end());
    int cnt = 1;
    int result = 0;
    for (int i = 1; i < nums.size(); i++) {

      if (nums[i - 1] == nums[i]) {
        continue;
      }
      if (nums[i - 1] == nums[i] - 1) {
        cnt++;

      } else {
        result = max(result, cnt);
        cnt = 1;
      }
    }
    return max(result, cnt);
  }
};

// O（n）
class Solution {
public:
  int longestConsecutive(vector<int> &nums) {
    //利用 vector 的头尾迭代器，调用 unordered_set 的范围构造函数
    unordered_set<int> st(nums.begin(), nums.end());
    int cnt = 1;
    int ans = 0;
    for (int x : st) {
      if (st.contains(x - 1)) {
        continue;
      }
      //找到了以x开始的序列，准备计数
      while (st.contains(++x)) {
        cnt++;
      }
      ans = max(ans, cnt);
      cnt = 1;
    }
    return ans;
  }
};