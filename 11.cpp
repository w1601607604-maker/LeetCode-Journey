class Solution {
public:
  vector<int> maxSlidingWindow(vector<int> &nums, int k) {
    vector<int> result;
    deque<int> dq;

    for (int i = 0; i < nums.size(); i++) {

      //清理队头过期元素
      if (!dq.empty() && dq.front() < i + 1 - k) {
        dq.pop_front();
      }
      //清理队尾数字小于等于新来的
      while (!dq.empty() && nums[i] >= nums[dq.back()]) {
        dq.pop_back();
      }
      dq.push_back(i);
      //形成队列，再把队头（最大）加入结果
      if (i + 1 - k >= 0) {
        result.push_back(nums[dq.front()]);
      }
    }
    return result;
  }
};