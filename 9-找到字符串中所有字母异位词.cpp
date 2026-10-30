class Solution {
public:
  vector<int> findAnagrams(string s, string p) {
    vector<int> result;
    vector<int> cnt_p(26, 0);
    for (char c : p) {
      cnt_p[c - 'a']++;
    }
    vector<int> cnt_s(26, 0);
    for (int r = 0; r < s.size(); r++) {
      int l = r - p.size() + 1;
      cnt_s[s[r] - 'a']++;
      if (l < 0) {
        continue;
      }
      if (cnt_p == cnt_s) {
        result.push_back(l);
      }
      cnt_s[s[l] - 'a']--;
    }
    return result;
  }
};