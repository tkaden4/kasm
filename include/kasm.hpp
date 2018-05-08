#pragma once

#include<string>
#include<memory>
#include<vector>
#include<unordered_map>

namespace kasm {

// useful type-aliases
using pos_t = size_t;
using label_t = std::string;
using buf_t = std::vector<uint8_t>;

// symbol table, used for label positioning
template<typename K, typename V>
using env = std::unordered_map<K, V>;

struct argument {
    enum class type {
        label
    };
    type type;
};

struct insn {
    enum class mode {
        iABCD,
        iABCx,
        iAx,
        iRAx,
        iI
    };

    std::string mnemonic;
    mode mode;
    std::vector<argument> arguments;
};

using segment = std::vector<insn>;

struct program {
    segment code;
};

/* perform macro expansion */
auto macro_pass(program) -> std::tuple<env<label_t, size_t>, program>;
/* resolve labels */
auto label_pass(env<label_t, size_t>, program) -> program;
/* generate bytecode */
auto gen_pass(program) -> buf_t;

}   // namespace kasm
