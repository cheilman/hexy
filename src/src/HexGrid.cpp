#include "HexGrid.h"

namespace Hexy {

void HexGrid::AddHex(const Hex& hex) { hexes_.emplace(std::make_pair(hex.q(), hex.r()), hex); }

std::optional<std::reference_wrapper<const Hex>> HexGrid::GetHex(int q, int r) const {
  auto it = hexes_.find(std::make_pair(q, r));
  if (it != hexes_.end()) {
    return std::cref(it->second);
  }
  return std::nullopt;
}

}  // namespace Hexy