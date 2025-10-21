#include "Hex.h"

namespace Hexy {

Hex::Hex(int q, int r, int s, TerrainType type) : q_(q), r_(r), s_(s), type_(type) {}

Hex::Hex(int q, int r, TerrainType type) : q_(q), r_(r), s_(-q - r), type_(type) {}

}  // namespace Hexy