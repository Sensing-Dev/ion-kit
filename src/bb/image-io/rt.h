#ifndef ION_BB_IMAGE_IO_RT_H
#define ION_BB_IMAGE_IO_RT_H

#include <chrono>
#include <cstdlib>
#include <thread>
#include <vector>

#include <HalideBuffer.h>

#include <Halide.h>
namespace ion {
namespace bb {
namespace image_io {

std::map<std::string, Halide::ExternCFunction> extern_functions;

class RegisterExtern {
public:
    RegisterExtern(std::string key, Halide::ExternCFunction f) {
        extern_functions[key] = f;
    }
};

}  // namespace image_io
}  // namespace bb
}  // namespace ion
#define ION_REGISTER_EXTERN(NAME) static auto ion_register_extern_##NAME = ion::bb::image_io::RegisterExtern(#NAME, NAME);

#include "rt_u3v.h"
#include "rt_file.h"
#include "rt_display.h"

#ifdef __linux__
#include "rt_realsense.h"
#include "rt_v4l2.h"
#endif

#undef ION_REGISTER_EXTERN

#endif
