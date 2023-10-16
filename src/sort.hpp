#include <iostream>
#include <vector>

using namespace std;

namespace mydsa {

void merge(vector<int> &nums, int l, int m, int r) {

  vector<int> tmp(r - l + 1);

  int i = l, j = m + 1;
  int k = 0;
  while (i <= m && j <= r) {
    if (nums[i] < nums[j])
      tmp[k++] = nums[i++];
    else
      tmp[k++] = nums[j++];
  }

  while (i <= m)
    tmp[k++] = nums[i++];
  while (j <= r)
    tmp[k++] = nums[j++];
  for (int i = l; i <= r; ++i)
    nums[i] = tmp[i - l];
}

void mergeSort(vector<int> &nums, int l, int r) {
  int m = l + (r - l) / 2;
  if (l == r)
    return;
  mergeSort(nums, l, m);
  mergeSort(nums, m + 1, r);

  merge(nums, l, m, r);
}

void insertionSort(vector<int> &nums) {
  for (size_t i = 1; i < nums.size(); ++i) {
    size_t j = i;
    while (j > 0 && nums[j - 1] > nums[j]) {
      swap(nums[j - 1], nums[j]);
      j--;
    }
  }
}

void selectionSort(vector<int> &nums) {
  for (size_t i = 0; i < nums.size(); ++i) {
    int minIdx = i;
    for (size_t j = i + 1; j < nums.size(); ++j) {
      if (nums[j] < nums[minIdx])
        minIdx = j;
    }
    swap(nums[i], nums[minIdx]);
  }
}

void bubbleSort(vector<int> &nums) {
  for (size_t i = 0; i < nums.size(); ++i) {
    for (size_t j = 1; j < nums.size() - i; ++j) {
      if (nums[j - 1] > nums[j])
        swap(nums[j - 1], nums[j]);
    }
  }
}

} // namespace mydsa