#include <iostream>

namespace argument_parser {

void print_help();
void print_help_and_exit(int exit_code = 0);
std::string get_input_file_name(int argc, char* argv[]);

}
