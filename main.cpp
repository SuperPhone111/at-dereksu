#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
// Google : cplusplus, stackoverflow, geeksforgeeks

#include "includes.h"

using namespace std;

int main(int argc, char **argv) {
  int testID = 31;

  if (argc < 2) {
    printf("use default testID %d\n", testID);
  } else {
    testID = atoi(argv[1]);
  }

  switch (testID) {
  case 0:
    printf("hello world\n");
    break;
  case 1: // binary tree - BF creation
    basic_binaryTree_creation_breathFirst();
    break;
  case 2: // binary tree- DF creation (1D -> tree)
    basic_binaryTree_creation_depthFirst();
    break;
  case 3: // binary tree- DF traversal (tree -> 1D)
    basic_binaryTree_traversal();
    break;
  case 5:
    leetcode_balanced_tree();
    break;
  case 6:
    leetcode_recursive_leafs();
    break;
  case 7:
    leetcode_bt_distanceK();
    break;
  case 8: // recursive, backtracking, caching
    leetcode_fibonacci_seq();
    break;
  case 9:
    leetcode_functionParsing();
    break;
  case 10: // heapify
    basic_heapify();
    break;
  case 11: // heap sort
    basic_heap_sort();
    break;
  case 12:
    leetcode_bt_findKthMin();
    break;
  case 14: // pivot partiion
    basic_pivot_partitioning();
    break;
  case 15: // quick Sort
    basic_quickSort();
    break;
  case 16:
    leetcode_merge_sorted_lists();
    break;
  case 17:
    basic_mergeSort();
    break;
    // digit processing
  case 18: // decimal
    leetcode_revert_integer();
    break;
  case 19:
    leetcode_even_odd_diff();
    break;
  case 20: // binary
    leetcode_bits_resersal();
    break;
  case 22:
    leetcode_check_power_of_two();
    break;
  case 23:
    leetcode_print_decimal_in_binary();
    break;
    // unordered_map, map, unordered_set, set (SKIPPED)
    // recursive example and principles (1-2 example)
  //---  Dynamic Programming ---//
  case 24:
    leetcode_permutation();
    break;
  case 25:
    leetcode_targetSum();
    break;
  //LCS
  //3Sum
    
  //--- LinkedList / Hash Table --- //
  case 30:
    leetcode_prefix_score();
    break;
  case 31:
    leetcode_LRU_cache();
    break;
  //--- Ordering conflict --- //
  case 32:
    leetcode_merge_interval();
    break;
  case 33:
    leetcode_my_calendar();
    break;
  case 34:
    basic_map_usage();
    break;
  //meeting room 3

  //FSM
  case 35:
    leetcode_lonest_substring_without_repeating();
    break;
  //---- tricky question -----
  case 36:
    leetcode_largest_rectangular();
    break;
  //maximum retangle
  

  default:
    printf("not a supported testID %d\n", testID);
    exit(-1);
  }
  // linkedin list / hash table / string processing
  // cache problem
  // FSM
  // dynamic programming
  // ordering conflict
  // tricky problems
}

class CLargestRectangleBase {
public:
  virtual int largestRectangleArea(vector<int>& heights) { return -1; }
};

class CMLargestRectangleDerived : public CLargestRectangleBase {
public:
  int largestRectangleArea(vector<int>& heights) { 
    //TBD
    return -1;
  }
};


void leetcode_largest_rectangular() {
  // https://leetcode.com/problems/largest-rectangle-in-histogram/description/

  CMLargestRectangleDerived solDerived;
  CLargestRectangleBase *sol = &solDerived;

  vector<int> heights({2, 1, 5, 6, 2, 3});
  int area = sol->largestRectangleArea(heights);
  printf("area1 = %d (10)\n", area);

  heights = {2, 4};
  area = sol->largestRectangleArea(heights);
  printf("area2 = %d (4)\n", area);

  heights = {9, 0};
  area = sol->largestRectangleArea(heights);
  printf("area3 = %d(9)\n", area);

  heights = {0, 9};
  area = sol->largestRectangleArea(heights);
  printf("area4 = %d (9)\n", area);

  heights = {2, 1, 2};
  area = sol->largestRectangleArea(heights);
  printf("area5 = %d (3)\n", area);

  heights = {2, 0, 2};
  area = sol->largestRectangleArea(heights);
  printf("area6 = %d (2)\n", area);

  heights = {1, 1};
  area = sol->largestRectangleArea(heights);
  printf("area7 = %d (2)\n", area);
}


int lengthOfLongestSubstring(string s) {
  //TBD
  return -1;
}

void leetcode_lonest_substring_without_repeating()
{
  // https://leetcode.com/problems/longest-substring-without-repeating-characters/description/

  /*
  Given a string s, find the length of the longest 
substring
 without repeating characters.



Example 1:

Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.
Example 2:

Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:

Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.


Constraints:

0 <= s.length <= 5 * 104
s consists of English letters, digits, symbols and spaces.

  */
 string in;

 in = "abcabcbb";
 printf("res= %d (ans: 3)\n", lengthOfLongestSubstring(in));

 in = "bbbbb";
 printf("res= %d (ans: 1)\n", lengthOfLongestSubstring(in));

 in = "pwwkew";
 printf("res= %d (ans: 3)\n", lengthOfLongestSubstring(in));



}



class CSolTargetSumBase {

public:
  virtual int findTargetSumWays(vector<int> &nums, int target) { return -1; }
};

class CSolTargetSum : public CSolTargetSumBase {
  int g_target;
  unordered_map<int, int> memo;
public:
  int findTargetSumWays(vector<int> &nums, int target) {
    // HW1114
    this->g_target = target;
    memo.clear();
    int ans = backtrack(nums, 0, 0);
    return ans;
  }

  int backtrack(vector<int> &nums, int idx, int curr_sum) {
    int hash = (idx << 12) + curr_sum;
    if (memo.count(hash)) {
      return memo[hash];
    }
    if (curr_sum == g_target && idx == nums.size()) {
      return 1;
    } else if (idx >= nums.size()) {
      return 0;
    }

    int res1 = backtrack(nums, idx + 1, curr_sum + nums[idx]);
    int res2 = backtrack(nums, idx + 1, curr_sum - nums[idx]);
    memo[hash] = res1 + res2;
    return memo[hash];
  }
};

void leetcode_targetSum() {

  // HW1114
  //  https://leetcode.com/problems/target-sum/description/

  /*
  You are given an integer array nums and an integer target.

  You want to build an expression out of nums by adding one of the symbols '+'
  and '-' before each integer in nums and then concatenate all the integers.

  For example, if nums = [2, 1], you can add a '+' before 2 and a '-' before 1
  and concatenate them to build the expression "+2-1". Return the number of
  different expressions that you can build, which evaluates to target.



  Example 1:

  Input: nums = [1,1,1,1,1], target = 3
  Output: 5
  Explanation: There are 5 ways to assign symbols to make the sum of nums be
  target 3. -1 + 1 + 1 + 1 + 1 = 3 +1 - 1 + 1 + 1 + 1 = 3 +1 + 1 - 1 + 1 + 1 = 3
  +1 + 1 + 1 - 1 + 1 = 3
  +1 + 1 + 1 + 1 - 1 = 3
  Example 2:

  Input: nums = [1], target = 1
  Output: 1


  Constraints:

  1 <= nums.length <= 20
  0 <= nums[i] <= 1000
  0 <= sum(nums[i]) <= 1000
  -1000 <= target <= 1000
  */
  CSolTargetSum solDerived;
  CSolTargetSumBase *sol;

  sol = &solDerived;

  int res;
  vector<int> nums;
  int target;

  printf("-- case 0 --\n");
  nums = {1, 1, 1, 1, 1};
  target = 3;
  res = sol->findTargetSumWays(nums, target);
  printf("res = %d (ans : 5)\n", res);

  printf("-- case 1 --\n");

  nums = {1, 0};
  target = 1;
  res = sol->findTargetSumWays(nums, target);
  printf("res = %d (ans : 2)\n", res);

  printf("-- case 2 --\n");

  nums = {0, 0, 0, 0, 0, 0, 0, 0, 1};
  target = 1;

  res = sol->findTargetSumWays(nums, target);
  printf("res = %d (and : 256)\n", res);
}

void basic_map_usage() {
  map<int, int> data;

  // start end
  data[10] = 20;
  data[5] = 7;
  data[25] = 30;

  for (auto &ir : data)
    printf("%d %d\n", ir.first, ir.second);
  printf("\n");

  int key = 12;
  auto it = data.lower_bound(key);
  printf("key= %d, (%d, %d)\n", key, it->first, it->second);
  auto preit = prev(it);
  printf("previous key= %d, (%d, %d)\n", key, preit->first, preit->second);

  key = 27;
  it = data.lower_bound(key);
  if (it == data.end()) {
    printf("exceed the last key = %d\n", prev(data.end())->first);
  } else {
    printf("key= %d, (%d, %d)\n", key, it->first, it->second);
  }

  key = 2;
  it = data.lower_bound(key);
  if (it == data.end()) {
    printf("exceed the last key = %d\n", prev(data.end())->first);
  } else {
    printf("key= %d, (%d, %d)\n", key, it->first, it->second);
  }
}

class MyCalendarBase {
public:
  virtual bool book(int start, int end) {
    printf("need implementation\n");
    return false;
  }
};

class MyCalendar : public MyCalendarBase {
  map<int, int> events;

public:
  bool book(int start, int end) {
    // HW1103
    // suggested : std::map<> :: lower_bound(key)
    // https://www.geeksforgeeks.org/map-lower_bound-function-in-c-stl/
    auto nextEvent = events.lower_bound(start);
    if (nextEvent != events.end() && nextEvent->first < end) {
      return false;
    }
    if (nextEvent != events.begin() && prev(nextEvent)->second > start) {
      return false;
    }
    events[start] = end;
    return true;
  }
};

void leetcode_my_calendar() {
  //
  //  https://leetcode.com/problems/my-calendar-i/description/
  //
  /*
  You are implementing a program to use as your calendar. We can add a new event
if adding the event will not cause a double booking.

  The event can be represented as a pair of integers start and end that
represents a booking on the half-open interval [start, end), the range of real
numbers x such that start <= x < end.

  Implement the MyCalendar class:

  - MyCalendar() Initializes the calendar object.
  - boolean book(int start, int end) Returns true if the event can be added to
the calendar successfully without causing a double booking. Otherwise, return
false and do not add the event to the calendar.

Input
["MyCalendar", "book", "book", "book"]
[[], [10, 20], [15, 25], [20, 30]]
Output
[null, true, false, true]

Explanation
MyCalendar myCalendar = new MyCalendar();
myCalendar.book(10, 20); // return True
myCalendar.book(15, 25); // return False, It can not be booked because time 15
is already booked by another event. myCalendar.book(20, 30); // return True, The
event can be booked, as the first event takes every time less than 20, but not
including 20.

Constraints:

0 <= start < end <= 10^9
At most 1000 calls will be made to book.

  */
  MyCalendar objDerived;

  MyCalendarBase *obj = nullptr;

  obj = &objDerived;

  bool booked;
  int start, end;

  start = 10;
  end = 20;
  booked = obj->book(start, end);
  printf("[%d, %d) => %s", start, end, booked ? "true" : "false");
  printf(" (ans = true)\n");

  start = 15;
  end = 25;
  booked = obj->book(start, end);
  printf("[%d, %d) => %s", start, end, booked ? "true" : "false");
  printf(" (ans = false)\n");

  start = 20;
  end = 30;
  booked = obj->book(start, end);
  printf("[%d, %d) => %s", start, end, booked ? "true" : "false");
  printf(" (ans = true)\n");
}

