#ifndef DATA_STRUCTURES_LINKED_LIST_NODE_H_
#define DATA_STRUCTURES_LINKED_LIST_NODE_H_

template <class T>
class Node {
public:
  Node(const T& value) : value_(value), next_(nullptr), prev_(nullptr) {}
  ~Node() = default;
  Node& operator=(const Node& node) = default;

  T GetValue() const { return value_; }
  void SetValue(const T& value) { value_ = value; }
  Node<T>* GetNext() const { return next_; }
  void SetNext(Node<T>* next) { next_ = next; }
  Node<T>* GetPrev() const { return prev_; }
  void SetPrev(Node<T>* prev) { prev_ = prev; }

private:
  T value_;
  Node<T>* next_;
  Node<T>* prev_;
};

#endif  // DATA_STRUCTURES_LINKED_LIST_NODE_H_
