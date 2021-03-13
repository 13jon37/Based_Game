/* date = March 13th 2021 1:53 pm */

#ifndef LANGUAGE_LAYER_H
#define LANGUAGE_LAYER_H

#include <stdint.h>
#include <stdbool.h>

#define internal        static
#define local_persist   static
#define global_variable static

typedef int8_t i8;
typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;

typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;

typedef float f32;

#endif //LANGUAGE_LAYER_H