class CMergeIntervalBase {
public:
  virtual vector<vector<int>> merge(vector<vector<int>> &intervals) {
    vector<vector<int>> merged;
    printf("please derive your implementation from CmergeIntervalBase \n");
    return merged;
  }
};

class CMergeInterval : public CMergeIntervalBase {
  vector<vector<int>> merge(vector<vector<int>> &intervals) {
    vector<vector<int>> merged;
    // HW1103 (optional) -
    // HW1114 (debug)
    for (auto &ir : intervals) {
      if (merged.empty() || merged.back()[1] < ir[0]) {
        merged.push_back(ir);
      } else {
        merged.back()[1] = max(merged.back()[1], ir[1]);
      }
    }
    return merged;
  }
};

void leetcode_merge_interval() {
  /*

  https://leetcode.com/problems/merge-intervals/description/

  Given an array of intervals where intervals[i] = [starti, endi], merge all
  overlapping intervals, and return an array of the non-overlapping intervals
  that cover all the intervals in the input.


  Example 1:

  Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
  Output: [[1,6],[8,10],[15,18]]
  Explanation: Since intervals [1,3] and [2,6] overlap, merge them into [1,6].
  Example 2:

  Input: intervals = [[1,4],[4,5]]
  Output: [[1,5]]
  Explanation: Intervals [1,4] and [4,5] are considered overlapping.


  Constraints:

  1 <= intervals.length <= 10^4
  intervals[i].length == 2
  0 <= starti <= endi <= 10^4

  */

  CMergeInterval objDerived;
  CMergeIntervalBase *obj;

  obj = &objDerived; // O(NlogN)

  vector<vector<int>> intervals;
  vector<vector<int>> mergedIntervals;
  intervals.push_back({1, 3});
  intervals.push_back({8, 10});
  intervals.push_back({2, 6});
  intervals.push_back({15, 18});

  printf("== case 1: before merge ==\n");
  for (auto &ir : intervals) {
    printf("[%d, %d] ", ir[0], ir[1]);
  }
  printf("\n");
  mergedIntervals = obj->merge(intervals);

  printf("== after merge ==\n");
  for (auto &ir : mergedIntervals) {
    printf("[%d, %d] ", ir[0], ir[1]);
  }
  printf("\n");
  printf("=>ans: [1, 6] [8, 10], [15, 18]\n\n\n");

  printf("== case 2: before merge ==\n");
  intervals.clear();
  intervals.push_back({1, 4});
  intervals.push_back({4, 5});
  for (auto &ir : intervals) {
    printf("[%d, %d] ", ir[0], ir[1]);
  }
  printf("\n");
  mergedIntervals = obj->merge(intervals);

  printf("== after merge ==\n");
  for (auto &ir : mergedIntervals) {
    printf("[%d, %d] ", ir[0], ir[1]);
  }
  printf("\n");
  printf("=>ans: [1, 5]\n\n\n");

  printf("== case 3: before merge ==\n");
  intervals.clear();
  intervals.push_back({1, 4});
  intervals.push_back({2, 3});

  for (auto &ir : intervals) {
    printf("[%d, %d] ", ir[0], ir[1]);
  }
  printf("\n");
  mergedIntervals = obj->merge(intervals);

  printf("== after merge ==\n");
  for (auto &ir : mergedIntervals) {
    printf("[%d, %d] ", ir[0], ir[1]);
  }
  printf("\n");
  printf("=>ans: [1, 4]\n\n\n");

  printf("== case 4: before merge ==\n");
  intervals.clear();
  intervals.push_back({1, 4});
  intervals.push_back({0, 2});
  intervals.push_back({3, 5});

  for (auto &ir : intervals) {
    printf("[%d, %d] ", ir[0], ir[1]);
  }
  printf("\n");
  mergedIntervals = obj->merge(intervals);

  printf("== after merge ==\n");
  for (auto &ir : mergedIntervals) {
    printf("[%d, %d] ", ir[0], ir[1]);
  }
  printf("\n");
  printf("=>ans: [0, 5]\n\n\n");

  printf("== case 5: before merge ==\n");
  intervals.clear();
  intervals.push_back({2, 3});
  intervals.push_back({5, 5});
  intervals.push_back({2, 2});
  intervals.push_back({3, 4});
  intervals.push_back({3, 4});

  for (auto &ir : intervals) {
    printf("[%d, %d] ", ir[0], ir[1]);
  }
  printf("\n");
  mergedIntervals = obj->merge(intervals);

  printf("== after merge ==\n");
  for (auto &ir : mergedIntervals) {
    printf("[%d, %d] ", ir[0], ir[1]);
  }
  printf("\n");
  printf("=>ans: [2, 4], [5, 5]\n\n\n");

  printf("== case 6: before merge ==\n");
  intervals.clear();
  intervals.push_back({1, 4});
  intervals.push_back({0, 4});

  for (auto &ir : intervals) {
    printf("[%d, %d] ", ir[0], ir[1]);
  }
  printf("\n");
  mergedIntervals = obj->merge(intervals);

  printf("== after merge ==\n");
  for (auto &ir : mergedIntervals) {
    printf("[%d, %d] ", ir[0], ir[1]);
  }
  printf("\n");
  printf("=>ans: [0, 4]\n\n\n");
}

class LRUCacheBase {
public:
  virtual int get(int key) { return -1; }
  virtual void put(int key, int value) {}
  virtual void reset(int cap) {}
};

class DoublyLinkedListNode {
public:
  int key;
  int value;
  DoublyLinkedListNode *prev;
  DoublyLinkedListNode *next;

  DoublyLinkedListNode(int key, int value) {
    this->key = key;
    this->value = value;
    this->prev = nullptr;
    this->next = nullptr;
  }

  void removeBindings() {
    if (this->prev != nullptr) {
      this->prev->next = this->next;
    }
    if (this->next != nullptr) {
      this->next->prev = this->prev;
    }
    this->next = nullptr;
    this->prev = nullptr;
  }
};

class DoublyLinkedList {
public:
  DoublyLinkedListNode *head;
  DoublyLinkedListNode *tail;

  DoublyLinkedList() {
    this->head = nullptr;
    this->tail = nullptr;
  }

  void setHead(DoublyLinkedListNode *node) {
    if (this->head == node) {
      return;
    } else if (this->head == nullptr) {
      this->head = node;
      this->tail = node;
    } else if (this->head == this->tail) {
      this->tail->prev = node;
      this->head = node;
      this->head->next = this->tail;
    } else {
      if (this->tail == node) {
        this->removeTail();
      }
      node->removeBindings();
      this->head->prev = node;
      node->next = this->head;
      this->head = node;
    }
  }

  void removeTail() {
    if (this->tail == nullptr) {
      return;
    }
    if (this->tail == this->head) {
      this->head = nullptr;
      this->tail = nullptr;
      return;
    }
    this->tail = this->tail->prev;
    this->tail->next = nullptr;
  }
};

class LRUCache : public LRUCacheBase {
public:
  unordered_map<int, DoublyLinkedListNode *> cache;
  int maxSize;
  int currentSize;
  DoublyLinkedList listOfMostRecent;

  LRUCache(int cap) { reset(cap); }

  int get(int key) {
    // HW1103
    if (this->cache.find(key) == this->cache.end()) {
      return -1;
    }
    this->updateMostRecent(this->cache[key]);
    return this->cache[key]->value;
  }
  void put(int key, int value) {
    // HW1103
    if (this->cache.find(key) == this->cache.end()) {
      if (this->currentSize == this->maxSize) {
        this->evictLeastRecent();
      } else {
        this->currentSize++;
      }
      this->cache[key] = new DoublyLinkedListNode(key, value);
    } else {
      this->replaceKey(key, value);
    }
    this->updateMostRecent(this->cache[key]);
  }
  void reset(int cap) {
    // HW1103
    this->maxSize = cap > 1 ? cap : 1;
    this->currentSize = 0;
    this->listOfMostRecent = DoublyLinkedList();
  }

private:
  void updateMostRecent(DoublyLinkedListNode *node) {
    this->listOfMostRecent.setHead(node);
  }
  void evictLeastRecent() {
    int keyToRemove = this->listOfMostRecent.tail->key;
    this->listOfMostRecent.removeTail();
    this->cache.erase(keyToRemove);
  }
  void replaceKey(int key, int value) {
    if (this->cache.find(key) == this->cache.end()) {
      return;
    }
    this->cache[key]->value = value;
  }
};

class LRUCacheVK : public LRUCacheBase {
public:
  LRUCacheVK(int cap) { reset(cap); }
  int get(int key) {
    // if key exists
    //     //append w/ key
    //     //remove data w /idx
    // otherwise, return -1

    if (idxMap.find(key) == idxMap.end())
      return -1;

    int idx = idxMap[key];
    int val = data[idx].second;

    append(key, val);
    erase(idx);
    return val;
  }

  void append(int key, int value) {
    data.push_back(make_pair(key, value));
    int MRUidx = data.size() - 1;
    nextMap[MRUidx - 1] = MRUidx;
    prevMap[MRUidx] = MRUidx - 1;
    idxMap[key] = MRUidx;
  }
  void erase(int idx) {
    // clear data[idx]
    int prevIdx = prevMap[idx];
    int nextIdx = nextMap[idx];
    nextMap[prevIdx] = nextIdx;
    prevMap[nextIdx] = prevIdx;
    if (idx == LRUidx) {
      LRUidx = nextMap[idx];
      prevMap.erase(prevMap.find(idx));
      nextMap.erase(nextMap.find(idx));
    }
  }

  void put(int key, int value) {
    /*
     if key exist
        idx = idxMap[key]

        //append data w/ key
        //  next -> _____
        //  prev <-| MRU |
        //
        append (key, val) to data
        MRUidx = data.size()-1
        next[MRUidx-1] = MRUidx
        prev[MRUidx] = MRUidx -1
        update idxMap to MRUidx

        //remove data @idx
        celar data[idx]
        prevIdx = prevMap[idx], nextIdx= nextMap[idx]
        nextMap[prevIdx] = nextIdx
        prevMap[nextIdx] = prevIdx

        if idx == LRUidx
          update LRUidx = nextMap[idx]

        =>remove prevMap[idx], nextMap[idx]


     otherwise, // key ! exist
        //append data w/ key
        //check capacity
        fullness++
        if fullness > capacity
           update LRUidx = nextMap[LRUidx]
           => remove data@LRUidx, idMap[LRUidx]
           fullness--

    */
    if (idxMap.find(key) != idxMap.end()) {
      int idx = idxMap[key];
      append(key, value);
      erase(idx);
    } else {
      append(key, value);
      fullness++;
      if (fullness > capacity) {
        idxMap.erase(data[LRUidx].first);
        erase(LRUidx);
        fullness--;
      }
    }
  }

  void reset(int cap) {
    capacity = cap;
    fullness = 0;

    data.clear();
    idxMap.clear();
    prevMap.clear();
    nextMap.clear();

    prevMap[0] = -1;
    nextMap[-1] = 0;

    LRUidx = 0;
  }

private:
  int capacity;
  int fullness;
  int LRUidx; // idx@data, idx is LRU

  vector<pair<int, int>> data;     // <key, value>
  unordered_map<int, int> idxMap;  // <key, idx @ data>
  unordered_map<int, int> prevMap; // <idx @ data, previous idx @data>
  unordered_map<int, int> nextMap; // <idx @ data, next idx@ data>
};

