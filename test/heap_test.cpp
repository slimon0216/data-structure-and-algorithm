#include "../src/heap.hpp"
#include <gtest/gtest.h>

// Demonstrate some basic assertions.
TEST(HeapTest, Basic) {
  // Expect two strings not to be equal.
  Heap heap;
  heap.push(3);
  heap.push(2);
  heap.push(1);
  EXPECT_EQ(heap.top(), 1);

  heap.pop();
  EXPECT_EQ(heap.top(), 2);
}

TEST(HeapTest, Sort) {
  Heap pq;
  srand(time(NULL));
  std::vector<int> ans;
  for (int i = 0; i < 1000000; ++i) {
    int x = rand() % 1000;
    pq.push(x);
    ans.push_back(x);
  }

  std::sort(ans.begin(), ans.end());

  for (auto x : ans) {
    EXPECT_EQ(x, pq.top());
    pq.pop();
  }

  EXPECT_EQ(pq.size(), 0);
}