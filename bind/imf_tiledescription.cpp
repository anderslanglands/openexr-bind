#include <OpenEXR/ImfTileDescription.h>

#include <cppmm_bind.hpp>

namespace cppmm_bind {

namespace OPENEXR_IMF_INTERNAL_NAMESPACE {

namespace Imf = ::OPENEXR_IMF_INTERNAL_NAMESPACE;

enum LevelMode {};
enum LevelRoundingMode {};

struct TileDescription {
    using BoundType = Imf::TileDescription;

    TileDescription(unsigned int xs, unsigned int ys, Imf::LevelMode m,
                    Imf::LevelRoundingMode r);
    bool operator==(const Imf::TileDescription& other);

} CPPMM_VALUETYPE;

} // namespace OPENEXR_IMF_INTERNAL_NAMESPACE

} // namespace cppmm_bind
