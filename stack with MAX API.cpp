// Copyright (c) 2013 Elements of Programming Interviews. All rights reserved.

#include <algorithm>
#include <cassert>
#include <iostream>
#include <stdexcept>
#include <string>
#include <utility>
#include <stack>

using namespace std;

// @include
class Stack {
public:
    void Push(int x);
    int Pop();
    const int Max() const;
    
private:
    std::stack<int> m_stack;
    std::stack<int> m_max_so_far;
    
};
    
void Stack::Push(int x) {
    m_stack.push(x);
    int max_so_far = 0;
    if (!m_max_so_far.empty()) {
        max_so_far = m_max_so_far.top();
        if (x > max_so_far)
            m_max_so_far.push(x);
        else
            m_max_so_far.push(max_so_far);
    }
    else {
        m_max_so_far.push(x);
    }
}
    
int Stack::Pop() {
    if (!m_stack.empty()) {
        int x = m_stack.top();
        m_stack.pop();
        m_max_so_far.pop();
    
        return x;
    }
}
    
const int Stack::Max() const {
    return m_max_so_far.top();
}

// @exclude

int main(int argc, char* argv[]) {
  Stack s;
  s.Push(1);
  s.Push(2);
  
  assert(s.Max() == 2);
  cout << s.Max() << endl;  // 2
  cout << s.Pop() << endl;  // 2

  cout << s.Max() << endl;  // 1
  assert(s.Max() == 1);
  s.Push(3);
  s.Push(2);
  assert(s.Max() == 3);
  cout << s.Max() << endl;  // 3
  s.Pop();
  assert(s.Max() == 3);
  cout << s.Max() << endl;  // 3
  s.Pop();
  assert(s.Max() == 1);
  cout << s.Max() << endl;  // 1
  //s.Pop();
  try {
    s.Max();
    s.Pop();
    s.Pop();
    //s.Pop();
    //s.Pop();
  }
  catch (const std::exception& e) {
    cout << e.what() << endl;
  }
  
  return 0;
}
