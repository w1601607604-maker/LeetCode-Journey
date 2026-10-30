class Solution {
public:
  vector<int> productExceptSelf(vector<int> &nums) {
    int n = nums.size();
    vector<int> L(n, 1); // L[i] = nums[0..i-1] 的乘积
    vector<int> R(n, 1); // R[i] = nums[i+1..n-1] 的乘积
    vector<int> ans(n, 1);
    for (int i = 1; i < n; i++) {
      L[i] = L[i - 1] * nums[i - 1];
    }
    for (int i = n - 2; i >= 0; i--) {
      R[i] = R[i + 1] * nums[i + 1];
    }
    for (int i = 0; i < n; i++) {
      ans[i] = L[i] * R[i];
    }

    return ans;
  }
};