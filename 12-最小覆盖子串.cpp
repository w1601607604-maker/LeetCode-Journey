class Solution {
public:
  string minWindow(string s, string t) {
    if (t == "" || s == "" || t.size() > s.size()) {
      return "";
    }
    vector<int> need(128, 0);

    //记录每个字符的需求量
    for (char c : t) {
      need[c]++;
    }
    //记录目标有多少字符
    int need_count = t.size();
    int l = 0;
    int ans_left = -1;
    int ans_right = s.size();
    for (int r = 0; r < s.size(); r++) {
      //先拿到字符看是否符合
      char c = s[r];
      if (need[c] > 0) {
        need_count--;
      }
      need[c]--;
      while (need_count == 0) {
        if (r - l < ans_right - ans_left) {
          ans_left = l;
          ans_right = r;
        }
        char x = s[l];
        if (need[x] == 0) {
          need_count++;
        }
        need[x]++;
        l++;
      }
    }
    return ans_left == -1 ? "" : s.substr(ans_left, ans_right - ans_left + 1);
  }
};