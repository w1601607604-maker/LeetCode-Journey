class Solution {
public:
  vector<vector<string>> groupAnagrams(vector<string> &strs) {
    unordered_map<string, vector<string>> mp;

    for (const string &s : strs) {
      string key = s;
      sort(key.begin(), key.end());
      mp[key].push_back(s);
    }
    //[] 里面是 first  加上 [] 之后是 second
    //定义一个和second类型相同的数组
    vector<vector<string>> ans;
    for (auto &it : mp) {
      ans.push_back(it.second);
    }
    return ans;
  }
};