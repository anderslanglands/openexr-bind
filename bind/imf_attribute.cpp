// FIXME: should we split these out into multiple TUs?
#include <OpenEXR/ImfAttribute.h>
#include <OpenEXR/ImfBoxAttribute.h>
#include <OpenEXR/ImfChannelListAttribute.h>
#include <OpenEXR/ImfChromaticitiesAttribute.h>
#include <OpenEXR/ImfCompressionAttribute.h>
#include <OpenEXR/ImfDeepImageStateAttribute.h>
#include <OpenEXR/ImfEnvmapAttribute.h>
#include <OpenEXR/ImfFloatVectorAttribute.h>
#include <OpenEXR/ImfKeyCodeAttribute.h>
#include <OpenEXR/ImfLineOrderAttribute.h>
#include <OpenEXR/ImfMatrixAttribute.h>
#include <OpenEXR/ImfPreviewImageAttribute.h>
#include <OpenEXR/ImfRationalAttribute.h>
#include <OpenEXR/ImfStringAttribute.h>
#include <OpenEXR/ImfStringVectorAttribute.h>
#include <OpenEXR/ImfTileDescriptionAttribute.h>
#include <OpenEXR/ImfTimeCodeAttribute.h>
#include <OpenEXR/ImfVecAttribute.h>

#include <cppmm_bind.hpp>

#include <vector>

namespace cppmm_bind {

namespace OPENEXR_IMF_INTERNAL_NAMESPACE {

namespace Imf = ::OPENEXR_IMF_INTERNAL_NAMESPACE;

class Attribute {
public:
    using BoundType = Imf::Attribute;

    virtual const char* typeName() const = 0;
    virtual Imf::Attribute* copy() const = 0;

    virtual void writeValueTo(Imf::OStream& os, int version) const = 0;

    virtual void readValueFrom(Imf::IStream& is, int size, int version) = 0;

    virtual void copyValueFrom(const Imf::Attribute& other) = 0;

    IMF_EXPORT
    static Imf::Attribute* newAttribute(const char typeName[]);

