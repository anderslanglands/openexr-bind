#include <OpenEXR/ImfDeepImageLevel.h>

#include <cppmm_bind.hpp>

namespace cppmm_bind {

namespace OPENEXR_IMF_INTERNAL_NAMESPACE {

namespace Imf = ::OPENEXR_IMF_INTERNAL_NAMESPACE;

struct DeepImageLevel {
    using BoundType = Imf::DeepImageLevel;

    // Inherited from ImageLevel
    Imf::Image& image();
    const Imf::Image& image() const CPPMM_RENAME(image_const);

    int xLevelNumber() const;
    int yLevelNumber() const;

    const IMATH_NAMESPACE::Box2i& dataWindow() const;

    IMFUTIL_EXPORT
    Imf::DeepImage& deepImage();
    IMFUTIL_EXPORT
    const Imf::DeepImage& deepImage() const CPPMM_RENAME(deepImage_const);

    IMFUTIL_EXPORT
    Imf::DeepImageChannel* findChannel(const std::string& name);
    IMFUTIL_EXPORT
    const Imf::DeepImageChannel* findChannel(const std::string& name) const
        CPPMM_RENAME(findChannel_const);

    IMFUTIL_EXPORT
    Imf::DeepImageChannel& channel(const std::string& name)
        CPPMM_THROWS(Iex::ArgExc, IEX_INVALID_ARGUMENT);
    IMFUTIL_EXPORT
    const Imf::DeepImageChannel& channel(const std::string& name) const
        CPPMM_RENAME(channel_const)
            CPPMM_THROWS(Iex::ArgExc, IEX_INVALID_ARGUMENT);

    template <class T>
    Imf::TypedDeepImageChannel<T>* findTypedChannel(const std::string& name);

    template <class T>
    const Imf::TypedDeepImageChannel<T>*
    findTypedChannel(const std::string& name) const;

    template <class T>
    Imf::TypedDeepImageChannel<T>& typedChannel(const std::string& name)
        CPPMM_THROWS(Iex::ArgExc, IEX_INVALID_ARGUMENT) CPPMM_IGNORE;

    template <class T>
    const Imf::TypedDeepImageChannel<T>&
    typedChannel(const std::string& name) const
        CPPMM_THROWS(Iex::ArgExc, IEX_INVALID_ARGUMENT) CPPMM_IGNORE;

    IMFUTIL_EXPORT
    Imf::DeepImageLevel::Iterator begin();
    IMFUTIL_EXPORT
    Imf::DeepImageLevel::ConstIterator begin() const CPPMM_RENAME(begin_const);

    IMFUTIL_EXPORT
    Imf::DeepImageLevel::Iterator end();
    IMFUTIL_EXPORT
    Imf::DeepImageLevel::ConstIterator end() const CPPMM_RENAME(end_const);

    IMFUTIL_EXPORT
    Imf::SampleCountChannel& sampleCounts();
    IMFUTIL_EXPORT
    const Imf::SampleCountChannel& sampleCounts() const
        CPPMM_RENAME(sampleCounts_const);

    struct Iterator {
        using BoundType = Imf::DeepImageLevel::Iterator;
        IMFUTIL_EXPORT
        Iterator();
        IMFUTIL_EXPORT
        Iterator(const Imf::DeepImageLevel::ChannelMap::iterator& i)
            CPPMM_IGNORE;

        Iterator(const Imf::DeepImageLevel::Iterator& rhs);
        Iterator(Imf::DeepImageLevel::Iterator&& rhs);

        IMFUTIL_EXPORT
        Imf::DeepImageLevel::Iterator& operator++() CPPMM_RENAME(inc);
        IMFUTIL_EXPORT
        Imf::DeepImageLevel::Iterator operator++(int) CPPMM_IGNORE;

        IMFUTIL_EXPORT
        const std::string& name() const;
        IMFUTIL_EXPORT
        Imf::DeepImageChannel& channel() const;

    } CPPMM_OPAQUEBYTES;

    struct ConstIterator {
        using BoundType = Imf::DeepImageLevel::ConstIterator;

        IMFUTIL_EXPORT
        ConstIterator();
        IMFUTIL_EXPORT
        ConstIterator(const Imf::DeepImageLevel::ChannelMap::const_iterator& i)
            CPPMM_IGNORE;

