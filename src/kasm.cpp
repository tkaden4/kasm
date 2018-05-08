#include"kasm.hpp"

namespace kasm {

auto label_pass(env<label_t, size_t> env, program prog) -> program {
    (void) env;
    for(auto &i: prog.code){
        for(auto &arg: i.arguments){
            if(arg.type == argument::type::label){

            }
        }
    }

    return prog;
}

}   // namespace kasm
