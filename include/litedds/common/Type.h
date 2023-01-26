#pragma once

#include <stdint.h>

namespace litedds
{
using octet = char;

#if __BYTE_ORDER__ ==__ORDER_BIG_ENDIAN__
#define BIG_ENDIAN
#endif
}