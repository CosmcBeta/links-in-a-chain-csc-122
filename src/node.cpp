#include "node.hpp"
#include "link.hpp"

Node::Node(Link* link, Node* next): link_(link), next_(next) {}

Node* Node::next() const
{
	return next_;
}

Link* Node::getData() const
{
	return link_;
}
