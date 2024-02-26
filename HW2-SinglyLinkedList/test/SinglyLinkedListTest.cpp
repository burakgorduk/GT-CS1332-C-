#include "SinglyLinkedList.hpp"
#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>

TEST_CASE("Test back")
{
    SinglyLinkedList<int> sll;
    SinglyLinkedListNode<int> *head;
    SinglyLinkedListNode<int> *tail;

    sll.addToBack(3);
    head = sll.getHead();
    tail = sll.getTail();

    REQUIRE(1 == sll.size());
    REQUIRE(3 == head->getData());
    REQUIRE(3 == tail->getData());

    sll.addToBack(2);
    head = sll.getHead();
    tail = sll.getTail();
    REQUIRE(2 == sll.size());
    REQUIRE(3 == head->getData());
    REQUIRE(2 == tail->getData());

    sll.addToBack(1);
    head = sll.getHead();
    tail = sll.getTail();
    REQUIRE(3 == sll.size());
    REQUIRE(3 == head->getData());
    REQUIRE(1 == tail->getData());

    REQUIRE(1 == sll.removeFromBack());
    head = sll.getHead();
    tail = sll.getTail();
    REQUIRE(2 == sll.size());
    REQUIRE(3 == head->getData());
    REQUIRE(2 == tail->getData());

    REQUIRE(2 == sll.removeFromBack());
    head = sll.getHead();
    tail = sll.getTail();
    REQUIRE(1 == sll.size());
    REQUIRE(3 == head->getData());
    REQUIRE(3 == tail->getData());

    REQUIRE(3 == sll.removeFromBack());
    REQUIRE(0 == sll.size());
    REQUIRE(!sll.getHead());
    REQUIRE(!sll.getTail());
}

TEST_CASE("Test front")
{
    SinglyLinkedList<int> sll;
    SinglyLinkedListNode<int> *head;
    SinglyLinkedListNode<int> *tail;

    sll.addToFront(3);
    head = sll.getHead();
    tail = sll.getTail();
    REQUIRE(1 == sll.size());
    REQUIRE(3 == head->getData());
    REQUIRE(3 == tail->getData());

    sll.addToFront(2);
    head = sll.getHead();
    tail = sll.getTail();
    REQUIRE(2 == sll.size());
    REQUIRE(2 == head->getData());
    REQUIRE(3 == tail->getData());

    sll.addToFront(1);
    head = sll.getHead();
    tail = sll.getTail();
    REQUIRE(3 == sll.size());
    REQUIRE(1 == head->getData());
    REQUIRE(3 == tail->getData());

    REQUIRE(1 == sll.removeFromFront());
    head = sll.getHead();
    tail = sll.getTail();
    REQUIRE(2 == sll.size());
    REQUIRE(2 == head->getData());
    REQUIRE(3 == tail->getData());

    REQUIRE(2 == sll.removeFromFront());
    head = sll.getHead();
    tail = sll.getTail();
    REQUIRE(1 == sll.size());
    REQUIRE(3 == head->getData());
    REQUIRE(3 == tail->getData());

    REQUIRE(3 == sll.removeFromFront());
    REQUIRE(0 == sll.size());
    REQUIRE(!sll.getHead());
    REQUIRE(!sll.getTail());
}

TEST_CASE("Test back and front")
{
    SinglyLinkedList<int> sll;
    SinglyLinkedListNode<int> *head;
    SinglyLinkedListNode<int> *tail;

    sll.addToBack(2);
    head = sll.getHead();
    tail = sll.getTail();
    REQUIRE(1 == sll.size());
    REQUIRE(2 == head->getData());
    REQUIRE(2 == tail->getData());

    sll.addToFront(1);
    head = sll.getHead();
    tail = sll.getTail();
    REQUIRE(2 == sll.size());
    REQUIRE(1 == head->getData());
    REQUIRE(2 == tail->getData());

    sll.addToBack(3);
    head = sll.getHead();
    tail = sll.getTail();
    REQUIRE(3 == sll.size());
    REQUIRE(1 == head->getData());
    REQUIRE(3 == tail->getData());

    REQUIRE(1 == sll.removeFromFront());
    head = sll.getHead();
    tail = sll.getTail();
    REQUIRE(2 == sll.size());
    REQUIRE(2 == head->getData());
    REQUIRE(3 == tail->getData());

    REQUIRE(3 == sll.removeFromBack());
    head = sll.getHead();
    tail = sll.getTail();
    REQUIRE(1 == sll.size());
    REQUIRE(2 == head->getData());
    REQUIRE(2 == tail->getData());

    REQUIRE(2 == sll.removeFromFront());
    REQUIRE(0 == sll.size());
    REQUIRE(!sll.getHead());
    REQUIRE(!sll.getTail());
}

TEST_CASE("Remove throws when empty")
{
    SinglyLinkedList<int> sll;

    REQUIRE_THROWS_AS(sll.removeFromBack(), std::logic_error);
    REQUIRE_THROWS_AS(sll.removeFromFront(), std::logic_error);
}
