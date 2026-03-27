#include <string>
#include <vector>
#include <cstdint>


struct parser
{
	using parsed_profile = std::vector< std::string >;
	using parsed_info = std::tuple< std::string, int64_t >;
	using parsed_struct = std::tuple< parsed_profile, int64_t >;

	parsed_profile parsed;
	parser() = default;

	const parsed_struct parse_line(std::string &parsed_line) const;

	const parsed_info get_freq(std::string &context) const;

	void skip_spaces(std::string &context, int64_t &index) const;

};
