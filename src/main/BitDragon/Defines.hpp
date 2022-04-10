#pragma once
#include <cstdint>

typedef int8_t int8;
typedef int16_t int16;
typedef int32_t int32;
typedef int64_t int64;
typedef uint8_t uint8;
typedef uint16_t uint16;
typedef uint32_t uint32;
typedef uint64_t uint64;
typedef float float32;
typedef double float64;

#define BD_TAG_ID_CTAG_END		0x00
#define BD_TAG_ID_CTAG_START	0x01
#define BD_TAG_ID_NUMBER		0x02
#define BD_TAG_ID_STRING		0x03
#define BD_TAG_ID_ARRAY			0x04
#define BD_TAG_ID_COMPOUND		0x05

#define BD_TAG_DATA_TYPE_INT8	'b'
#define BD_TAG_DATA_TYPE_INT16	's'
#define BD_TAG_DATA_TYPE_INT32	'i'
#define BD_TAG_DATA_TYPE_INT64	'l'
#define BD_TAG_DATA_TYPE_FLOAT	'f'
#define BD_TAG_DATA_TYPE_DOUBLE	'd'