/*
capcity = 3

data<1, 1> <- LRU, MRU

===
data<1, 1> <- LRU,
data<2, 2> <-- MRU

===
data<1, 1> <- LRU,
data<2, 2>
data<3, 3> <-- MRU

===
data<1, 1> X
data<2, 2> <- LRU
data<3, 3>
data<4, 4> <-- MRU

==
get(1) = -1
==
get(2)?

data<1, 1> X
data<2, 2> X
data<3, 3> <- LRU
data<4, 4>
data<2, 2> <- MRU
===
get(4)?

data<1, 1> X
data<2, 2> X
data<3, 3> <- LRU
data<4, 4> X
data<2, 2>
data<4, 4> <- MRU

===
put(2, 5)

data<1, 1> X
data<2, 2> X
data<3, 3> <- LRU
data<4, 4> X
data<2, 2> X
data<4, 4>
data<2, 5> <- MRU

===
get (3)

data<1, 1> X
data<2, 2> X
data<3, 3> X
data<4, 4> X
data<2, 2> X
data<4, 4> <- LRU
data<2, 5>
data<3, 3> <- MRU



*/

void leetcode_LRU_cache() {
  /*

  https://leetcode.com/problems/lru-cache/description/

  Design a data structure that follows the constraints of a Least Recently Used
  (LRU) cache.

  Implement the LRUCache class:

  LRUCache(int capacity) Initialize the LRU cache with positive size capacity.
  int get(int key) Return the value of the key if the key exists, otherwise
  return -1. void put(int key, int value) Update the value of the key if the key
  exists. Otherwise, add the key-value pair to the cache. If the number of keys
  exceeds the capacity from this operation, evict the least recently used key.
  The functions get and put must each run in O(1) average time complexity.



  Example 1:

  Input
  ["LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"]
  [[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]
  Output
  [null, null, null, 1, null, -1, null, -1, 3, 4]

  Explanation
  LRUCache lRUCache = new LRUCache(2);
  lRUCache.put(1, 1); // cache is {1=1}
  lRUCache.put(2, 2); // cache is {1=1, 2=2} (2)
  lRUCache.get(1);    // return 1 (1)
  lRUCache.put(3, 3); // LRU key was 2, evicts key 2, cache is {1=1, 3=3} (3)
  lRUCache.get(2);    // returns -1 (not found)
  lRUCache.put(4, 4); // LRU key was 1, evicts key 1, cache is {4=4, 3=3} (4)
  lRUCache.get(1);    // return -1 (not found)
  lRUCache.get(3);    // return 3 (3)
  lRUCache.get(4);    // return 4 (4)


  Constraints:

  1 <= capacity <= 3000
  0 <= key <= 10^4
  0 <= value <= 10^5
  At most 2 * 10^5 calls will be made to get and put.

  */

  LRUCache objOOne(2);
  LRUCacheVK objVK(2);
  LRUCacheBase *obj;

  enum IMPLT_ID_ {
    IMPLT_OONE = 0, // O(1)
    IMPLT_LUT,      // O(1)
  };

  int impltID = IMPLT_LUT;
  if (impltID == IMPLT_OONE) {
    obj = &objOOne;
  } else if (impltID == IMPLT_LUT) {
    obj = &objVK;
  } else {
    printf("not a supported implementation");
    exit(-1);
  }
  int val, key;

  printf("------- test case 0 ---------\n");

  obj->put(1, 1);
  obj->put(2, 2);

  key = 1;
  val = obj->get(key);
  printf("get key= %d, val = %d (ans: 1)\n", key, val);

  obj->put(3, 3);

  key = 2;
  val = obj->get(key);
  printf("get key= %d, val = %d (ans: -1)\n", key, val);

  obj->put(4, 4);

  key = 1;
  val = obj->get(key);
  printf("get key= %d, val = %d (ans: -1)\n", key, val);

  key = 3;
  val = obj->get(key);
  printf("get key= %d, val = %d (ans: 3)\n", key, val);

  key = 4;
  val = obj->get(key);
  printf("get key= %d, val = %d (ans: 4)\n", key, val);

  printf("------- test case 1 ---------\n");
  obj->reset(2);

  key = 2;
  val = obj->get(key);
  printf("get key= %d, val = %d (ans: -1)\n", key, val);

  obj->put(2, 6);

  key = 1;
  val = obj->get(key);
  printf("get key= %d, val = %d (ans: -1)\n", key, val);

  obj->put(1, 5);
  obj->put(1, 2);

  key = 1;
  val = obj->get(key);
  printf("get key= %d, val = %d (ans: 2)\n", key, val);

  key = 2;
  val = obj->get(key);
  printf("get key= %d, val = %d (ans: 6)\n", key, val);
}
struct STreeNode {
  int val;
  STreeNode *left;
  STreeNode *right;

