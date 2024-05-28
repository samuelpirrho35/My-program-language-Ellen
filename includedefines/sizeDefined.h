#ifndef SIZEDEFINED_H
#define SIZEDEFINED_H

#include "../includedefines/referenceTypes.h"
#include "../includedefines/defines.h"

#define I64_N_B_0_LEN_STR 19
#define I32_N_B_0_LEN_STR 10
#define I16_N_B_0_LEN_STR 5
#define I8_N_B_0_LEN_STR  3

#define I64_N_S_0_LEN_STR 20
#define I32_N_S_0_LEN_STR 11
#define I16_N_S_0_LEN_STR 6
#define I8_N_S_0_LEN_STR  4

#define U64_LEN_STR 20

#define F32_N_B_0_LEN_STR 49
#define F64_N_B_0_LEN_STR 319

#define F32_N_S_0_LEN_STR 50
#define F64_N_S_0_LEN_STR 320

#define START_DATA_STRUCTURE 0x10
#define INIT_LEN_DS_STR      3
#define NO_MODIFY            0
#define WITH_MODIFY          1

#define INIT_SIZE_STRING 0x255

#define CONST_MAX_i64  9223372036854775807
#define CONST_MAX_i32  2147483647
#define CONST_MAX_i16  32767
#define CONST_MAX_i8   127

#define CONST_MIN_i64  -9223372036854775808
#define CONST_MIN_i32  -2147483648
#define CONST_MIN_i16  -32768
#define CONST_MIN_i8   -128

#define CONST_MAX_u64  18446744073709551615ULL
#define CONST_MAX_u32  4294967295
#define CONST_MAX_u16  65535
#define CONST_MAX_u8   255

#define CONST_MAX_f32  3.402823e+38
#define CONST_MAX_f64  1.797693e+308

#define CONST_MIN_f32  1.175494e-38
#define CONST_MIN_f64  2.225074e-308

#define INITSIZEWORDIDENTIFIER 100

#define INTERNALOPERQTTY 20
#define KEYWORDsQTTY 46
#define OBJECTsQTTY  29

#define BUFFER_SIZE      1024

typedef enum{
    i64_size  =   sizeof(i64),
    i32_size  =   sizeof(i32),
    i16_size  =   sizeof(i16),
    i8_size   =   sizeof(i8),
    f32_size  =   sizeof(f32),
    f64_size  =   sizeof(f64)
}referencesu64;

#endif //SIZEDEFINED_H