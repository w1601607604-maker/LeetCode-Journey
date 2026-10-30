class Solution {
public:
  int lengthOfLongestSubstring(string s) {
    unordered_set<char> window;
    int l = 0;
    int r = 0;
    int ans = 0;
    for (; r < s.size(); r++) {
      while (window.contains(s[r])) {
        //去掉左边的字符，更改起始位置
        window.erase(s[l]);
        //缩小窗口长度
        l++;
      }
      //此时窗口内一定没有重复元素，把字符加入哈希表
      window.insert(s[r]);
      ans = max(ans, r - l + 1);
    }
    return ans;
  }
};