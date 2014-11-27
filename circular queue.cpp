#include <algorithm>
#include <cassert>
#include <iostream>
#include <stdexcept>
#include <vector>

using std::cout;
using std::endl;
using std::exception;
using std::length_error;
using std::vector;

// @include
class Queue {
 public:
  Queue(size_t cap) : m_data(cap)  {}

  void Enqueue(int x) {
      m_data[m_tail++] = x;
      m_num_elements++;

      if (m_num_elements >= m_data.size()/2) {
          m_data.resize(m_data.size()*2);
      }
      if (m_tail >= m_data.size()) {
          m_tail = 0;
      }
  }

  int Dequeue() {
      if (m_num_elements ==0) {
          throw std::runtime_error("queue size is zero, do not dequeue!\n");
      }
      int output = m_data[m_head++];
      m_num_elements--;
      if (m_head >= m_data.size()) {
          m_head = 0;
      }
      printf("output=%d\n",output);
      return output;
  }

  size_t size() const { return m_num_elements; }

 private:
    vector<int> m_data;
    int m_head = 0;
    int m_tail = 0;
    int m_num_elements = 0;
};
// @exclude

void Test() {
  Queue q(8);
  q.Enqueue(1);
  q.Enqueue(2);
  q.Enqueue(3);
  q.Enqueue(4);
  q.Enqueue(5);
  q.Enqueue(6);
  q.Enqueue(7);
  q.Enqueue(8);
  // Now head = 0 and tail = 0

  assert(1 == q.Dequeue());
  assert(2 == q.Dequeue());
  assert(3 == q.Dequeue());
  // Now head = 3 and tail = 0

  q.Enqueue(11);
  q.Enqueue(12);
  q.Enqueue(13);
  // Ok till here. Now head = 3 and tail = 3

  q.Enqueue(14);  // now the vector (data) is resized; but the head and tail.
                  // (or elements) does not change accordingly.
  q.Enqueue(15);
  q.Enqueue(16);
  q.Enqueue(17);
  q.Enqueue(18);
  // The elements starting from head=3 are overwritten!

  assert(4 == q.Dequeue());
  assert(5 == q.Dequeue());
  assert(6 == q.Dequeue());
  assert(7 == q.Dequeue());
  assert(8 == q.Dequeue());
  assert(11 == q.Dequeue());
  assert(12 == q.Dequeue());
}

int main(int argc, char* argv[]) {
  Test();
  Queue q(8);
  q.Enqueue(1);
  q.Enqueue(2);
  q.Enqueue(3);
  assert(1 == q.Dequeue());
  q.Enqueue(4);
  assert(2 == q.Dequeue());
  assert(3 == q.Dequeue());
  assert(4 == q.Dequeue());
  try {
    printf("size is %d\n", q.size());
    q.Dequeue();
  }
  catch (const exception& e) {
    cout << e.what() << endl;
  }
  // test resize().
  q.Enqueue(4);
  q.Enqueue(4);
  q.Enqueue(4);
  q.Enqueue(4);
  q.Enqueue(4);
  q.Enqueue(4);
  q.Enqueue(4);
  q.Enqueue(4);
  q.Enqueue(4);
  assert(q.size() == 9);
  return 0;
}
