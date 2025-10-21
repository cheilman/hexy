#ifndef HEXY_HEX_GRID_H_
#define HEXY_HEX_GRID_H_

#include <functional>  // For std::reference_wrapper
#include <map>
#include <optional>  // For std::optional
#include <utility>   // For std::pair

#include "Hex.h"

namespace Hexy {

class HexGrid {
 public:
  HexGrid() = default;

  void AddHex(const Hex& hex);
  std::optional<std::reference_wrapper<const Hex>> GetHex(int q, int r) const;

 private:
  std::map<std::pair<int, int>, Hex> hexes_;
};

}  // namespace Hexy

#endif  // HEXY_HEX_GRID_H_