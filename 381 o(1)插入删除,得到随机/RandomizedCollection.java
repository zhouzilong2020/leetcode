import java.util.ArrayList;
import java.util.HashMap;

class RandomizedCollection {
  private HashMap<Integer, Integer> cnt;
  private ArrayList<Integer> out;


  /** Initialize your data structure here. */
  public RandomizedCollection() {
    cnt = new HashMap<>();
    out = new ArrayList<>();

  }

  /**
   * Inserts a value to the collection. Returns true if the collection did not
   * already contain the specified element.
   */
  public boolean insert(int val) {
    out.add(val);

    if (cnt.containsKey(val)) {
      // key already exist
      cnt.put(val, cnt.get(val) + 1);
      return false;
    } else {
      // key does not exist yet
      cnt.put(val, 1);
      return true;
    }

  }

  /**
   * Removes a value from the collection. Returns true if the collection contained
   * the specified element.
   */
  public boolean remove(int val) {
    if (cnt.containsKey(val)) {
      if (cnt.get(val) > 1) {
        out.remove((Object) val);
        // delete one val
        cnt.put(val, cnt.get(val) - 1);
      } else {
        out.remove((Object) val);
        // delete the only one val
        cnt.remove(val);
      }
      return true;
    } else {
      return false;
    }
  }

  /** Get a random element from the collection. */
  public int getRandom() {
    return out.get((int) (Math.random() * out.size()));
  }

  // public static void main(String[] args) {
  // RandomizedCollection a= new RandomizedCollection();
  // a.insert(1);
  // a.insert(10);
  // a.insert(10);
  // a.insert(100);
  // a.getRandom();

  // a.getRandom();

  // a.getRandom();

  // a.getRandom();

  // a.getRandom();

  // }
}

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection obj = new RandomizedCollection(); boolean param_1 =
 * obj.insert(val); boolean param_2 = obj.remove(val); int param_3 =
 * obj.getRandom();
 */