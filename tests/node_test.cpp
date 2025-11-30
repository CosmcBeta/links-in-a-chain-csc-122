#include "../src/link.hpp"
#include "../src/node.hpp"

#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/benchmark/catch_constructor.hpp>
#include <catch2/catch_test_macros.hpp>
#include <catch2/generators/catch_generators_range.hpp>

TEST_CASE("Node can be created with a Link")
{
	Link gold("Gold");
	Node node(&gold);

	REQUIRE(node.getData()->getMaterial() == "Gold");
}

TEST_CASE("Node starts with no next node")
{
	Link gold("Gold");
	Node node(&gold);

	REQUIRE(node.next() == nullptr);
}

TEST_CASE("Node can be created with a Link and next node")
{
	Link gold("Gold");
	Node node_one(&gold);

	Link silver("Silver");
	Node node_two(&silver, &node_one);

	REQUIRE(node_two.next() == &node_one);
	REQUIRE(node_two.getData()->getMaterial() == "Silver");
}

TEST_CASE("Multiple nodes can be chained together")
{
	Link gold("Gold");
	Node node_one(&gold);

	Link silver("Silver");
	Node node_two(&silver, &node_one);

	Link bronze("Bronze");
	Node node_three(&bronze, &node_two);

	REQUIRE(node_three.next() == &node_two);
	REQUIRE(node_two.next() == &node_one);
	REQUIRE(node_one.next() == nullptr);
}

TEST_CASE("Can traverse from HEAD to end of list")
{
	Link gold("Gold");
	Node node_one(&gold);

	Link silver("Silver");
	Node node_two(&silver, &node_one);

	Link bronze("Bronze");
	Node node_three(&bronze, &node_two);

	Node* current = &node_three;
	REQUIRE(current->getData()->getMaterial() == "Bronze");

	current = current->next();
	REQUIRE(current->getData()->getMaterial() == "Silver");

	current = current->next();
	REQUIRE(current->getData()->getMaterial() == "Gold");

	current = current->next();
	REQUIRE(current == nullptr);
}

TEST_CASE("Node retrieval works as expected")
{
	Link gold("Gold");
	Node node_one(&gold);

	Link silver("Silver");
	Node node_two(&silver, &node_one);

	Link bronze("Bronze");
	Node node_three(&bronze, &node_two);

	Node* retrieved_node_two = node_three.next();
	Node* retrieved_node_one = node_two.next();

	REQUIRE(retrieved_node_two->getData()->getMaterial() == "Silver");
	REQUIRE(retrieved_node_one->getData()->getMaterial() == "Gold");
}

TEST_CASE("HEAD node has no parent")
{
	Link gold("Gold");
	Node head(&gold);

	REQUIRE(head.next() == nullptr);
}

TEST_CASE("Each node points to exactly one next node")
{
	Link gold("Gold");
	Node node_one(&gold);

	Link silver("Silver");
	Node node_two(&silver, &node_one);

	Link bronze("Bronze");
	Node node_three(&bronze, &node_two);

	REQUIRE(node_three.next() == &node_two);
	REQUIRE(node_two.next() == &node_one);
	REQUIRE(node_one.next() == nullptr);
}

TEST_CASE("Can create single node list")
{
	Link gold("Gold");
	Node single_node(&gold);

	REQUIRE(single_node.getData()->getMaterial() == "Gold");
	REQUIRE(single_node.next() == nullptr);
}

TEST_CASE("Can access Link data through Node")
{
	Link copper("Copper");
	Node node(&copper);

	REQUIRE(node.getData()->getMaterial() == "Copper");
}

TEST_CASE("Long chain traversal works correctly")
{
	Link link1("Link1");
	Node node1(&link1);

	Link link2("Link2");
	Node node2(&link2, &node1);

	Link link3("Link3");
	Node node3(&link3, &node2);

	Link link4("Link4");
	Node node4(&link4, &node3);

	Link link5("Link5");
	Node node5(&link5, &node4);

	Node* current = &node5;
	int count = 0;
	while (current != nullptr)
	{
		count++;
		current = current->next();
	}

	REQUIRE(count == 5);
}

TEST_CASE("Two node chain works correctly")
{
	Link first("First");
	Node node_first(&first);

	Link second("Second");
	Node node_second(&second, &node_first);

	REQUIRE(node_second.getData()->getMaterial() == "Second");
	REQUIRE(node_second.next()->getData()->getMaterial() == "First");
	REQUIRE(node_second.next()->next() == nullptr);
}
