#include <string>
#include <memory>
#include <fstream>
#include "../include/node.hpp"

void node::add(int64_t count_calls)
{
	exclusive_cpu_call_count += count_calls;
}

node &node::call(const std::string &func_name) 
{
	auto &curr = this->branches[ func_name ];
	if (curr == nullptr) {
		curr = std::make_unique< node >(func_name);
	}
	return *curr;
}

void node::export_back(std::ofstream &file, std::string &call_stack) const
{
	if (exclusive_cpu_call_count != 0) {
		file << call_stack << " " << exclusive_cpu_call_count << "\n";
	}

	for (const auto &[ call_tag, call_node ] : branches) {
		std::string next_call_stack;

		if (call_stack.empty()) {
			next_call_stack = call_tag;
		} else {
			next_call_stack = call_stack + ";" + call_tag;
		}

		if (call_node) { call_node->export_back(file, next_call_stack); }
	}
}

