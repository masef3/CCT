#include <string>
#include <iostream>
#include <fstream>
#include "../include/node.hpp"
#include "../include/cct.hpp"
#include "../include/parser.hpp"


bool check_user_input(int argc, std::ifstream &filename)
{
	if (argc != 2) {
		std::cerr << "Not specified <.folded> file" << std::endl;
		return false;
	}

	if (!filename.is_open()) {
		std::cerr << "File you provided does not exist" << std::endl;
		return false;
	}
	return true;	

}


int main(int argc, char* argv[])
{
	if (argc > 2 || argc < 2) {
		std::cerr << "There was a problem with given arguments" << std::endl;
		return 1;
	}

	std::ifstream file(argv[ 1 ]);
	if (!check_user_input(argc, file)) { return 1; }

	data_cct profiler;
	node &root = profiler.root;
	std::string curr_line;

	parser pars;

	while (std::getline(file, curr_line)) {
		auto const &[ call_stack, call_count ] = pars.parse_line(curr_line);
		profiler.update_branch(call_stack, call_count);
	}
	
	std::string fname = "exported_from_cct.folded";
	std::ofstream ofile(fname);
	std::string curr_call_stack = "";

	root.export_back(ofile, curr_call_stack);
	ofile.close();	
}
