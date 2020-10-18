
class Solution {
  public static void main(String[] args) {
    Solution s = new Solution();
    System.out.println(s.totalNQueens(100));
  }




  private  int[] pos; // 位置数组,pos[i] = k 表示第i行的皇后在第k列上. -1表示没有皇后
  private  int n; // 棋盘大小
  private  int cnt;

  public int totalNQueens(int n) {
    // 初始化位置数组
    this.n = n;
    this.pos = new int[n];
    for (int i = n - 1; i >= 0; i--) {
      pos[i] = -1;
    }
    search(0);

    return cnt;
  }

  public void search(int k) {
    if (k == n ) {
      cnt++;
      return;
    }
    // 搜索第k行
    for (int i = 0; i < n; i++) {
      if (isValid(k, i)) {
        pos[k] = i;
        search(k + 1);
        pos[k] = -1;
      }
    }
  }

  public Boolean isValid(int i, int j) {
    for (int k = 0; k< n; k++) {
      if (pos[k] == j) {
        // 同一列
        return false;
      } else {
        if (pos[k] == j + k - i && j + k - i >= 0 && j + k - i < n) {
          // 左上到右下的斜线
          return false;
        } else if (pos[k] == j - k + i && j - k + i >= 0 && j - k + i < n) {
          // 右下到左上的斜线
          return false;
        }
      }
    }
    return true;

  }
  // public static void main(String[] args) {
  // System.out.println("asasdd");
  // }
}