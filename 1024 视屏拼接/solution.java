import java.util.Arrays;
import java.util.Comparator;

public class solution {
  public int videoStitching(int[][] clips, int T) {
    int dp[] = new int[T + 1];
    // 按照开始时间进行排序
    Arrays.sort(clips, new Comparator<int[]>() {
      @Override
      public int compare(int[] o1, int[] o2) {
        if (o1[0] == o2[0]) {
          return o1[1] - o2[1];
        } else {
          return o1[0] - o2[0];
        }
      }
    });
    for (int i = 0, len = clips.length; i < len; i++) {
      for (int j = clips[i][0]; j <= T && j <= clips[i][1]; j++) {
        if (dp[j] < clips[i][1]) {
          dp[j] = clips[i][1];
        }
      }
    }

    int cnt = 0;
    int pos = 0;
    while (pos < T) {
      if (dp[pos] == pos) {
        return -1;
      }
      pos = dp[pos];
      cnt++;
    }
    return cnt;
  }

  public static void main(String[] args) {
    solution s = new solution();
    // int[][] clips = { { 0, 1 }, { 6, 8 }, { 0, 2 }, { 5, 6 }, { 0, 4 }, { 0, 3 }, { 6, 7 }, { 1, 3 }, { 4, 7 },
    //     { 1, 4 }, { 2, 5 }, { 2, 6 }, { 3, 4 }, { 4, 5 }, { 5, 7 }, { 6, 9 } };
    // int T = 9;

    int[][] clips = { { 0, 1 }, { 1, 2 } };
    int T = 5;

    System.out.println(s.videoStitching(clips, T));

  }
}
