#pragma once

#include <string>

class Link
{
public:
	Link(std::string material);

	std::string getMaterial() const;

private:
	std::string material_;
};
