#pragma once

#include <vector>
#include <string>
#include <regex>

class CSlice
{
	int* start;
	int* stop;
	int* step;
	std::vector<int> elements;
	static std::regex format;
	CSlice() = default;
	void parse(std::string);
	int* resolveString(const std::string&);
public:
	CSlice(std::vector<int>& elements) { this->elements = elements; };
	std::vector<int> slice(std::string);
	bool checkFormat(const std::string&);
	~CSlice() { delete start; delete stop; delete step; };
};

