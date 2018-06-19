#include "argument_parser.hpp"

namespace argument_parser {

void print_help() {
    // [todo] 
    std::cout << "HELP" << std::endl;
}

void print_help_and_exit(int exit_code) {
    print_help();
    std::exit(exit_code);
}

std::string get_input_file_name(int argc, char* argv[]) {
    std::string file_name = "in.txt";

    if (argc > 2) {
        print_help_and_exit();
    }
    if (argc == 2) {
        file_name = std::string(argv[1]);

        if (file_name == "-h" || file_name == "--help") {
            print_help_and_exit();
        }
    }

    return file_name;
}

}