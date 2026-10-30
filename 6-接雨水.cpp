class Solution {
public:
  int trap(vector<int> &height) {
    int ans = 0;
    stack<int> st; //存柱子的下标
    for (int i = 0; i < height.size(); i++) {
      while (!st.empty() && height[i] > height[st.top()]) {
        int bottom = st.top(); //取出底部
        st.pop();              //此时栈顶是左侧
        //检查一遍栈是否为空，防止越界访问
        if (st.empty())
          break;
        int h = min(height[i], height[st.top()]) - height[bottom];
        int l = i - st.top() - 1;
        ans += l * h;
      }

      st.push(i);
    }
    return ans;
  }
};