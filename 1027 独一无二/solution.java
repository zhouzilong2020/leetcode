import java.util.HashMap;

class Solution {
    public boolean uniqueOccurrences(int[] arr) {
        HashMap<Integer, Integer> cnt = new HashMap<>();
        HashMap<Integer, Integer> res = new HashMap<>();

        for (int i = 0, len = arr.length; i < len; i++) {
            if (cnt.containsKey(arr[i])) {
                cnt.put(arr[i], cnt.get(arr[i]) + 1);
            } else {
                cnt.put(arr[i], 1);
            }
        }

        for (HashMap.Entry<Integer, Integer> entry : cnt.entrySet()) {
            if (res.containsKey(entry.getValue())) {
                return false;
            } else {
                res.put(entry.getValue(), 1);
            }
        }
        return true;
    }

    public static void main(String[] args) {
        HashMap<Integer, Integer> result = new HashMap<Integer, Integer>();
        result.put(1, 4);
        result.put(2, 1);
        result.put(3, 5);

    }
}