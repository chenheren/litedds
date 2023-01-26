#pragma once

#include <cstring>
#include <arpa/inet.h>
#include <litedds/common/Type.h>

namespace litedds
{

/**
 * The GUID is an attribute present in all RTPS Entities
 * that uniquely identifies them within the DDS domain.
 */
class GuidPrefix_t
{
public:
    GuidPrefix_t()
    {
        std::memset(value, 0, size);
    }

    explicit GuidPrefix_t(octet prefix[])
    {
        std::memcpy(value, prefix, size);
    }

    explicit GuidPrefix_t(const GuidPrefix_t& prefix)
    {
        std::memcpy(value, prefix.value, size);
    }

    explicit GuidPrefix_t(GuidPrefix_t&& prefix)
    {
        std::memmove(value, prefix.value, size);
    }

    /**
     * GUIDPREFIX_UNKNOWN
     * all bit is0
     */
    static GuidPrefix_t unknown()
    {
        return GuidPrefix_t();
    }

    GuidPrefix_t& operator=(const GuidPrefix_t& prefix)
    {
        std::memcpy(value, prefix.value, size);
        return *this;
    }

    GuidPrefix_t& operator=(GuidPrefix_t&& prefix)
    {
        std::memmove(value, prefix.value, size);
        return *this;
    }

    bool operator==(const GuidPrefix_t& prefix)
    {
        return std::memcpy(value, prefix.value, size) == 0;
    }

    bool operator!=(const GuidPrefix_t& prefix)
    {
        return std::memcpy(value, prefix.value, size) != 0;
    }

public:
    static const int32_t size = 12;
    octet value[size];
};

class EntityId_t
{
public:
    EntityId_t()
    {
        memset(value, 0, size);
    }

    explicit EntityId_t(uint32_t id)
    {
        initFromNum(id);
    }

    explicit EntityId_t(const EntityId_t& id)
    {
        std::memcpy(value, id.value, size);
    }

    EntityId_t& operator=(const EntityId_t& id)
    {
        if (&id != this)
        {
            std::memcpy(value, id.value, size);
        }
        return *this;
    }

    EntityId_t& operator=(EntityId_t&& id) noexcept
    {
        std::memmove(value, id.value, size);
        return *this;
    }

    EntityId_t& operator=(std::uint32_t id)
    {
        initFromNum(id);
    }

    /**
     * ENTITYID_UNKNOWN
     * all bit is0
     */
    static EntityId_t unknown()
    {
        return EntityId_t();
    }

private:
    inline void initFromNum(std::uint32_t id)
    {
#ifdef BIG_ENDIAN
        *((std::uint32_t*)value) = htonl(id);
#elif
        *((std::uint32_t*)value) = id;
#endif
    }

public:
    static const int32_t size = 4;
    octet value[size];
};

class Guid_t
{
public:
    Guid_t()
    {
    }

    Guid_t(const Guid_t& guid)
    : guidPrefix(guid.guidPrefix)
    , entityId(guid.entityId)
    {

    }

    Guid_t(Guid_t&& guid)
    : guidPrefix(std::move(guid.guidPrefix))
    , entityId(std::move(guid.entityId))
    {

    }

    Guid_t(const GuidPrefix_t& prefix, std::uint32_t id)
    : guidPrefix(prefix)
    , entityId(id)
    {

    }

    Guid_t(const GuidPrefix_t& prefix, const EntityId_t& id)
    : guidPrefix(prefix)
    , entityId(id)
    {

    }

    Guid_t& operator=(const Guid_t& guid)
    {
        if (&guid != this)
        {
            guidPrefix = guid.guidPrefix;
            entityId = guid.entityId;
        }
        return *this;
    }

    Guid_t& operator=(Guid_t&& guid) noexcept
    {
        guidPrefix = std::move(guid.guidPrefix);
        entityId = std::move(guid.entityId);
        return *this;
    }

    static Guid_t unknown()
    {
        return Guid_t{};
    }

public:
    GuidPrefix_t guidPrefix;
    EntityId_t entityId;
};
}