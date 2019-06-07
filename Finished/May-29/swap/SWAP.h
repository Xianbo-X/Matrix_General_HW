#ifndef SWAP_H_
#define SWAP_H_

namespace myNamespace {
template <class T>
void swap(T &a, T &b) {
  T temp = a;
  a = b;
  b = temp;
}
}  // namespace myNamespace
#endif