    IMF_EXPORT
    static bool knownType(const char typeName[]);

} CPPMM_OPAQUEPTR;

template <class T> class TypedAttribute : public Attribute {
public:
    using BoundType = Imf::TypedAttribute<T>;

    TypedAttribute() CPPMM_RENAME(ctor);
    TypedAttribute(const T& value) CPPMM_RENAME(from_value);
    TypedAttribute(const TypedAttribute<T>& other) CPPMM_RENAME(ctor_copy);

    virtual ~TypedAttribute() CPPMM_RENAME(dtor);

    Imf::TypedAttribute<T>& operator=(const TypedAttribute<T>& other)
        CPPMM_RENAME(assign);

    T& value();
    const T& value() const CPPMM_RENAME(value_const);

    virtual const char* typeName() const;
    static const char* staticTypeName();
    static Imf::Attribute* makeNewAttribute();
    virtual Imf::Attribute* copy() const;

    virtual void writeValueTo(Imf::OStream& os, int version) const;

    virtual void readValueFrom(Imf::IStream& is, int size, int version);

    virtual void copyValueFrom(const Attribute& other);

    static Imf::TypedAttribute<T>* cast(Attribute* attribute)
        CPPMM_RENAME(cast_ptr) CPPMM_THROWS(Iex::TypeExc, IEX_INVALID_TYPE);
    static const Imf::TypedAttribute<T>* cast(const Imf::Attribute* attribute)
        CPPMM_RENAME(cast_ptr_const)
            CPPMM_THROWS(Iex::TypeExc, IEX_INVALID_TYPE);
    static Imf::TypedAttribute<T>& cast(Attribute& attribute) CPPMM_RENAME(cast)
        CPPMM_THROWS(Iex::TypeExc, IEX_INVALID_TYPE);
    static const Imf::TypedAttribute<T>& cast(const Imf::Attribute& attribute)
        CPPMM_RENAME(cast_const) CPPMM_THROWS(Iex::TypeExc, IEX_INVALID_TYPE);

    static void registerAttributeType();
    static void unRegisterAttributeType();
} CPPMM_OPAQUEPTR;

template class TypedAttribute<int>;
using IntAttribute = Imf::TypedAttribute<int>;

template class TypedAttribute<float>;
using FloatAttribute = Imf::TypedAttribute<float>;

template class TypedAttribute<double>;
using DoubleAttribute = Imf::TypedAttribute<double>;

template class TypedAttribute<Imath::Box2i>;
using Box2iAttribute = Imf::TypedAttribute<Imath::Box2i>;

template class TypedAttribute<Imath::Box2f>;
using Box2fAttribute = Imf::TypedAttribute<Imath::Box2f>;

template class TypedAttribute<Imf::ChannelList>;
using ChannelListAttribute = Imf::TypedAttribute<Imf::ChannelList>;

template class TypedAttribute<Imf::Chromaticities>;
using ChromaticitiesAttribute = Imf::TypedAttribute<Imf::Chromaticities>;

template class TypedAttribute<Imf::Compression>;
using CompressionAttribute = Imf::TypedAttribute<Imf::Compression>;

template class TypedAttribute<Imf::DeepImageState>;
using DeepImageStateAttribute = Imf::TypedAttribute<Imf::DeepImageState>;

template class TypedAttribute<Imf::Envmap>;
using EnvmapAttribute = Imf::TypedAttribute<Imf::Envmap>;

template class TypedAttribute<std::vector<float>>;
using FloatVectorAttribute = Imf::TypedAttribute<std::vector<float>>;

template class TypedAttribute<std::vector<std::string>>;
using StringVectorAttribute = Imf::TypedAttribute<std::vector<std::string>>;

template class TypedAttribute<std::string>;
using StringAttribute = Imf::TypedAttribute<std::string>;

template class TypedAttribute<Imf::KeyCode>;
using KeyCodeAttribute = Imf::TypedAttribute<Imf::KeyCode>;

template class TypedAttribute<Imf::LineOrder>;
using LineOrderAttribute = Imf::TypedAttribute<Imf::LineOrder>;

template class TypedAttribute<Imath::M33f>;
using M33fAttribute = Imf::TypedAttribute<Imath::M33f>;

template class TypedAttribute<Imath::M33d>;
using M33dAttribute = Imf::TypedAttribute<Imath::M33d>;

template class TypedAttribute<Imath::M44f>;
using M44fAttribute = Imf::TypedAttribute<Imath::M44f>;

template class TypedAttribute<Imath::M44d>;
using M44dAttribute = Imf::TypedAttribute<Imath::M44d>;

template class TypedAttribute<Imf::PreviewImage>;
using PreviewImageAttribute = Imf::TypedAttribute<Imf::PreviewImage>;

template class TypedAttribute<Imf::Rational>;
using RationalAttribute = Imf::TypedAttribute<Imf::Rational>;

template class TypedAttribute<Imf::TileDescription>;
using TileDescriptionAttribute = Imf::TypedAttribute<Imf::TileDescription>;

template class TypedAttribute<Imf::TimeCode>;
using TimeCodeAttribute = Imf::TypedAttribute<Imf::TimeCode>;

template class TypedAttribute<Imath::V2i>;
using V2iAttribute = Imf::TypedAttribute<Imath::V2i>;

template class TypedAttribute<Imath::V2f>;
using V2fAttribute = Imf::TypedAttribute<Imath::V2f>;

template class TypedAttribute<Imath::V2d>;
using V2dAttribute = Imf::TypedAttribute<Imath::V2d>;

template class TypedAttribute<Imath::V3i>;
using V3iAttribute = Imf::TypedAttribute<Imath::V3i>;

template class TypedAttribute<Imath::V3f>;
using V3fAttribute = Imf::TypedAttribute<Imath::V3f>;

template class TypedAttribute<Imath::V3d>;
using V3dAttribute = Imf::TypedAttribute<Imath::V3d>;

} // namespace OPENEXR_IMF_INTERNAL_NAMESPACE

namespace std {

template <typename T> struct vector {
    using BoundType = ::std::vector<T>;
} CPPMM_OPAQUEBYTES;

template class vector<float>;
using vector_float = std::vector<float>;

} // namespace std

} // namespace cppmm_bind

template class Imf::TypedAttribute<int>;
template class Imf::TypedAttribute<float>;
template class Imf::TypedAttribute<double>;
template class Imf::TypedAttribute<Imath::Box2i>;
template class Imf::TypedAttribute<Imath::Box2f>;
template class Imf::TypedAttribute<Imf::ChannelList>;
template class Imf::TypedAttribute<Imf::Chromaticities>;
template class Imf::TypedAttribute<Imf::Compression>;
template class Imf::TypedAttribute<Imf::DeepImageState>;
template class Imf::TypedAttribute<Imf::Envmap>;
template class Imf::TypedAttribute<Imf::KeyCode>;
template class Imf::TypedAttribute<Imf::LineOrder>;
template class Imf::TypedAttribute<Imath::M33f>;
template class Imf::TypedAttribute<Imath::M33d>;
template class Imf::TypedAttribute<Imath::M44f>;
template class Imf::TypedAttribute<Imath::M44d>;
template class Imf::TypedAttribute<Imf::PreviewImage>;
template class Imf::TypedAttribute<Imf::Rational>;
template class Imf::TypedAttribute<Imf::TimeCode>;
template class Imf::TypedAttribute<Imf::TileDescription>;
template class Imf::TypedAttribute<std::vector<float>>;
template class Imf::TypedAttribute<std::vector<std::string>>;
template class Imf::TypedAttribute<std::string>;
template class Imf::TypedAttribute<Imath::V2i>;
template class Imf::TypedAttribute<Imath::V2f>;
template class Imf::TypedAttribute<Imath::V2d>;
template class Imf::TypedAttribute<Imath::V3i>;
template class Imf::TypedAttribute<Imath::V3f>;
template class Imf::TypedAttribute<Imath::V3d>;

template class std::vector<float>;
