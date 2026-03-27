#pragma once
#include <string>
#include <cstdint>
#include "node.hpp"
#include <vector>

struct data_cct 
{
	node root;

	data_cct() : root("stack_root") {}
	node &append_profile(const std::vector< std::string > &parsed, int64_t freq);
	void update_branch(const std::vector< std::string > &parsed, int64_t freq);
			
};
