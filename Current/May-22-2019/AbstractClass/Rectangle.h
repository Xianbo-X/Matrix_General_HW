#include "Figure.h"

class RECTANGLE : public FIGURE {
 public:
  double get_area() { return (this->x_size * this->y_size); }
};