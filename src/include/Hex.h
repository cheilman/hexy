#ifndef HEXY_HEX_H_
#define HEXY_HEX_H_

#include "TerrainType.h"

namespace Hexy {

class Hex {
 public:
  Hex(int q, int r, int s, TerrainType type);
  Hex(int q, int r, TerrainType type);  // Axial coordinates constructor

  int q() const { return q_; }
  int r() const { return r_; }
  int s() const { return s_; }
  TerrainType type() const { return type_; }

 private:
  int q_;
  int r_;
  int s_;
  TerrainType type_;
};

}  // namespace Hexy

#endif  // HEXY_HEX_H_