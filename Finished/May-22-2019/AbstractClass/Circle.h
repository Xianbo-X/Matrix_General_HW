#include "Figure.h"

class CIRCLE : public FIGURE {
 public:
  double get_area() { return (PI * this->x_size * this->x_size); };
};