        ConstIterator(const Imf::DeepImageLevel::ConstIterator& rhs);
        ConstIterator(Imf::DeepImageLevel::ConstIterator&& rhs);
        ConstIterator(const Imf::DeepImageLevel::Iterator& rhs)
            CPPMM_RENAME(from_mut);

        IMFUTIL_EXPORT
        Imf::DeepImageLevel::ConstIterator& operator++() CPPMM_RENAME(inc);
        IMFUTIL_EXPORT
        Imf::DeepImageLevel::ConstIterator operator++(int) CPPMM_IGNORE;

        IMFUTIL_EXPORT
        const std::string& name() const;
        IMFUTIL_EXPORT
        const Imf::DeepImageChannel& channel() const;

    } CPPMM_OPAQUEBYTES;

} CPPMM_OPAQUEPTR;

// ------------ TypedChannel<half> ---------------------
extern template Imf::TypedDeepImageChannel<Imath::half>*
DeepImageLevel::findTypedChannel(const std::string& name);

extern template const Imf::TypedDeepImageChannel<Imath::half>*
DeepImageLevel::findTypedChannel(const std::string& name) const;

Imf::TypedDeepImageChannel<Imath::half>* (
    DeepImageLevel::*findTypedChannel_half)(const std::string& name) =
    &DeepImageLevel::findTypedChannel<Imath::half>;

const Imf::TypedDeepImageChannel<Imath::half>* (
    DeepImageLevel::*findTypedChannel_half_const)(const std::string& name)
    const = &DeepImageLevel::findTypedChannel<Imath::half>;

// ------------ TypedChannel<float> ---------------------
extern template Imf::TypedDeepImageChannel<float>*
DeepImageLevel::findTypedChannel(const std::string& name);

extern template const Imf::TypedDeepImageChannel<float>*
DeepImageLevel::findTypedChannel(const std::string& name) const;

Imf::TypedDeepImageChannel<float>* (DeepImageLevel::*findTypedChannel_float)(
    const std::string& name) = &DeepImageLevel::findTypedChannel<float>;

const Imf::TypedDeepImageChannel<float>* (
    DeepImageLevel::*findTypedChannel_float_const)(
    const std::string& name) const = &DeepImageLevel::findTypedChannel<float>;

// ------------ TypedChannel<uint> ---------------------
extern template Imf::TypedDeepImageChannel<unsigned int>*
DeepImageLevel::findTypedChannel(const std::string& name);

extern template const Imf::TypedDeepImageChannel<unsigned int>*
DeepImageLevel::findTypedChannel(const std::string& name) const;

Imf::TypedDeepImageChannel<unsigned int>* (
    DeepImageLevel::*findTypedChannel_uint)(const std::string& name) =
    &DeepImageLevel::findTypedChannel<unsigned int>;

const Imf::TypedDeepImageChannel<unsigned int>* (
    DeepImageLevel::*findTypedChannel_uint_const)(const std::string& name)
    const = &DeepImageLevel::findTypedChannel<unsigned int>;

} // namespace OPENEXR_IMF_INTERNAL_NAMESPACE

} // namespace cppmm_bind

// ------------ TypedDeepImageChannel<half> ---------------------
extern template Imf::TypedDeepImageChannel<Imath::half>*
Imf::DeepImageLevel::findTypedChannel(const std::string& name);

extern template const Imf::TypedDeepImageChannel<Imath::half>*
Imf::DeepImageLevel::findTypedChannel(const std::string& name) const;

// ------------ TypedDeepImageChannel<float> ---------------------
extern template Imf::TypedDeepImageChannel<float>*
Imf::DeepImageLevel::findTypedChannel(const std::string& name);

extern template const Imf::TypedDeepImageChannel<float>*
Imf::DeepImageLevel::findTypedChannel(const std::string& name) const;

// ------------ TypedDeepImageChannel<unsigned int> ---------------------
extern template Imf::TypedDeepImageChannel<unsigned int>*
Imf::DeepImageLevel::findTypedChannel(const std::string& name);

extern template const Imf::TypedDeepImageChannel<unsigned int>*
Imf::DeepImageLevel::findTypedChannel(const std::string& name) const;
