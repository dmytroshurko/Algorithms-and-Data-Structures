#ifndef DATA_STRUCTURES_PRIORITY_QUEUE_NODE_H_
#define DATA_STRUCTURES_PRIORITY_QUEUE_NODE_H_

template <class T>
class Node {
public:
  Node() = default;
  Node(int priority, T data) : priority_(priority), data_(data) {}
  ~Node() = default;

  int GetPriority() const { return priority_; }
  T GetData() const { return data_; }

private:
  int priority_;
  T data_;
};

#endif  // DATA_STRUCTURES_PRIORITY_QUEUE_NODE_H_
