class Solution {
public:
  int subarraySum(vector<int> &nums, int k) {
    //记录 <前缀和, 该前缀和出现的次数>
    unordered_map<int, int> mp;
    //记录一开始前缀和为0的情况出现了1次
    mp[0] = 1;

    int ans = 0;
    vector<int> preSum(nums.size() + 1, 0);
    for (int i = 0; i < nums.size(); i++) {
      preSum[i + 1] = preSum[i] + nums[i];
      //找目标子段和为k
      int target = preSum[i + 1] - k;
      if (mp.contains(target)) {
        ans += mp[target];
      }
      mp[preSum[i + 1]]++;
    }
    return ans;
  }
};