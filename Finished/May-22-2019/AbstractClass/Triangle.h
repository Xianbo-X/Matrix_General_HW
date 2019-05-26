#include "Figure.h"

class TRIANGLE : public FIGURE {
 public:
  double get_area() { return this->x_size * this->y_size / 2; }
};