  STreeNode() : val(0), left(nullptr), right(nullptr) {}
  STreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
// BT : complete, balanced tree
//    balanced : diff between depth of left tree and depth of right tree <= 1
//    complete : log( number of nodes) == maximum depth no
//          For example: data size = 6 , log(6) = 2.x
//               7     d= 0
//              / \
//             9   1   d= 1
//            / \    \
//           5   4    2  d= 2

void printNodes(vector<STreeNode> &nodes) {
  for (auto &ir : nodes) {
    printf("val=%d ", ir.val);
    if (ir.left)
      printf("left = %d ", ir.left->val);
    else
      printf("left = null ");

    if (ir.right)
      printf("right = %d ", ir.right->val);
    else
      printf("right = null ");

    printf("\n");
  }
  printf("\n");
}

void heapifyMaxHeap(vector<int> &vecData, int rootIdx) {
  // exception

  // general :
  //  f(parent):
  //  if parent is the max node => end
  //  otherwise :  swap parent and max node => f(max node)

  // shift down
  int maxIdx = rootIdx;
  // compare w/ left
  int childIdx = 2 * rootIdx + 1;
  if (childIdx < vecData.size()) {
    if (vecData[childIdx] > vecData[maxIdx]) {
      maxIdx = childIdx;
    }
  }

  // compare w/ right
  childIdx = 2 * rootIdx + 2;
  if (childIdx < vecData.size()) {
    if (vecData[childIdx] > vecData[maxIdx]) {
      maxIdx = childIdx;
    }
  }

  if (maxIdx != rootIdx) {
    // swap
    int tmp = vecData[maxIdx];
    vecData[maxIdx] = vecData[rootIdx];
    vecData[rootIdx] = tmp;

    // recursive call
    heapifyMaxHeap(vecData, maxIdx);
  }
}

void buildMaxHeap(vector<int> &vecData) {
  // d=0 =>1              5(0)
  //                     /    \
  // d=1 =>1+2        4(1)    1(2)
  //                 /   \      /   \
  // d=2 =>1+2+4   9(3)  2(4)  3(5)  null(6)
  //
  // d= 3 => 1+2+4+8

  // int depth = (int)log2((double)vecData.size());
  int maxTestNodes = 0;

  // for (int i = 0; i < depth; i++) {
  //   maxTestNodes += (1 << i);
  // }
  maxTestNodes = (vecData.size() - 1 - 1) / 2;
  // printf("maxTestNodes = %d\n", maxTestNodes);

  // for (int idx = maxTestNodes - 1; idx >= 0; idx--) {
  for (int idx = maxTestNodes; idx >= 0; idx--) {
    heapifyMaxHeap(vecData, idx);
  }
}

void basic_heapify() {
  vector<int> vecData({5, 4, 1, 9, 2, 3});
  //      5(0)
  //      /    \
  //    4(1)    1(2)
  //   /   \      /   \
  //  9(3)  2(4)  3(5)  null(6)
  printf("== input data ==\n");
  for (auto &ir : vecData)
    printf("%d ", ir);
  printf("\n");

  printf("== Heapify (max heap) ==\n");
  // build max/min heapfied tree : O(NlogN)
  // Hepaify a heapified tree : O(logN)
  buildMaxHeap(vecData);
  for (auto &ir : vecData)
    printf("%d ", ir);
  printf("\n");

  printf("== Re-Heapify (max heap) ==\n");
  // log(N)
  vecData.erase(vecData.begin());
  vecData.insert(vecData.begin(), vecData.back());
  vecData.pop_back();
  heapifyMaxHeap(vecData, 0);
  for (auto &ir : vecData)
    printf("%d ", ir);
  printf("\n");
}

#define HEAP_SORT_AVOID_COPY 0

void basic_heap_sort() {
  vector<int> data({6, 2, 8, 1, 0, 7, 3});

  // HW0919: heap sort / ascending sort

  // build min heap: O(NlogN)
  // N heapify : O(NlogN)

  buildMaxHeap(data);

  printf("== Max Heap built ==\n");
  for (auto &val : data)
    printf("%d ", val);
  printf("\n");

#if HEAP_SORT_AVOID_COPY
  vector<int> res;
  while (1) {
    swap(data.front(), data.back());

    res.push_back(data.back());
    data.pop_back();

    if (data.size() == 1) {
      res.push_back(data.front());
      break;
    }
    heapifyMaxHeap(data, 0);
  }

  data = res;
#else

  for (int i = data.size() - 1; i > 0; --i) {
    swap(data[0], data[i]);

    vector<int> subVec(data.begin(), data.begin() + i);
    heapifyMaxHeap(subVec, 0);

    copy(subVec.begin(), subVec.end(), data.begin());

    printf("== After re-heapify (i = %d) ==\n", i);
    for (auto &val : data)
      printf("%d ", val);
    printf("\n");
  }
#endif

  printf("== Sorted data (Ascending) ==\n");
  for (auto &val : data)
    printf("%d ", val);
  printf("\n");
}

STreeNode *createBFTree(vector<STreeNode> &nodes) {
  // METHOD 1: recursive programming (X)
  // METHOD 2: using index relationship to create tree

  for (int i = 1; i < nodes.size(); i++) {
    if (i % 2) {
      int parentIdx = (i - 1) / 2;
      nodes[parentIdx].left = &(nodes[i]);
    } else {
      int parentIdx = (i - 2) / 2;
      nodes[parentIdx].right = &(nodes[i]);
    }
  }

  return &(nodes[0]);
}

void basic_binaryTree_creation_breathFirst() {
  vector<int> vals({8, 5, 3, 2, 9, 1});

  // Breath-first / level-first binary tree
  //     8(0)
  //    /      \
  //   5(1)     3(2)
  //  /   \      /    \
  // 2(3) 9(4)  1(5)   null(6)

  // METHOD 1: allocation memory along initialization (X)
  // METHOD 2: allocation memory at once (O)

  vector<STreeNode> nodes;
  for (auto &ir : vals) {
    nodes.push_back(STreeNode(ir));
  }

  STreeNode *root = createBFTree(nodes);
  printf("root value = %d\n", root->val);
  printNodes(nodes);
}

STreeNode *createDFPreOrderRec(vector<STreeNode> &nodes, int maxDepthNo,
                               int depth, int &dataIdx) {
  // f(x) = {root} + f(root->left) + f(root->right)
  STreeNode *root = nullptr;

  // excetion
  if (depth == maxDepthNo) {
    if (dataIdx < nodes.size()) {
      root = &(nodes[dataIdx]);
      dataIdx++;
    }
    return root;
  }

  // general
  root = &(nodes[dataIdx]);
  dataIdx++;

  root->left = createDFPreOrderRec(nodes, maxDepthNo, depth + 1, dataIdx);
  root->right = createDFPreOrderRec(nodes, maxDepthNo, depth + 1, dataIdx);

  return root;
}

STreeNode *createDFPreOrderRec(vector<STreeNode> &nodes, int startIdx,
                               int endIdx) {
  //  f(x) = {root} + f(root->left) + f(root->right)
  //   startIdx        startIdx +1              endIdx
  STreeNode *root = nullptr;
  // exception
  // only one node
  if (startIdx == endIdx) {
    return &(nodes[startIdx]);
  }
  // only two nodes
  if (startIdx + 1 == endIdx) {
    nodes[startIdx].left = &(nodes[endIdx]);
    return &(nodes[startIdx]);
  }

  // general case
  int rootIdx = startIdx;
  root = &(nodes[rootIdx]);

  int len = endIdx - (startIdx + 1) + 1;

  root->left =
      createDFPreOrderRec(nodes, startIdx + 1, startIdx + 1 + len / 2 - 1);
  root->right = createDFPreOrderRec(nodes, startIdx + 1 + len / 2, endIdx);

  return root;
}

STreeNode *createDFTree_PreOrder(vector<STreeNode> &nodes) {
  STreeNode *root = nullptr;

  enum IMPLT_ID_ {
    IMPLT_MAXDEPTH = 0,
    IMPLT_DIV_N_CONQ,
  };

  int impltID = IMPLT_DIV_N_CONQ;

  if (impltID == IMPLT_MAXDEPTH) {
    int maxDepthNo = (int)log2((double)nodes.size());
    // Depth-first binary tree 1) Pre-order traversal  : Root, Left, Right
    //      8(0)
    //    /      \
    //   5(1)     9(4)
    //  /   \      /    \
    // 3(2) 2(3)  1(5)   null(6)

    // input/condition: maxDepthNo
    // output (return, reference) : return root
    // variables among iterations: depth, dataIdx
    //  f(x) = {root} + f(root->left) + f(root->right)
    int depth = 0;
    int dataIdx = 0;
    root = createDFPreOrderRec(nodes, maxDepthNo, depth, dataIdx);
  } else if (impltID == IMPLT_DIV_N_CONQ) {
    // Depth-first binary tree 1) Pre-order traversal  : Root, Left, Right
    //      8(0)
    //    /         \
    //   5(1)         2(3)
    //  /   \         /    \
    // 3(2) null(6)   9(4)  1(5)
    //
    //  f(x) = {root} + f(root->left) + f(root->right)
    //         {  8 ,    5, 3, 2,        4, 1         }
    //
    // (1) input /condition : startIdx, endIdx, nodes
    // (2) output : return root
    // (3) variable among iterations :
    int startIdx = 0;
    int endIdx = nodes.size() - 1;
    root = createDFPreOrderRec(nodes, startIdx, endIdx);

  } else {
    printf("Not a supported implementation ID : %d\n", impltID);
    exit(-1);
  }

  return root;
}

STreeNode *createDFInOrderRec(vector<STreeNode> &nodes, int maxDepthNo,
                              int depth, int &dataIdx) {
  // f(x) = f(root->left) + {root} + f(root->right)
  STreeNode *root = nullptr;
  // if (depth > maxDepthNo || dataIdx >= nodes.size()) {
  //   return nullptr;
  // }
  if (depth == maxDepthNo) {
    if (dataIdx < nodes.size()) {
      root = &(nodes[dataIdx]);
      dataIdx++;
    }
    return root;
  }

  STreeNode *left = createDFInOrderRec(nodes, maxDepthNo, depth + 1, dataIdx);

  root = &nodes[dataIdx++];
  root->left = left;

  STreeNode *right = createDFInOrderRec(nodes, maxDepthNo, depth + 1, dataIdx);
  root->right = right;

  return root;
}

STreeNode *createDFInOrderRec(vector<STreeNode> &nodes, int startIdx,
                              int endIdx) {
  //  f(x) =  f(root->left) + {root} + f(root->right)

  STreeNode *root = nullptr;
  // exception
  // only one node
  if (startIdx == endIdx) {
    return &(nodes[startIdx]);
  }

  // only two nodes
  if (startIdx + 1 == endIdx) {
    nodes[endIdx].left = &(nodes[startIdx]);
    return &(nodes[endIdx]);
  }

  // general case
  int rootIdx = startIdx + (endIdx - startIdx + 1) / 2;
  root = &(nodes[rootIdx]);

  root->left = createDFInOrderRec(nodes, startIdx, rootIdx - 1);
  root->right = createDFInOrderRec(nodes, rootIdx + 1, endIdx);

  return root;
}

STreeNode *createDFTree_InOrder(vector<STreeNode> &nodes) {
  STreeNode *root = nullptr;

  enum IMPLT_ID_ {
    IMPLT_MAXDEPTH = 0,
    IMPLT_DIV_N_CONQ,
  };

  int impltID = IMPLT_DIV_N_CONQ;

  if (impltID == IMPLT_MAXDEPTH) {
    int maxDepthNo = (int)log2((double)nodes.size());
    // HW0829
    // vector<int> vals({8, 5, 3, 2, 9, 1});
    // Depth-first binary tree 2) In-order traversal : Left, Root, Right
    //      2(3)
    //    /      \
    //   5(1)     1(5)
    //  /   \      /    \
    // 8(0) 3(2)  9(4)   null(6)
    int depth = 0;
    int dataIdx = 0;
    root = createDFInOrderRec(nodes, maxDepthNo, depth, dataIdx);
  } else if (impltID == IMPLT_DIV_N_CONQ) {

    // vector<int> vals({8, 5, 3, 2, 9, 1});
    // Depth-first binary tree 2) In-order traversal : Left, Root, Right
    //      2(3)
    //    /      \
    //   5(1)     1(5)
    //  /   \      /    \
    // 8(0) 3(2)  9(4)   null(6)
    int startIdx = 0;
    int endIdx = nodes.size() - 1;
    root = createDFInOrderRec(nodes, startIdx, endIdx);

  } else {
    printf("Not a supported implementation ID : %d\n", impltID);
    exit(-1);
  }

  return root;
}

STreeNode *createDFPostOrderRec(vector<STreeNode> &nodes, int maxDepthNo,
                                int depth, int &dataIdx) {
  // f(x) = f(root->left) + {root->right} + f(root)
  STreeNode *root = nullptr;
  if (depth > maxDepthNo || dataIdx >= nodes.size()) {
    return nullptr;
  }

  STreeNode *left = createDFPostOrderRec(nodes, maxDepthNo, depth + 1, dataIdx);
  STreeNode *right =
      createDFPostOrderRec(nodes, maxDepthNo, depth + 1, dataIdx);

  root = &nodes[dataIdx];
  root->left = left;
  root->right = right;
  dataIdx++;

  return root;
}
STreeNode *createDFPostOrderRec(vector<STreeNode> &nodes, int startIdx,
                                int endIdx) {
  // f(x) = f(root->left) + {root->right} + {root}
  //  left, right root
  STreeNode *root = nullptr;

  // exception
  // only one node
  if (startIdx == endIdx) {
    return &(nodes[startIdx]);
  }

  // only two nodes
  if (startIdx + 1 == endIdx) {
    nodes[endIdx].left = &(nodes[startIdx]);
    return &(nodes[endIdx]);
  }

  // general case
  int rootIdx = endIdx;
  root = &(nodes[rootIdx]);
  int len = (endIdx - 1) - startIdx + 1;

  root->left = createDFPostOrderRec(nodes, startIdx, startIdx + len / 2 - 1);
  root->right = createDFPostOrderRec(nodes, startIdx + len / 2, endIdx - 1);

  return root;
}

STreeNode *createDFTree_PostOrder(vector<STreeNode> &nodes) {
  STreeNode *root = nullptr;

  enum IMPLT_ID_ {
    IMPLT_MAXDEPTH = 0,
    IMPLT_DIV_N_CONQ,
  };

  int impltID = IMPLT_DIV_N_CONQ;

  if (impltID == IMPLT_MAXDEPTH) {
    int maxDepthNo = (int)log2((double)nodes.size());
    // HW0829
    // vector<int> vals({8, 5, 3, 2, 9, 1});
    // Depth-first binary tree 3) Post-order traversal : Left, Right, Root
    //      null(6) ?
    //    /        \
  //   3(2)      1(5)
    //  /   \      /   \
  // 8(0) 5(1)  2(3)   9(4)

    // Derek how to construct this tree ??
    //      1(5)
    //    /      \
  //   3(2)      9(4)
    //  /   \      /   \
  // 8(0) 5(1)  2(3)
    int depth = 0;
    int dataIdx = 0;
    root = createDFPostOrderRec(nodes, maxDepthNo, depth, dataIdx);
  } else if (impltID == IMPLT_DIV_N_CONQ) {
    //      1(5)
    //    /      \
    //   5(1)      9(4)
    //  /   \      /   \
    // 8(0)  null  3(2)  2(3)
    int startIdx = 0;
    int endIdx = nodes.size() - 1;
    root = createDFPostOrderRec(nodes, startIdx, endIdx);

  } else {
    printf("Not a supported implementation ID : %d\n", impltID);
    exit(-1);
  }

  return root;
}

void basic_binaryTree_creation_depthFirst() {
  vector<int> vals({8, 5, 3, 2, 9, 1});
  vector<STreeNode> nodes;
  STreeNode *root = nullptr;

  printf("== Depth First: Pre-order ==\n");
  // Depth-first binary tree 1) Pre-order traversal  : Root, Left, Right
  //      8(0)
  //    /      \
  //   5(1)     9(4)
  //  /   \      /    \
  // 3(2) 2(3)  1(5)   null(6)
  for (auto &ir : vals) {
    nodes.push_back(STreeNode(ir));
  }
  root = createDFTree_PreOrder(nodes);
  printf("root value = %d\n", root->val);
  printNodes(nodes);

  printf("== Depth First: In-order ==\n");
  // Depth-first binary tree 2) In-order traversal : Left, Root, Right
  //      2(3)
  //    /      \
  //   5(1)     1(5)
  //  /   \      /    \
  // 8(0) 3(2)  9(4)   null(6)
  nodes.clear();
  for (auto &ir : vals) {
    nodes.push_back(STreeNode(ir));
  }
  root = createDFTree_InOrder(nodes);
  printf("root value = %d\n", root->val);
  printNodes(nodes);

  printf("== Depth First: Post-order ==\n");
  // Depth-first binary tree 3) Post-order traversal : Left, Right, Root
  //      null(6) ?
  //    /        \
  //   3(2)      1(5)
  //  /   \      /   \
  // 8(0) 5(1)  2(3)   9(4)

  //      1(5)
  //    /      \
  //   3(2)      9(4)
  //  /   \      /   \
  // 8(0) 5(1)  2(3)
  nodes.clear();
  for (auto &ir : vals) {
    nodes.push_back(STreeNode(ir));
  }
  root = createDFTree_PostOrder(nodes);
  printf("root value = %d\n", root->val);
  printNodes(nodes);
}

vector<int> traverseBTPreOrder(STreeNode *root) {

  //       8
  //    /     \
  //   5        3
  //  /   \    /
  // 2    9   1

  // Pre-order traversal : root, left, right:  {8, 5, 2, 9, 3, 1}
  //   f(x) = {root} + f(x->left) + f(x->right)
  vector<int> traversed;

  // exception
  if (root == nullptr)
    return traversed;

  // general
  traversed.push_back(root->val);

  vector<int> leftTraversed = traverseBTPreOrder(root->left);
  // traversed + leftTraversed
  traversed.insert(traversed.end(), leftTraversed.begin(), leftTraversed.end());

  vector<int> rightTraversed = traverseBTPreOrder(root->right);
  //+ rightTraversed
  traversed.insert(traversed.end(), rightTraversed.begin(),
                   rightTraversed.end());

  return traversed;
}

vector<int> traverseBTInOrder(STreeNode *root) {
  //       8
  //    /     \
  //   5        3
  //  /   \    /
  // 2    9   1
  // In-order traversal : left, root, right:  {2, 5, 9, 8, 1, 3}
  //   f(x) = f(x->left) +  {root} + f(x->right)
  vector<int> traversed;
  // exception
  if (root == nullptr)
    return traversed;

  // general
  vector<int> leftTraversed = traverseBTInOrder(root->left);
  // traversed + leftTraversed
  traversed.insert(traversed.end(), leftTraversed.begin(), leftTraversed.end());

  traversed.push_back(root->val);

  vector<int> rightTraversed = traverseBTInOrder(root->right);
  //+ rightTraversed
  traversed.insert(traversed.end(), rightTraversed.begin(),
                   rightTraversed.end());

  return traversed;
}

vector<int> traverseBTPostOrder(STreeNode *root) {
  //       8
  //    /     \
  //   5        3
  //  /   \    /
  // 2    9   1
  // traversal : left, right, root:  {5, 2, 9, 3, 1, 8}
  //   f(x) = f(x->left) +  f(x->right)+ {root}
  vector<int> traversed;
  // exception
  if (root == nullptr)
    return traversed;

  // general
  vector<int> leftTraversed = traverseBTPostOrder(root->left);
  // traversed + leftTraversed
  traversed.insert(traversed.end(), leftTraversed.begin(), leftTraversed.end());

  vector<int> rightTraversed = traverseBTPostOrder(root->right);
  //+ rightTraversed
  traversed.insert(traversed.end(), rightTraversed.begin(),
                   rightTraversed.end());

  traversed.push_back(root->val);

  return traversed;
}

void basic_binaryTree_traversal() {
  vector<int> vals({8, 5, 3, 2, 9, 1});

  STreeNode *root = nullptr;
  vector<STreeNode> nodes;
  for (auto &ir : vals) {
    nodes.push_back(STreeNode(ir));
  }

  root = createBFTree(nodes);
  printNodes(nodes);
  //       8
  //    /     \
  //   5        3
  //  /   \    /
  // 2    9   1

  // Pre-order traversal : root, left, right:  {8, 5, 2, 9, 3, 1}
  // In-order traversal : left, root, right:   {2, 5, 9, 8, 1, 3}
  // Post-order traversal : left, right, root: {2, 9, 5, 1, 3, 8}
  //

  vector<int> traversed;

  printf("== Pre-order traversal === \n");
  traversed = traverseBTPreOrder(root);
  for (auto &ir : traversed)
    printf("%d ", ir);
  printf("\n");

  printf("== In-order traversal === \n");
  traversed = traverseBTInOrder(root);
  for (auto &ir : traversed)
    printf("%d ", ir);
  printf("\n");

  printf("== Post-order traversal === \n");
  traversed = traverseBTPostOrder(root);
  for (auto &ir : traversed)
    printf("%d ", ir);
  printf("\n");
}

void leetcode_balanced_tree() {
  vector<STreeNode> nodeData(6);
  nodeData[0].val = 7;
  nodeData[0].left = &(nodeData[1]);
  nodeData[0].right = &(nodeData[2]);
  nodeData[1].val = 9;
  nodeData[1].left = &(nodeData[3]);
  nodeData[1].right = &(nodeData[4]);
  nodeData[2].val = 1;

  nodeData[3].val = 5;
  nodeData[4].val = 4;
  nodeData[4].left = &(nodeData[5]);
  nodeData[5].val = 6;

  //             7
  //            / \
  //           9   1
  //          / \
  //         5   4
  //             /
  //            6
  STreeNode *root = &(nodeData[0]);
  printf("root value is %d\n", root->val);
  printNodes(nodeData);
  //---------------//
  // Q:  Given an unbalanced binary tree, make it in-order balanced tree.

  //      6
  //     /  \
  //   5     1
  //  / \   / \
  // 9   4 7   NULL

  // HW0906
  vector<int> traversed;
  traversed = traverseBTInOrder(root);
  // traversed = traverseBTPreOrder(root);
  // traversed = traverseBTPostOrder(root);
  for (auto &ir : traversed)
    printf("%d ", ir);
  printf("\n");

  vector<STreeNode> nodes;
  for (auto &ir : traversed) {
    nodes.push_back(STreeNode(ir));
  }
  int startIdx = 0;
  int endIdx = traversed.size() - 1;
  root = createDFInOrderRec(nodes, startIdx, endIdx);
  // root = createDFPreOrderRec(nodes, startIdx, endIdx);
  // root = createDFPostOrderRec(nodes, startIdx, endIdx);
  printf("root value is %d\n", root->val);
  printNodes(nodes);
}

class CRecurLeafBase {
public:
  virtual vector<vector<int>> getLayeredLeaveValues(STreeNode *tree) {
    printf("No implementation\n");
    return vector<vector<int>>(0);
  }
};

class CRecurLeftVK : public CRecurLeafBase {
public:
  vector<vector<int>> getLayeredLeaveValues(STreeNode *tree) {
    //             7
    //            / \
    //           9   1
    //          / \    \
    //         5   4   2
    //             /
    //            6
    //
    // time complexity : O(N logN )

    vector<vector<int>> layers;
    bool isLastNode = false;
    while (!isLastNode) // logN
    {
      // general case
      //  input/ condition :
      //  output (return, reference) : return
      //  variable among recursion: tree
      vector<int> oneLayer = getOneLayerNodes(tree, isLastNode); // N
      layers.push_back(oneLayer);

      // ending contion (TBD)
      // if(isLastNode) break;
    }

    return layers;
  }

private:
  vector<int> getOneLayerNodes(STreeNode *root, bool &setNullPtrLater) {
    vector<int> leafs;

    // exception
    if (root == nullptr)
      return leafs;

    if (root->left == nullptr && root->right == nullptr) {
      leafs.push_back(root->val);
      setNullPtrLater = true;
      return leafs;
    }

    // general  - backtracking + get the feedback signal
    bool setNullPtrNow = false;
    vector<int> leftLeafs = getOneLayerNodes(root->left, setNullPtrNow);
    if (setNullPtrNow)
      root->left = nullptr;
    leafs.insert(leafs.end(), leftLeafs.begin(), leftLeafs.end());

    setNullPtrNow = false;
    vector<int> rightLeafs = getOneLayerNodes(root->right, setNullPtrNow);
    if (setNullPtrNow)
      root->right = nullptr;
    leafs.insert(leafs.end(), rightLeafs.begin(), rightLeafs.end());

    return leafs;
  }
};

class CRecurLeaf : public CRecurLeafBase {
public:
  vector<vector<int>> getLayeredLeaveValues(STreeNode *tree) {
    //             7
    //            / \
    //           9   1
    //          / \    \
    //         5   4   2
    //             /
    //            6
    //

    //     4
    //    /
    //   6
    // left {{6}}, right {}
    // res = left, shortest_side = right
    // res[0] = {{6}, {}}
    // {
    //  {6, },
    //  {4}
    // }
    //
    // HW0913:
    //  post-order traversol: f(x) = f(x->left) + f(x->right) + f(root)
    //     1
    //    / \
    //   2   3
    //  / \
    // 4   5
    // STEP1:
    // root = 1, recursive to left node 2 and right node 3
    // STEP2:
    // root = 2, left = [[4]], right = [[5]], res = [[4]], shortest_side =
    // [[5]], push_back(2) res [[4, 5], [2]] STEP3: return to root = 1 left =
    // [[4, 5], [2]], right = [[3]] res = [[4, 5], [2]], shortest_side = [[3]],
    // push_back(1) res = [[4, 5, 3], [2], [1]]

    // Pre-order : root, left, right  => f(x) = {root} + f(x->left) +
    // f(x->right)
    //
    // HW0913 : derive the recursive functions in polynomial expression: why
    // this method is backtracing? Further improved?
    //
    // time complexity : O(NlogN)
    //
    if (!tree) {
      return {};
    }
    vector<vector<int>> left = getLayeredLeaveValues(tree->left);
    vector<vector<int>> right = getLayeredLeaveValues(tree->right);
    vector<vector<int>> res = (left.size() >= right.size()) ? left : right;
    vector<vector<int>> shortest_side =
        (left.size() >= right.size()) ? right : left;
    for (int i = 0; i < shortest_side.size(); i++) {
      res[i].insert(res[i].begin(), shortest_side[i].begin(),
                    shortest_side[i].end());
    }
    res.push_back({tree->val});
    return res;
    // return vector<vector<int>>(0);
  }
};

void leetcode_recursive_leafs() {

  //             7
  //            / \
  //           9   1
  //          /     \
  //         5       2
  //     {5, 2}, {9, 1}, {7}

  //             7
  //            / \
  //           9   1
  //          /
  //         5
  //     {5, 1}, {9}, {7}

  vector<STreeNode> nodeData(7);
  nodeData[0].val = 7;
  nodeData[0].left = &(nodeData[1]);
  nodeData[0].right = &(nodeData[2]);
  nodeData[1].val = 9;
  nodeData[1].left = &(nodeData[3]);
  nodeData[1].right = &(nodeData[4]);
  nodeData[2].val = 1;
  nodeData[2].right = &(nodeData[6]);
  nodeData[3].val = 5;
  nodeData[4].val = 4;
  nodeData[4].left = &(nodeData[5]);
  nodeData[5].val = 6;
  nodeData[6].val = 2;
  //             7
  //            / \
  //           9   1
  //          / \    \
  //         5   4   2
  //             /
  //            6
  //
  printNodes(nodeData);

  //---------------//
  STreeNode *tree = &(nodeData[0]);

  // Q:  Given binary tree, print out the leaf values at different layers
  //   Examples: {5, 6, 2} {4, 1} {9}, {7}
  CRecurLeaf solDerived;
  CRecurLeafBase *sol = &solDerived;

  vector<vector<int>> vecOut;
  vecOut = sol->getLayeredLeaveValues(tree);
  for (auto ir : vecOut) {
    for (auto ir_t : ir) {
      printf("%d ", ir_t);
    }
    printf("\n");
  }
}
class CSolDistanceKInBTBase {
public:
  virtual vector<int> distanceK(STreeNode *root, STreeNode *target, int k) {
    return vector<int>();
  }
};
//
// Dynamic Programming : Top-down thinking => backtracking
//
// f(x) = {root} + f(x->left) + f(x->right) : decision tree (X)
// f(x) = f(x-1) + f(x-2) : numerical operation => backtracking O(2^N) =>
// memoization => O(N)
//
class CSolDistanceKInBT : public CSolDistanceKInBTBase {
public:
  vector<int> distanceK(STreeNode *root, STreeNode *target, int k) {
    // time complexity : O(logN K) (?)  To be discused.
    // HW0913 : to be discussed (no action item)
    // target = 3, k = 2
    // ans = [2, 7, 8]
    //             1
    //            / \
    //           2   3  <- target
    //          / \    \
    //         4   5    6
    //                 / \
    //                7   8
    //
    // dfs(1)
    // left = -1 -> dfs(2) -> left = dfs(4) return -1
    //                -> right = dfs(5) return -1
    // right = 1 -> dfs(3) return 1
    // looking for left sub-tree of node 1 is distance one from node 3
    // find all nodes that are distance one from node 1
    // HW0906
    vector<int> nodesDistanceK;
    find_distance_from_node_to_target(root, target->val, k, nodesDistanceK);
    // return vector<int>();
    return nodesDistanceK;
  }
  int find_distance_from_node_to_target(STreeNode *node, int target, int k,
                                        vector<int> &nodesDistanceK) {
    // exception / base
    if (node == nullptr) {
      return -1;
    }
    if (node->val == target) {
      add_subtree_node_at_distance_k(node, 0, k, nodesDistanceK);
      return 1;
    }

    // general
    int leftDistance = find_distance_from_node_to_target(node->left, target, k,
                                                         nodesDistanceK);
    int rightDistance = find_distance_from_node_to_target(node->right, target,
                                                          k, nodesDistanceK);

    if (leftDistance == k || rightDistance == k) {
      nodesDistanceK.push_back(node->val);
    }
    if (leftDistance != -1) {
      add_subtree_node_at_distance_k(node->right, leftDistance + 1, k,
                                     nodesDistanceK);
      return leftDistance + 1;
    }
    if (rightDistance != -1) {
      add_subtree_node_at_distance_k(node->left, rightDistance + 1, k,
                                     nodesDistanceK);
      return rightDistance + 1;
    }

    return -1;
  }
  void add_subtree_node_at_distance_k(STreeNode *node, int distance, int k,
                                      vector<int> &nodesDistanceK) {
    if (node == nullptr) {
      return;
    }
    if (distance == k) {
      nodesDistanceK.push_back(node->val);
    } else {
      add_subtree_node_at_distance_k(node->left, distance + 1, k,
                                     nodesDistanceK);
      add_subtree_node_at_distance_k(node->right, distance + 1, k,
                                     nodesDistanceK);
    }
  }
};

class CSolDistanceKVK : public CSolDistanceKInBTBase {
public:
  vector<int> distanceK(STreeNode *root, STreeNode *target, int k) {
    vector<int> kVals;

    // traverse to target and backtracking all parent nodes
    //  O(logN)
    int distance = 0;
    vector<STreeNode *> nodeList = traverseToTarget(root, target, distance);

    // traverse from target and all rotts
    int numRoots = (k + 1 < nodeList.size()) ? (k + 1) : nodeList.size();
    // O(logN * k)
    for (int i = 0; i < numRoots; i++, k--) {
      STreeNode *excludeNode = (i == 0) ? nullptr : nodeList[i - 1];
      vector<int> vals = traverseChildsWithK(nodeList[i], excludeNode, k);
      kVals.insert(kVals.end(), vals.begin(), vals.end());
    }

    return kVals;
  }

private:
  vector<int> traverseChildsWithK(STreeNode *root, STreeNode *excludeNode,
                                  int distance) {
    vector<int> traversed;
    // exception
    if (root == nullptr || root == excludeNode) {
      return traversed;
    }

    if (distance == 0) {
      traversed.push_back(root->val);
      return traversed;
    }

    // general
    vector<int> leftList =
        traverseChildsWithK(root->left, excludeNode, distance - 1);
    traversed.insert(traversed.end(), leftList.begin(), leftList.end());

    vector<int> rightList =
        traverseChildsWithK(root->right, excludeNode, distance - 1);
    traversed.insert(traversed.end(), rightList.begin(), rightList.end());

    return traversed;
  }

