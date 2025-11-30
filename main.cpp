#include <iostream>

#include "src/node.hpp"

int main()
{
	// Create Link objects
	Link gold("Gold");
	Link silver("Silver");
	Link bronze("Bronze");

	// Create nodes, linking them as we go
	Node node_three(&bronze);
	Node node_two(&silver, &node_three);
	Node node_one(&gold, &node_two);

	// Head of the list
	Node* head = &node_one;

	// Example output
	std::cout << "Traversing the linked list:" << std::endl;
	Node* current = head;
	while (current != nullptr)
	{
		std::cout << current->getData()->getMaterial() << std::endl;
		current = current->next();
	}

	// Accessing next nodes directly, like in teacher example
	Node* retrieved_node_two = node_one.next();
	Node* retrieved_node_three = node_two.next();

	std::cout << "\nDirect access using next():" << std::endl;
	std::cout << "Node one next: " << retrieved_node_two->getData()->getMaterial() << std::endl;
	std::cout << "Node two next: " << retrieved_node_three->getData()->getMaterial() << std::endl;

	return 0;
}
