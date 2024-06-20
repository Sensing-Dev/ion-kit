#include "ion/ion.h"

#include "test-bb.h"

using namespace ion;

int main()
{
    try {
        Halide::Type t = Halide::type_of<int32_t>();
        Port min0{"min0", t}, extent0{"extent0", t}, min1{"min1", t}, extent1{"extent1", t}, v{"v", t};
        Param v41{"v", "41"};
        Builder b;
        b.set_target(Halide::get_target_from_environment());
        Node n;
        n = b.add("test_producer").set_params(v41);
        n = b.add("test_consumer")(n["output"], min0, extent0, min1, extent1, v);
        b.compile("simple_graph");
    } catch (const Halide::Error& e) {
        std::cerr << e.what() << std::endl;
        return 1;
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }

    std::cout << "Passed" << std::endl;

    return 0;
}
