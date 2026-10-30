class Solution {
public:
  void setZeroes(vector<vector<int>> &matrix) {
    int m = matrix.size();    //行数
    int n = matrix[0].size(); //列数

    // 1. 单独记录第一行 / 第一列本身是否含 0
    bool row0 = false, col0 = false;

    for (int i = 0; i < m; ++i) {
      if (matrix[i][0] == 0) {
        col0 = true;
        break;
      }
    }
    for (int i = 0; i < n; ++i) {
      if (matrix[0][i] == 0) {
        row0 = true;
        break;
      }
    }

    // 2. 用第一行 / 第一列作为标记位
    for (int i = 1; i < m; ++i) {
      for (int j = 1; j < n; ++j) {
        if (matrix[i][j] == 0) {
          matrix[i][0] = 0;
          matrix[0][j] = 0;
        }
      }
    }

    // 3. 根据标记清空内部区域（不含第一行第一列）
    for (int i = 1; i < m; ++i) {
      for (int j = 1; j < n; ++j) {
        if (matrix[i][0] == 0 || matrix[0][j] == 0) {
          matrix[i][j] = 0;
        }
      }
    }

    // 4. 最后处理第一行和第一列
    if (row0)
      for (int j = 0; j < n; ++j)
        matrix[0][j] = 0;
    if (col0)
      for (int i = 0; i < m; ++i)
        matrix[i][0] = 0;
  }
};