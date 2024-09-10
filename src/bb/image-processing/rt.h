// Don't use this file.
// You can add only BB written by pure Halide function to ion-bb-image-processing.

#include <Halide.h>

namespace ion {
namespace bb {
namespace image_processing {

std::map<std::string, Halide::ExternCFunction> extern_functions;

class RegisterExtern {
public:
    RegisterExtern(std::string key, Halide::ExternCFunction f) {
        extern_functions[key] = f;
    }
};

}  // namespace image_processing
}  // namespace bb
}  // namespace ion
