#include <string>
#include <cstdint>
#include <vector>
#include "../include/node.hpp"
#include "../include/cct.hpp"
	
node &data_cct::append_profile(const std::vector< std::string > &parsed, int64_t freq)
{
	node *curr = &root;
	curr->inclusive_cpu_call_count += freq;

	for (const auto &profile : parsed) {
		curr = &(curr->call(profile));
		curr->inclusive_cpu_call_count += freq;
	}
	return *curr;
}

void data_cct::update_branch(const std::vector< std::string > &parsed, int64_t freq) {
	append_profile(parsed, freq).add(freq);
}