  vector<STreeNode *> traverseToTarget(STreeNode *root, STreeNode *target,
                                       int &distance) {
    vector<STreeNode *> traversed;
    // exception case
    if (root == nullptr) {
      return traversed;
    }

    if (root == target) {
      traversed.push_back(root);
      distance++;
      return traversed;
    }

    // general case
    traversed = traverseToTarget(root->left, target, distance);
    if (distance > 0) {
      traversed.push_back(root);
      distance++;
      return traversed;
    }

    traversed = traverseToTarget(root->right, target, distance);
    if (distance > 0) {
      traversed.push_back(root);
      distance++;
      return traversed;
    }

    return traversed;
  }
};

void leetcode_bt_distanceK() {

  CSolDistanceKInBT objDerived;
  CSolDistanceKInBTBase *obj;
  obj = &objDerived;

  int k;
  vector<int> kVals;

  STreeNode *root = nullptr;
  STreeNode *target = nullptr;
  vector<STreeNode> nodeData;
  printf("-- case 0 --\n");
  nodeData.clear();
  nodeData.resize(4);
  nodeData[0].val = 0;
  nodeData[1].val = 1;
  nodeData[2].val = 3;
  nodeData[3].val = 2;
  nodeData[0].left = &(nodeData[1]);
  nodeData[1].left = &(nodeData[2]);
  nodeData[1].right = &(nodeData[3]);

  root = &(nodeData[0]);
  target = &(nodeData[3]);
  k = 1;

  kVals = obj->distanceK(root, target, k);

  printf("[");
  for (auto ir : kVals) {
    printf("%d ", ir);
  }
  printf("] => ans: [1]\n");

  printf("-- case 1 --\n");
  nodeData.clear();
  nodeData.resize(7);
  nodeData[0].val = 7;
  nodeData[0].left = &(nodeData[1]);
  nodeData[0].right = &(nodeData[2]);
  nodeData[1].val = 9;
  nodeData[1].left = &(nodeData[3]);
  nodeData[1].right = &(nodeData[4]);
  nodeData[2].val = 1;
  nodeData[2].right = &(nodeData[6]);
  nodeData[3].val = 5;
  nodeData[4].val = 4;
  nodeData[4].left = &(nodeData[5]);
  nodeData[5].val = 6;
  nodeData[6].val = 2;
  //              7 (0)
  //            /      \
  //           9 (1)    1 (2)
  //          / \         /  \
  //       5(3)  4 (4)  null   2(6)
  //             /
  //            6 (5)

  printNodes(nodeData);

  root = &(nodeData[0]);
  target = &(nodeData[4]);
  k = 2;

  kVals = obj->distanceK(root, target, k);

  printf("[");
  for (auto ir : kVals) {
    printf("%d ", ir);
  }
  printf("] => ans: [5 7]\n");

  printf("-- case 2 --\n");
  nodeData.clear();
  nodeData.resize(9);

  nodeData[0].val = 3;
  nodeData[0].left = &(nodeData[1]);
  nodeData[0].right = &(nodeData[2]);

  nodeData[1].val = 5;
  nodeData[1].left = &(nodeData[3]);
  nodeData[1].right = &(nodeData[4]);

  nodeData[3].val = 6;

  nodeData[4].val = 2;
  nodeData[4].left = &(nodeData[7]);
  nodeData[4].right = &(nodeData[8]);
  nodeData[7].val = 7;
  nodeData[8].val = 4;

  nodeData[2].val = 1;
  nodeData[2].left = &(nodeData[5]);
  nodeData[2].right = &(nodeData[6]);
  nodeData[5].val = 0;
  nodeData[6].val = 8;
  //              3 (0)
  //            /      \
  //           5 (1)    1 (2)
  //          / \         /  \
  //       6(3)  2 (4)  null   2(6)
  //            /   \
  //           7 (5) 4 (8)
  printNodes(nodeData);

  root = &(nodeData[0]);
  target = &(nodeData[1]);
  k = 2;

  kVals = obj->distanceK(root, target, k);

  printf("[");
  for (auto ir : kVals) {
    printf("%d ", ir);
  }
  printf("] => ans: [7 4 1]\n");
}

int fibSeqHelper(int k, unordered_map<int, int> &memorize) {
  if (memorize.find(k) != memorize.end()) {
    return memorize[k];
  } else {
    memorize[k] = fibSeqHelper(k - 1, memorize) + fibSeqHelper(k - 2, memorize);
    return memorize[k];
  }
#if 0
  //exception | base
  if(k== 0) return 0;
  if(k== 1) return 1;

  //general: X(n) = X(n-1) + X(n-2)
  // without memo : O(2^N)
  // w/ memo : O(N)
  //
  if (memorize.find(k) != memorize.end()){
    return memorize[k];
  }
  return memorize[k] = fibSeqHelper(k - 1, memorize) + fibSeqHelper(k - 2, memorize);
#endif
}
int getFibSeq(int k) {
  // HW0913 : backtracking + memoization
  unordered_map<int, int> memorize{{1, 0}, {2, 1}};
  return fibSeqHelper(k, memorize); // please modify it.
}
void leetcode_fibonacci_seq() {

  // Fibonacci (費氏函數)
  // Formula : X(n) = X(n-1) + X(n-2)
  //           X(0) = 0, X(1) = 1
  //  {0,   1,   1,    2, 3, 5, 8....}
  //  X(0) X(1) X(2)  X(3) ........ X(N-1)
  //
  //
  //  Q: Given k, derive X(k)
  //.    For example : X(0) = 0, when k=0
  //.                  X(2) = 1, when k=2
  //                   X(4) = 3, when k=4
  // NOTE: time complexity must be O(N)

  int k = 10;
  int Xk = getFibSeq(k);

  printf("X%d= %d\n", k, Xk);
}

class CFuncParsingBase {
public:
  virtual int solveFunctions(string paramStr) { return -1; }
};

class CFuncBase {
public:
  virtual int getNum() { return -1; }
  virtual int getRes(vector<int> in) { return -1; }
};

class CFuncF : public CFuncBase {
  int getNum() { return 1; }
  int getRes(vector<int> in) { return (2 * in[0] - 3); }
};

// 𝑔(𝑥, 𝑦) = 2𝑥 + 𝑦 – 7
class CFuncG : public CFuncBase {
  int getNum() { return 2; }
  int getRes(vector<int> in) { return (2 * in[0] + in[1] - 7); }
};

// ℎ(𝑥, 𝑦, 𝑧) = 3𝑥 – 2𝑦 + 𝑧
class CFuncH : public CFuncBase {
  int getNum() { return 3; }
  int getRes(vector<int> in) { return (3 * in[0] - 2 * in[1] + in[2]); }
};

class CFuncParsingVK : CFuncParsingBase {
public:
  int solveFunctions(string paramStr) {
    // input string -> vector of parameters
    vector<string> paramList;
    string oneStr;
    for (auto &ir : paramStr) {
      if (ir == ' ') {
        paramList.push_back(oneStr);
        oneStr.clear();
      } else {
        oneStr.push_back(ir);
      }
    }
    paramList.push_back(oneStr);
    return recSolveFunc(paramList);
  }

private:
  int recSolveFunc(vector<string> &paramList) {
    // int res = -1;
    // exception
    if (isdigit(paramList.front().back())) {
      int oneParam = stoi(paramList.front());
      paramList.erase(paramList.begin());
      return oneParam;
    }

    // general
    char funcChar = paramList.front().front();
    CFuncBase *func = nullptr;

    switch (funcChar) {
    case 'f':
      func = &funcF;
      break;
    case 'g':
      func = &funcG;
      break;
    case 'h':
      func = &funcH;
      break;
    default:
      printf("not a defined implementation: %d\n", (int)funcChar);
      exit(-1);
    }
    paramList.erase(paramList.begin());
    vector<int> funcParams;
    for (int i = 0; i < func->getNum(); i++)
      funcParams.push_back(recSolveFunc(paramList));

    return func->getRes(funcParams);
  }

private:
  CFuncF funcF;
  CFuncG funcG;
  CFuncH funcH;
};

class CFuncParsingDerive : public CFuncParsingBase {
public:
  int solveFunctions(string paramStr) {
    // H@0913
    vector<string> tokens = tokenize(paramStr);
    int idx = 0;
    return evaluate(tokens, idx);
  }

private:
  int f(int x) { return 2 * x - 3; }

