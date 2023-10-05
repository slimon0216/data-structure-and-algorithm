#include <vector>

class Heap {
private:
  std::vector<int> v;

  size_t left(int i);
  size_t right(int i);
  size_t parent(int i);
  void heapify(int i);

public:
  Heap() { v.push_back(-1); };
  int top();
  void push(int x);
  void pop();
  int size();
};

size_t Heap::left(int i) { return 2 * i; }

size_t Heap::right(int i) { return 2 * i + 1; }

size_t Heap::parent(int i) { return i / 2; }

void Heap::heapify(int i) {
  size_t l = left(i);
  size_t r = right(i);
  int smallest = i;
  if (l < v.size() && v[l] < v[i])
    smallest = l;
  if (r < v.size() && v[r] < v[smallest])
    smallest = r;
  if (smallest != i) {
    std::swap(v[smallest], v[i]);
    heapify(smallest);
  }
}

void Heap::push(int x) {
  v.push_back(x);
  int cur = v.size() - 1;
  while (cur > 0 && v[parent(cur)] > v[cur]) {
    std::swap(v[parent(cur)], v[cur]);
    cur = parent(cur);
  }
}

int Heap::top() { return v[1]; }

int Heap::size() { return v.size() - 1; }

void Heap::pop() {
  v[1] = v.back();
  v.pop_back();
  heapify(1);
}