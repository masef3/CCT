#include <string>
#include <sstream>
#include <vector>
#include <tuple>
#include "../include/parser.hpp"


using parsed_profile = std::vector< std::string >;
using parsed_info = std::tuple< std::string, int64_t >;
using parsed_struct = std::tuple< parsed_profile, int64_t>;


void parser::skip_spaces(std::string &context, int64_t &index) const
{
	while (context[ index ] == ' ') {
		++ index;
	}
}


const parsed_info parser::get_freq(std::string &context) const
{
	std::string last_call, freq_str;

	for (int64_t i = 0; context[ i ] != ' '; ++ i) {
		last_call.push_back(context[ i ]);
	}
	
	int64_t index = last_call.size();
	skip_spaces(context, index);

	for (size_t k = index; k < context.size(); ++ k) {
		freq_str.push_back(context[ k ]);	
	}

	int64_t freq = std::stoll(freq_str);
	return make_tuple(last_call, freq);
}


const parsed_struct parser::parse_line(std::string &parsed_line) const
{ 
	std::string res;	
	std::stringstream curr_line(parsed_line);
	
	parsed_profile temp;
	while (std::getline(curr_line, res, ';')) {
		temp.push_back(res);				
	}
	
	std::string to_be_fixed = temp.back();
	temp.pop_back();
	auto [ last_call, freq ] = get_freq(to_be_fixed);
	temp.push_back(last_call);

	return make_tuple(temp, freq);
}
