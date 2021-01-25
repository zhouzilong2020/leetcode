
class Solution {
  public int islandPerimeter(int[][] grid) {
    int r = grid.length;
    if (r == 0) {
      return 0;
    }
    int cir = 0;
    for (int i = 0, c = grid[0].length; i < r; i++) {
      for (int j = 0; j < c; j++) {
        if (grid[i][j] != 0) {
          cir += (5 - grid[i][j]);
          if (i + 1 < r && grid[i + 1][j] != 0) {
            grid[i + 1][j] += 2;
          }
          if (j + 1 < c && grid[i][j + 1] != 0) {
            grid[i][j + 1] += 2;
          }
        }
      }
    }
    return cir;
  }

}