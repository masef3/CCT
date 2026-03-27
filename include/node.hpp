#pragma once
#include <string>
#include <memory>
#include <fstream>
#include <unordered_map>

struct data_cct;

struct node
{
	int64_t exclusive_cpu_call_count = 0;
	int64_t inclusive_cpu_call_count = 0;
	const std::string tag;
	std::unordered_map< std::string, std::unique_ptr< node > > branches;

	node(const std::string &name) : tag(name) {}
	
	void add(int64_t count_calls);
	node &call(const std::string &func_name);
	void export_back(std::ofstream &file, std::string &call_stack) const;	
};


