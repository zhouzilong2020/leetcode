class Solution {
  private int r;
  private int c;

  public int[][] updateMatrix(int[][] matrix) {
    r = matrix.length;
    if (r == 0) {
      return matrix;
    }
    c = matrix[0].length;
    for (int i = 0; i < r; i++) {
      for (int j = 0; j < c; j++) {
        if (matrix[i][j] == 1) {
          matrix[i][j] = BFS(matrix, i, j);
        }
      }
    }
    return matrix;
  }

  int BFS(int[][] matrix, int x, int y) {
    for (int dis = 1; dis < r + c; dis++) {
      for (int i = 0, j = dis - i; i <= dis; i++, j--) {
        if (isValid(x + i, y + j) && matrix[x + i][y + j] == 0) {
          return dis;
        } else if (isValid(x + i, y - j) && matrix[x + i][y - j] == 0) {
          return dis;
        } else if (isValid(x - i, y + j) && matrix[x - i][y + j] == 0) {
          return dis;
        } else if (isValid(x - i, y - j) && matrix[x - i][y - j] == 0) {
          return dis;
        }
      }
    }
    return 0;
  }

  boolean isValid(int x, int y) {
    return 0 <= x && x < r && 0 <= y && y < c;
  }

  public static void main(String[] args) {
    Solution s = new Solution();
    int[][] arr = { { 0, 0, 0 }, { 0, 1, 0 }, { 1, 1, 1 } };
    System.out.println(s.updateMatrix(arr));
  }
}