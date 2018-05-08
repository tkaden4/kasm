#include<iostream>
#include<vector>
#include<cstdint>

#include<getopt.h>

#include"kasm.hpp"
#include"parse.hpp"

constexpr auto USAGE = "usage: kasm <file> [-o|--out-file <out-file>]";

enum {
    NO_ARG = 0,
    REQ_ARG = 1,
    OPT_ARG = 2
};

struct option long_opts[] = {
    { "--out-file", REQ_ARG, NULL, 'o' },
    { NULL, 0, NULL, 0 }
};

int main(int argc, char **argv)
{
    if(argc != 2){
        puts(USAGE);
        exit(1);
    }
    std::string output_file{"out.ko"};
    int opt = EOF;
    while((opt = getopt(argc, argv, "")) != EOF){
        switch(opt){
        case 'o':
            output_file = std::string{optarg};
            break;
        default:
            std::cerr << USAGE << std::endl;
            exit(1);
        }
    }

    yyin = stdin;
    if(yyparse()){
        exit(1);
    }

    return 0;
}
