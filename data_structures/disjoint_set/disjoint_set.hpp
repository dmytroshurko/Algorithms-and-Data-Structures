#ifndef DATA_STRUCTURES_DISJOINT_SET_DISJOINT_SET_H_
#define DATA_STRUCTURES_DISJOINT_SET_DISJOINT_SET_H_

#include <utility>
#include <vector>

namespace ds {

  class DisjointSet {
  public:
    DisjointSet(size_t n);

    // Creates a singleton set {x}.
    void MakeSet(size_t x);

    // Returns the ID of the set containing x.
    size_t Find(size_t x);

    // Checks whether a particular cell is reachable from the other cell.
    bool IsReachable(size_t a, size_t b);

    // Merges two sets containing x and y.
    void Union(size_t x, size_t y);

  private:
    std::vector<int> parent_;
    // The vector in which we keep the height of each subtree.
    // rank_[i] is the height of the subtree whose root is i.
    std::vector<int> rank_;
  };

}  // namespace ds

#endif  // DATA_STRUCTURES_DISJOINT_SET_DISJOINT_SET_H_
