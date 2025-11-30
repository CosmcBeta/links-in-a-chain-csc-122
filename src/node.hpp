#pragma once

#include "link.hpp"

class Node
{
public:
	Node(Link* link, Node* next = nullptr);

	Node* next() const;
	Link* getData() const;

private:
	Link* link_;
	Node* next_;
};
