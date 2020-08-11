#include "disjoint_set.hpp"

namespace ds {

  DisjointSet::DisjointSet(size_t n) : parent_(n, 0), rank_(n, 0) {}

  void DisjointSet::MakeSet(size_t x) {
    parent_[x] = x;
    rank_[x] = 0;
  }

  // uses Path Compression heuristic
  size_t DisjointSet::Find(size_t x) {
    if (x != parent_[x]) {
      parent_[x] = Find(parent_[x]);
    }
    return parent_[x];
  }

  bool DisjointSet::IsReachable(size_t a, size_t b) { return Find(a) == Find(b); }

  // uses Union by Rank heuristic
  void DisjointSet::Union(size_t x, size_t y) {
    size_t x_id = Find(x);
    size_t y_id = Find(y);

    if (x_id != y_id) {
      if (rank_[x_id] < rank_[y_id]) {
        std::swap(x_id, y_id);
      }
      parent_[y_id] = x_id;
      if (rank_[x_id] == rank_[y_id]) {
        ++rank_[x_id];
      }
    }
  }

}  // namespace ds