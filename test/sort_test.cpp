#include "../src/sort.hpp"
#include <gtest/gtest.h>

// Demonstrate some basic assertions.
TEST(MergeSort, Test) {
  std::vector<int> nums;
  for (int i = 0; i < 200; ++i) {
    nums.push_back(rand() % 100);
  }
  auto ans = nums;

  mydsa::mergeSort(nums, 0, nums.size() - 1);

  std::sort(ans.begin(), ans.end());
  EXPECT_EQ(nums, ans);
}

TEST(InsertionSort, Test) {
  std::vector<int> nums;
  for (int i = 0; i < 200; ++i) {
    nums.push_back(rand() % 100);
  }
  auto ans = nums;

  mydsa::insertionSort(nums);

  std::sort(ans.begin(), ans.end());
  EXPECT_EQ(nums, ans);
}

TEST(SelectionSort, Test) {
  std::vector<int> nums;
  for (int i = 0; i < 200; ++i) {
    nums.push_back(rand() % 100);
  }
  auto ans = nums;

  mydsa::selectionSort(nums);

  std::sort(ans.begin(), ans.end());
  EXPECT_EQ(nums, ans);
}

TEST(BubbleSort, Test) {
  std::vector<int> nums;
  for (int i = 0; i < 200; ++i) {
    nums.push_back(rand() % 100);
  }
  auto ans = nums;

  mydsa::bubbleSort(nums);

  std::sort(ans.begin(), ans.end());
  EXPECT_EQ(nums, ans);
}
