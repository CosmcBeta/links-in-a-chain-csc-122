#include "link.hpp"

Link::Link(std::string material): material_(material) {}

std::string Link::getMaterial() const
{
	return material_;
}
