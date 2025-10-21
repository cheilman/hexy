#include "Hex.h"
#include "HexGrid.h"
#include "TerrainType.h"
#include "gtest/gtest.h"

TEST(TerrainTypeTest, EnumValues) {
  ASSERT_EQ(static_cast<int>(Hexy::TerrainType::BORDER), 0);
  ASSERT_EQ(static_cast<int>(Hexy::TerrainType::GRASS), 1);
  ASSERT_EQ(static_cast<int>(Hexy::TerrainType::SAND), 2);
  ASSERT_EQ(static_cast<int>(Hexy::TerrainType::WATER), 3);
  ASSERT_EQ(static_cast<int>(Hexy::TerrainType::MOUNTAIN), 4);
}

TEST(HexTest, CubeCoordinatesConstructor) {
  Hexy::Hex hex(1, 2, -3, Hexy::TerrainType::GRASS);
  ASSERT_EQ(hex.q(), 1);
  ASSERT_EQ(hex.r(), 2);
  ASSERT_EQ(hex.s(), -3);
  ASSERT_EQ(hex.type(), Hexy::TerrainType::GRASS);
}

TEST(HexTest, AxialCoordinatesConstructor) {
  Hexy::Hex hex(1, 2, Hexy::TerrainType::SAND);
  ASSERT_EQ(hex.q(), 1);
  ASSERT_EQ(hex.r(), 2);
  ASSERT_EQ(hex.s(), -3);  // s = -q - r = -1 - 2 = -3
  ASSERT_EQ(hex.type(), Hexy::TerrainType::SAND);
}

TEST(HexGridTest, AddAndGetHex) {
  Hexy::HexGrid grid;
  Hexy::Hex hex1(0, 0, 0, Hexy::TerrainType::WATER);
  Hexy::Hex hex2(1, -1, 0, Hexy::TerrainType::MOUNTAIN);

  grid.AddHex(hex1);
  grid.AddHex(hex2);

  std::optional<std::reference_wrapper<const Hexy::Hex>> retrievedHex1 = grid.GetHex(0, 0);
  ASSERT_TRUE(retrievedHex1.has_value());
  ASSERT_EQ(retrievedHex1->get().q(), 0);
  ASSERT_EQ(retrievedHex1->get().r(), 0);
  ASSERT_EQ(retrievedHex1->get().s(), 0);
  ASSERT_EQ(retrievedHex1->get().type(), Hexy::TerrainType::WATER);

  std::optional<std::reference_wrapper<const Hexy::Hex>> retrievedHex2 = grid.GetHex(1, -1);
  ASSERT_TRUE(retrievedHex2.has_value());
  ASSERT_EQ(retrievedHex2->get().q(), 1);
  ASSERT_EQ(retrievedHex2->get().r(), -1);
  ASSERT_EQ(retrievedHex2->get().s(), 0);
  ASSERT_EQ(retrievedHex2->get().type(), Hexy::TerrainType::MOUNTAIN);

  std::optional<std::reference_wrapper<const Hexy::Hex>> nonExistentHex = grid.GetHex(99, 99);
  ASSERT_FALSE(nonExistentHex.has_value());
}
