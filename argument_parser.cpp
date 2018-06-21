#include "argument_parser.hpp"

namespace argument_parser {

void print_help() {
    std::cout << "Usage: task15 [FILE]" << std::endl;
    std::cout << "Calculate longest path shorter than given time, given input in [FILE]." << std::endl << std::endl;

    std::cout << "With no FILE, default input file name is in.txt" << std::endl << std::endl;

    std::cout << "Description of file contents:" << std::endl;
    std::cout << "The first row of an input file: " <<
        "the total number of graph vertices (chambers), total number of graph edges (tunnels), maximum time (given until the bombs will blow-up).\n" <<
        "Following rows describe the edges (rest of the graph):\n" <<
        "start vertex, end vertex, edge weight (time to pass)\n" << std::endl;

    std::cout << "Notice that vertices numbering starts from '0', which is hero stating point" << std::endl << std::endl;

    std::cout << "For example:" << std::endl;
    std::cout << "5 5 4" << std::endl;
    std::cout << "0 1 1" << std::endl;
    std::cout << "1 2 1" << std::endl;
    std::cout << "2 3 2" << std::endl;
    std::cout << "0 3 3" << std::endl;
    std::cout << "1 4 1" << std::endl << std::endl;

    std::cout << "Is equivalent to graph:" << std::endl;

    std::cout << " 0 ----t=1---- 1 ----t=1---- 4" << std::endl;
    std::cout << " |             |" << std::endl;
    std::cout << " |             |" << std::endl;
    std::cout << "t=3           t=1" << std::endl;
    std::cout << " |             |" << std::endl;
    std::cout << " |             |" << std::endl;
    std::cout << " 3 ----t=2---- 2" << std::endl;
    std::cout << "With maximum time of 4." << std::endl;
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
