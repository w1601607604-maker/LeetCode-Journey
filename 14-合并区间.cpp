class Solution {
public:
  vector<vector<int>> merge(vector<vector<int>> &intervals) {
    // 1. 按左端点升序排序
    sort(
        intervals.begin(), intervals.end(),
        [](const vector<int> &a, const vector<int> &b) { return a[0] < b[0]; });

    vector<vector<int>> res;

    for (const auto &cur : intervals) {
      // res 为空，或当前区间和最后一段完全没有交集 → 新开一段
      if (res.empty() || res.back()[1] < cur[0]) {
        res.push_back(cur);
      } else {
        // 有交集（含端点相接）→ 左端点不用动，只把右端点撑大
        res.back()[1] = max(res.back()[1], cur[1]);
      }
    }
    return res;
  }
};