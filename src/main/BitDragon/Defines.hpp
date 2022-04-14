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

#define BD_TAG_ID_CTAG_END		0x00	// The end of a compound tag
#define BD_TAG_ID_CTAG_START	0x01	// The start of a compound tag
#define BD_TAG_ID_NUMBER		0x02	// A int
#define BD_TAG_ID_NUMBER_FLOAT	0x03	// A number with floatings
#define BD_TAG_ID_STRING		0x04	// A String
#define BD_TAG_ID_ARRAY			0x05	// An array
#define BD_TAG_ID_ARRAY_FLOAT	0x06	// An array with floatings
#define BD_TAG_ID_COMPOUND		0x07	// A Compound

#define BD_TAG_TYPE_UINT8			0x00
#define BD_TAG_TYPE_UINT16			0x01
#define BD_TAG_TYPE_UINT32			0x02
#define BD_TAG_TYPE_UINT64			0x03
#define BD_TAG_TYPE_FLOAT			0x04
#define BD_TAG_TYPE_DOUBLE			0x05
#define BD_TAG_TYPE_BOOL			0x06
#define BD_TAG_TYPE_STRING			0x07
#define BD_TAG_TYPE_COMPOUND		0x08
#define BD_TAG_TYPE_ARRAY_UINT8		0x09
#define BD_TAG_TYPE_ARRAY_UINT16	0x0A
#define BD_TAG_TYPE_ARRAY_UINT32	0x0B
#define BD_TAG_TYPE_ARRAY_UINT64	0x0C
#define BD_TAG_TYPE_ARRAY_FLOAT		0x0D
#define BD_TAG_TYPE_ARRAY_DOUBLE	0x0E

#define BD_TAG_DATA_TYPE_INT8	'b'
#define BD_TAG_DATA_TYPE_INT16	's'
#define BD_TAG_DATA_TYPE_INT32	'i'
#define BD_TAG_DATA_TYPE_INT64	'l'
#define BD_TAG_DATA_TYPE_FLOAT	'f'
#define BD_TAG_DATA_TYPE_DOUBLE	'd'

#define BD_MIN(a, b) a < b ? a : b
#define BD_MAX(a, b) a > b ? a : b