  int g(int x, int y) { return 2 * x + y - 7; }

  int h(int x, int y, int z) { return 3 * x - 2 * y + z; }

  vector<string> tokenize(const string &str) {
    vector<string> tokens;
    istringstream iss(str);
    string token;
    while (iss >> token) {
      tokens.push_back(token);
    }
    return tokens;
  }

  int evaluate(const vector<string> &tokens, int &idx) {
    string token = tokens[idx];
    idx++;
    if (token == "f") {
      int x = evaluate(tokens, idx);
      return f(x);
    } else if (token == "g") {
      int x = evaluate(tokens, idx);
      int y = evaluate(tokens, idx);
      return g(x, y);
    } else if (token == "h") {
      int x = evaluate(tokens, idx);
      int y = evaluate(tokens, idx);
      int z = evaluate(tokens, idx);
      return h(x, y, z);
    } else {
      return stoi(token);
    }
  }
};

void leetcode_functionParsing() {
  // 𝑓(𝑥) = 2𝑥 – 3
  // 𝑔(𝑥, 𝑦) = 2𝑥 + 𝑦 – 7
  // ℎ(𝑥, 𝑦, 𝑧) = 3𝑥 – 2𝑦 + 𝑧

  //
  //
  // input string = {h f 5 g 3 4 3}, "space" is inserted between two consecutive
  // parameters, ℎ(𝑓(5), 𝑔(3, 4), 3) = ℎ(7, 3, 3) = 18
  // y(x) = y( h, f, g) <== backtracking
  //

  CFuncParsingBase *sol = nullptr;
  CFuncParsingDerive solDerived;

  sol = &solDerived;
  string inStr = "h f 5 g 3 4 3";
  int res = sol->solveFunctions(inStr);
  printf("%d (ans = 18)\n", res);
}

void siftDown(int currentIdx, int endIdx, vector<int> &heap) {
  int childOneIdx = currentIdx * 2 + 1;
  while (childOneIdx <= endIdx) {
    int childTwoIdx = currentIdx * 2 + 2 <= endIdx ? currentIdx * 2 + 2 : -1;
    int idxToSwap;
    if (childTwoIdx != -1 && heap[childTwoIdx] < heap[childOneIdx]) {
      idxToSwap = childTwoIdx;
    } else {
      idxToSwap = childOneIdx;
    }
    if (heap[idxToSwap] < heap[currentIdx]) {
      swap(heap[idxToSwap], heap[currentIdx]);
      currentIdx = idxToSwap;
      childOneIdx = currentIdx * 2 + 1;
    } else {
      return;
    }
  }
}

vector<int> buildMinHeap(vector<int> &vector) {
  // Write your code here.
  int firstParentIdx = (vector.size() - 2) / 2;
  for (int i = firstParentIdx; i >= 0; i--) {
    siftDown(i, vector.size() - 1, vector);
    // for (auto n : vector) {
    //   cout << n << " " ;
    // }
    // cout << endl;
  }
  // cout << "sorted: ";
  // for (auto n : vector) {
  //   cout << n << " " ;
  // }
  return vector;
}

int funcFindKthMinFromArray(vector<int> vecData, int k) {
  // HW0926
  buildMinHeap(vecData);
  for (int endIdx = vecData.size() - 1; endIdx >= 0; endIdx--) {
    swap(vecData[0], vecData[endIdx]);
    siftDown(0, endIdx - 1, vecData);
  }
  cout << "sorted: ";
  for (auto n : vecData) {
    cout << n << " ";
  }
  cout << endl;
  for (int i = k; i > 1; i--) {
    vecData.pop_back();
  }
  return vecData.back();
}

void leetcode_bt_findKthMin() {
  // Given any array/vector, find the K-min number.
  // Example: array = {5, 4, 1, 9, 2, 3}, if K=3, the 3rd min number is 3.
  // d=0 =>1              5(0)
  //                     /    \
  // d=1 =>1+2        4(1)    1(2)
  //                 /   \      /   \
  // d=2 =>1+2+4   9(3)  2(4)  3(5)  null(6)
  vector<int> vecData({5, 4, 1, 9, 2, 3});
  printf("input= { ");
  for (auto &ir : vecData) {
    printf("%d ", ir);
  }
  printf("}\n");

  int k = 3;
  int kthMin = funcFindKthMinFromArray(vecData, k);
  printf("%d-min is %d\n\n", k, kthMin);
}

int pivotPartition(vector<int> &in, int startIdx, int endIdx) {
  // {5, 2, 6, 1, 8, 3, 6, 9, 4}
  //                          ^^
  //  ^ -->             <--^
  // {smaller than pivot} {pivot} {greater than pivot}
  // int startIdx = 0;
  // int endIdx = in.size() - 1;

  int pivotIdx = endIdx;
  int forwardIdx = startIdx, backwardIdx = endIdx - 1;

  while (forwardIdx <= backwardIdx) {
    // general
    //  compare in[forwardIdx]
    bool isForwarding = false, isBackwarding = false;
    if (in[forwardIdx] < in[pivotIdx]) {
      forwardIdx++;
      isForwarding = true;
    }

    // compare in[backwardIdx]
    if (in[backwardIdx] >= in[pivotIdx]) {
      backwardIdx--;
      isBackwarding = true;
    }

    // if both forward and backward operation got stuck,
    //    swap in[forward], in[backward] -> continue
    if (!isForwarding && !isBackwarding) {
      // swap
      int tmp = in[forwardIdx];
      in[forwardIdx] = in[backwardIdx];
      in[backwardIdx] = tmp;

      forwardIdx++;
      backwardIdx--;
    }
  }

  int tmp = in[forwardIdx];
  in[forwardIdx] = in[pivotIdx];
  in[pivotIdx] = tmp;

  return forwardIdx;
}

void basic_pivot_partitioning() {
  // {smaller than pivot} {pivot} {greater than pivot}

  vector<int> vecData({5, 2, 6, 1, 8, 3, 6, 9, 4});

  printf("before : ");
  for (auto &ir : vecData) {
    printf("%d ", ir);
  }
  printf("\n");

  // function
  pivotPartition(vecData, 0, vecData.size() - 1);

  printf("after : ");
  for (auto &ir : vecData) {
    printf("%d ", ir);
  }
  printf("\n");
}

#define MERGETWOLIST_ALTER 1

vector<int> mergeTwoSortedLists(vector<int> a, vector<int> b) {
  // METHOD 0: bubble sort (X)
  // METHOD 1 : std:sort() => O(NlogN)
  // NOTE: requirement : reduced the complexity to O(N)
  vector<int> merged;

#if MERGETWOLIST_ALTER
  // backtracking
  while (!a.empty() || !b.empty()) // Step 0: infinite loop //Step 3: satisfied
                                   // condition = ~(encoding condition)
  {
    // Step 1: general condition & iteration
    // if(!a.empty() && !b.empty()) // compare a.front() , b.front()
    // else if (a.empty) => take b
    // else (b.empty) -=> take a
    vector<int> &selected = (!a.empty() && !b.empty())
                                ? (a.front() < b.front() ? a : b)
                                : (a.empty() ? b : a);

    // get the value, pop out the front, either a or b
    merged.push_back(selected.front());
    selected.erase(selected.begin());

    // Step 2: ending condition
    // if(a.empty() && b.empty()) break;
  }

#else
  int merged_size = a.size() + b.size();

  int leftIdx = 0, rightIdx = 0;
  for (int i = 0; i < merged_size; i++) {
    ///// both a, b exist
    if (leftIdx < a.size() && rightIdx < b.size()) {
      if (a[leftIdx] < b[rightIdx]) {
        merged.push_back(a[leftIdx]);
        leftIdx++;
      } else {
        merged.push_back(b[rightIdx]);
        rightIdx++;
      }
    }
    ///// otherwise, if a exist => take a, other take b
    else if (leftIdx < a.size()) // take a
    {
      merged.push_back(a[leftIdx]);
      leftIdx++;
    } else // take b
    {
      merged.push_back(b[rightIdx]);
      rightIdx++;
    }
  }
#endif

  return merged;
}

void leetcode_merge_sorted_lists() {
  vector<int> a({2, 10, 20, 40}); // sorted
  vector<int> b({1, 25, 30});     // sorted

  vector<int> c = mergeTwoSortedLists(a, b);

  for (auto &ir : c)
    printf("%d ", ir);
  printf("\n");
}

vector<int> mergeSort(vector<int> in, int startIdx, int endIdx) {
  // HW1003
  vector<int> merged;
  // excpetion / base
  if (startIdx >= endIdx) {
    return {in[startIdx]};
  }

  // general
  //  left <-- mergesort()
  //  right <-- mergesort()
  int middleIdx = (startIdx + endIdx) / 2;
  vector<int> leftHalf = mergeSort(in, startIdx, middleIdx);
  vector<int> rightHalf = mergeSort(in, middleIdx + 1, endIdx);

  // merged = mergeTwoSOrtedLists(left, right)
  merged = mergeTwoSortedLists(leftHalf, rightHalf);
  return merged;
}

void basic_mergeSort() {
  vector<int> in({3, 1, 6, 2, 9, 7, 4, 8});

  // f(X0, X1) = f(f(X00, X01), f(X10, X11) )
  int startIdx = 0;

  int endIdx = in.size() - 1;
  vector<int> merged = mergeSort(in, startIdx, endIdx);
  for (auto &ir : merged)
    printf("%d ", ir);
  printf("\n");

  //               quick sort       merge sort     // heap sort
  // complexity     O(NlogN)         O(NlogN)      // O(NlogN)
  // worse case      O(N^2)          O(NlogN)      // O(NlogN)
  //  memory        in-place (less)  not-in-place (more)
  // use case       hw, small         general, large data
}

int revertInteger(int num) {

  int revertNum = 0;
  while (num) {
    int digit = num % 10;
    revertNum = revertNum * 10 + digit;
    num /= 10;
  }

  return revertNum;
}

void leetcode_revert_integer() {
  int num = 12345;
  num = revertInteger(num);
  printf("reverted number = %d (ans : 54321)\n", num);
}

int funcEvenOddDiff(int num) {
  // HW1017
  int evenSum = 0, oddSum = 0;
  int pos = 0;
  while (num) {
    int digit = num % 10;
    if (pos & 1) {
      oddSum += digit;
    } else {
      evenSum += digit;
    }
    num /= 10;
    pos++;
  }

  return abs(evenSum - oddSum);
}

void leetcode_even_odd_diff() {
  int X = 263541;
  // |(2+3+4)- (6+5+1)| = 3
  int diff = funcEvenOddDiff(X);
  printf("diff =%d (ans : 3)\n", diff);

  X = 131;
  // |(1+1) - 3| = 1
  diff = funcEvenOddDiff(X);
  printf("diff =%d (ans : 1)\n", diff);
}

void printIntInBinary(int word) {

  // for 32-bit
  for (int i = 31; i >= 0; --i) {
    int bit = (word >> i) & 1;
    cout << bit;

    if (i % 4 == 0 && i != 0) {
      cout << " ";
    }
  }

  cout << endl;
}

// n & (n - 1), n = 8
void leetcode_print_decimal_in_binary() {
  // >>
  // <<
  // &
  // |

  int word = 20; // 16+4
  printIntInBinary(word);
  // expected: "0000 0000 0000 0000 0000 0000 0001 0100"
}

int checkIfPowerOfTwo(int word) { return !(word & (word - 1)); }

void leetcode_check_power_of_two() {
  int X = 9;
  int isPowerOfTwo = checkIfPowerOfTwo(X);
  printf("%d is power of two: %d\n", X, isPowerOfTwo);
}

int reverseBits(int word) {
  // HW1017
  int reversed = 0;
  for (int i = 0; i < 32; i++) {
    int bit = (word >> i) & 1;
    reversed |= (bit << (31 - i));
  }
  return reversed;
}

void leetcode_bits_resersal() {
  int word = 20; // 16+4
  // "0000 0000 0000 0000 0000 0000 0001 0100"

  int reversed = reverseBits(word);

  printIntInBinary(reversed);
  //  0010 1000 0000 0000 0000 0000 0000 0000
}

#define QUICKSORT_ALTER 1

void quickSort(vector<int> &in, int startIdx, int endIdx) {

#if QUICKSORT_ALTER
  // backtracking + memoization (optional)
  //    {1, 2, 1, 1, 6, 9, 2, 1, 3, 1}
  //  memoization:
  //    - (unordered_map): key : string combeined with numbers, value = sorted
  //    results

  /*
  stringstream newStr;
  int a= 5;
  string str = "John";
  newStr << a << str;
  string tmp = newStr.str();
  */
  // f(X) = f(Xsmaller) + {pivot} + f(Xgreater)

  // exception
  if (startIdx >= endIdx)
    return;

  // general
  // partition in by pivot
  int pivotIdx = pivotPartition(in, startIdx, endIdx);

  // smaller
  quickSort(in, startIdx, pivotIdx - 1);

  // greater
  quickSort(in, pivotIdx + 1, endIdx);

#else
  // HW0926

  // exception
  //  considering your size (startIdx, endIdx) relationship
  if (startIdx >= endIdx) {
    return;
  }
  // general
  //  midPos = pivot partition
  //  startIdx ~ midPos-1
  //  midPos +1 -- endIdx
  int pivotIdx = startIdx;
  int leftIdx = startIdx + 1;
  int rightIdx = endIdx;
  while (leftIdx <= rightIdx) {
    if (in[leftIdx] > in[pivotIdx] && in[rightIdx] < in[pivotIdx]) {
      swap(in[leftIdx], in[rightIdx]);
    }
    if (in[leftIdx] <= in[pivotIdx]) {
      leftIdx += 1;
    }
    if (in[rightIdx] >= in[pivotIdx]) {
      rightIdx -= 1;
    }
  }
  swap(in[rightIdx], in[pivotIdx]);
  bool leftSubarrayIsSmaller =
      rightIdx - 1 - startIdx < endIdx - (rightIdx + 1);
  if (leftSubarrayIsSmaller) {
    // cout << "[left first]" << endl;
    // cout << "startIdx=" << startIdx << ",endIdx=" << endIdx  << endl;
    // cout << "rightIdx=" << rightIdx << endl;
    quickSort(in, startIdx, rightIdx - 1);
    quickSort(in, rightIdx + 1, endIdx);
  } else {
    // cout << "[right first]" << endl;
    // cout << "startIdx=" << startIdx << ",endIdx=" << endIdx  << endl;
    // cout << "rightIdx=" << rightIdx << endl;
    quickSort(in, rightIdx + 1, endIdx);
    quickSort(in, startIdx, rightIdx - 1);
  }
#endif
}

void basic_quickSort() {
  vector<int> in({1, 6, 2, 9, 3, 7, 2, 0, 2, 8, 5});

  printf("== unsorted ==");
  for (auto &ir : in)
    printf("%d ", ir);
  printf("\n");

  int startIdx = 0;
  int endIdx = in.size() - 1;
  quickSort(in, startIdx, endIdx);

  printf("== sorted ==");
  for (auto &ir : in)
    printf("%d ", ir);
  printf("\n");
}

void permute(vector<int> &data, vector<int> &path, int &num,
             vector<vector<int>> &result) {
  // exception
  if (path.size() == data.size()) {
    num++;
    result.push_back(path);
    return;
  }
  // general
  for (auto n : data) {
    if (count(begin(path), end(path), n)) {
      continue;
    }
    path.push_back(n);
    permute(data, path, num, result);
    path.pop_back();
  }
}

#define PERMUTE_VK 1

#if PERMUTE_VK

#define PERMUTE_MEMO 1

// f({a, b, c}) = f( {b, c} | a) + f({a, c} | b) + f({a, b} |c)
//                ^^^^^^^^^^^
//               = f({c} | a, b) + f({b} |a, c)
//              f({}|a, b, c )

string getHashKey(vector<int> nums) {
  stringstream ss;
  for (int i = 0; i < nums.size(); i++)
    ss << nums[i] << "_";
  // printf("haskey = %s\n", ss.str().c_str());
  return ss.str();
}

int permute(vector<int> nums, vector<int> fixed,
            unordered_set<string> &permutedRes) {

  int sum = 0;

  // exception
  if (nums.empty()) {
#if PERMUTE_MEMO
    return 1;
#else
    string key = getHashKey(fixed);

    if (permutedRes.find(key) == permutedRes.end()) {
      permutedRes.insert(key);
      sum = 1;

      //      printf("found: %s\n", key.c_str());
    }
    // else {
    //   printf("repeated: %s\n", key.c_str());
    // }
    return sum;
#endif
  }

  // general
  for (int i = 0; i < nums.size(); i++) {
    int cached = nums[i];
    nums.erase(nums.begin() + i);
    fixed.push_back(cached);
#if PERMUTE_MEMO
    string permuteKey = getHashKey(fixed) + getHashKey(nums);
    if (permutedRes.find(permuteKey) == permutedRes.end()) {
#endif
      sum += permute(nums, fixed, permutedRes);
#if PERMUTE_MEMO
      permutedRes.insert(permuteKey);
    }
#endif
    nums.insert(nums.begin() + i, cached);
    fixed.pop_back();
  }
  return sum;
}

int permuteData(vector<int> nums) {
  unordered_set<string> permutedRes;
  permutedRes.clear();
  return permute(nums, vector<int>(0), permutedRes);
}

#else
int permuteData(vector<int> data) {
  int num = 0;
  // f({a, b, c}) = f( {b, c} | a) + f({a, c} | b) + f({a, b} |c)
  //                ^^^^^^^^^^^
  //               = f({c} | a, b) + f({b} |a, c)
  //              f({}|a, b, c )
  // HW1017 : backtracking , think about if "memoization" can be used
  vector<int> path;
  vector<vector<int>> result;
  permute(data, path, num, result);

  for (int i = 0; i < result.size(); i++) {
    for (int j = 0; j < result[i].size(); j++) {
      cout << result[i][j] << " ";
    }
    cout << endl;
  }

  return num;
}
#endif

void leetcode_permutation() {
  vector<int> data;

  // 3! = 3x2x1
  //
  // 1, 2, 3
  // 1, 3, 2
  // 2, 1, 3
  // 2, 3, 1
  // 3, 1, 2
  // 3, 2, 1

  // Permutation : P(N, N), P(N, K)
  // Combintation : C(N, K)

  // time complexity
  //  backtracking : O(N! M)

  data = {1, 2, 3};
  printf("number of permutation: %d (ans : 6) \n", permuteData(data));

  // backtracking + memoization : O( N!/f M)
  //  f = 2!
  data = {1, 1, 2, 3};
  printf("number of permutation: %d (ans : 12) \n", permuteData(data));

  // backtracking + memoization : O( N!/f M)
  //  f = 2! 2! 2!  ..

  data = {1, 1, 2, 2, 3, 3};
  printf("number of permutation: %d (ans : 90) \n", permuteData(data));
}
// leetcode : P(N, k)
// leetcode : targetsum

class CPrefixScoreBase {
public:
  virtual vector<int> sumPrefixScores(vector<string> &words) {
    vector<int> scores;
    printf("need a implementation");
    return scores;
  }
};

class CPrefixScoreLUT : public CPrefixScoreBase {
public:
  vector<int> sumPrefixScores(vector<string> &words) {
    /*
      words.push_back("abc");
      words.push_back("ab");
      words.push_back("bc");
      words.push_back("b");

      //     a  ab  abc  b bc
      //     2  2   1    1  1
    */

    unordered_map<string, int> prefixMemo;
    // create LUT - Look-Up-Table
    for (auto word : words) {
      while (!word.empty()) {
        prefixMemo[word] = 0;
        word.pop_back();
      }
    }

    // get histogram of the prefix
    for (auto word : words) {
      while (!word.empty()) {
        prefixMemo[word]++;
        word.pop_back();
      }
    }

    // sum up the prefix score for each "word"
    vector<int> scores;
    for (auto word : words) {

      int sum = 0;
      while (!word.empty()) {
        sum += prefixMemo[word];
        word.pop_back();
      }
      scores.push_back(sum);
    }

    return scores;
  }
};

class CPrefixScore : public CPrefixScoreBase {
  class TrieNode {
  public:
    TrieNode *next[26];
    int count;
    TrieNode() : count(0) {
      for (int i = 0; i < 26; i++) {
        next[i] = nullptr;
      }
    }
  };

public:
  vector<int> sumPrefixScores(vector<string> &words) {
    vector<int> scores;
    // HW1023
    TrieNode *root = new TrieNode();
    for (string &word : words) {
      TrieNode *node = root;
      for (char ch : word) {
        if (!node->next[ch - 'a']) {
          node->next[ch - 'a'] = new TrieNode();
        }
        node = node->next[ch - 'a'];
        node->count++;
      }
    }

    for (string &word : words) {
      TrieNode *node = root;
      int score = 0;
      for (char ch : word) {
        if (!node->next[ch - 'a']) {
          break;
        }
        node = node->next[ch - 'a'];
        score += node->count;
      }
      scores.push_back(score);
    }
    return scores;
  }
};

void leetcode_prefix_score() {
  // HW1023
  /*

  https://leetcode.com/problems/sum-of-prefix-scores-of-strings/description/

  You are given an array words of size n consisting of non-empty strings.

  We define the score of a string word as the number of strings words[i]
  such that word is a prefix of words[i].

  For example, if words = ["a", "ab", "abc", "cab"],
  then the score of "ab" is 2, since "ab" is a prefix of both "ab" and "abc".
  Return an array answer of size n
  where answer[i] is the sum of scores of every non-empty prefix of words[i].

  Note that a string is considered as a prefix of itself.


  Example 1:

  Input: words = ["abc","ab","bc","b"]
  Output: [5,4,3,2]
  Explanation: The answer for each string is the following:

  - "abc" has 3 prefixes: "a", "ab", and "abc".
  - There are 2 strings with the prefix "a", 2 strings with the prefix "ab",
  and 1 string with the prefix "abc".
  The total is answer[0] = 2 + 2 + 1 = 5.

  - "ab" has 2 prefixes: "a" and "ab".
  - There are 2 strings with the prefix "a", and 2 strings with the prefix "ab".
  The total is answer[1] = 2 + 2 = 4.

  - "bc" has 2 prefixes: "b" and "bc".
  - There are 2 strings with the prefix "b", and 1 string with the prefix "bc".
  The total is answer[2] = 2 + 1 = 3.

  - "b" has 1 prefix: "b".
  - There are 2 strings with the prefix "b".
  The total is answer[3] = 2.

  Example 2:

  Input: words = ["abcd"]
  Output: [4]
  Explanation:
  "abcd" has 4 prefixes: "a", "ab", "abc", and "abcd".
  Each prefix has a score of one, so the total is answer[0] = 1 + 1 + 1 + 1 = 4.


  Constraints:

  1 <= words.length <= 1000
  1 <= words[i].length <= 1000
  words[i] consists of lowercase English letters.
  */

  CPrefixScore objDerived;
  CPrefixScoreLUT objLUT;
  CPrefixScoreBase *obj;

  enum _IMPLT_ID {
    IMPLT_DERIVED = 0, // O(MN)
    IMPLT_LUT,
  };

  int impltID = IMPLT_LUT;

  if (impltID == IMPLT_DERIVED) {
    obj = &objDerived;
  } else if (impltID == IMPLT_LUT) {
    obj = &objLUT;
  } else {
    printf("not a suppoted implementation %d\n", impltID);
    exit(-1);
  }

  vector<int> scores;

  vector<string> words;
  words.push_back("abc");
  words.push_back("ab");
  words.push_back("bc");
  words.push_back("b");

  scores = obj->sumPrefixScores(words);
  for (auto &ir : scores)
    printf("%d, ", ir);
  printf("\n");
  printf("ans : 5, 4, 3, 2\n");
}
