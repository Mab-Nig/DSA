#include <bits/stdc++.h>
#include <queue>

class MyStack {
public:
  MyStack() : m_first(&m_q[0]), m_second(&m_q[1]) {}

  void push(int x) {
    m_first->push(x);
  }

  int pop() {
    int res;
    while (m_first->size() > 1) {
      m_second->push(m_first->front());
      m_first->pop();
    }
    res = m_first->front();
    m_first->pop();
    std::swap(m_first, m_second);
    return res;
  }

  int top() {
    return m_first->back();
  }

  bool empty() {
    return m_first->empty();
  }

private:
  std::queue<int> m_q[2];
  std::queue<int> *m_first, *m_second;
};
