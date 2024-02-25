#include "ArrayList.hpp"
#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>

TEST_CASE("Test back")
{
    ArrayList<int> list;

    REQUIRE(list.size() == 0);
    list.addToBack(1);
    REQUIRE(list.size() == 1);
    list.addToBack(2);
    REQUIRE(list.size() == 2);
    list.addToBack(3);
    REQUIRE(list.size() == 3);

    REQUIRE(list.removeFromBack() == 3);
    REQUIRE(list.size() == 2);
    REQUIRE(list.removeFromBack() == 2);
    REQUIRE(list.size() == 1);
    REQUIRE(list.removeFromBack() == 1);
    REQUIRE(list.size() == 0);
}

TEST_CASE("Test front")
{
    ArrayList<int> list;

    REQUIRE(list.size() == 0);
    list.addToFront(1);
    REQUIRE(list.size() == 1);
    list.addToFront(2);
    REQUIRE(list.size() == 2);
    list.addToFront(3);
    REQUIRE(list.size() == 3);

    REQUIRE(list.removeFromFront() == 3);
    REQUIRE(list.size() == 2);
    REQUIRE(list.removeFromFront() == 2);
    REQUIRE(list.size() == 1);
    REQUIRE(list.removeFromFront() == 1);
    REQUIRE(list.size() == 0);
}

TEST_CASE("Test back and front")
{
    ArrayList<int> list;

    list.addToBack(2);
    list.addToFront(1);
    list.addToBack(3);
    list.addToFront(0);

    REQUIRE(list.removeFromFront() == 0);
    REQUIRE(list.removeFromFront() == 1);
    REQUIRE(list.removeFromFront() == 2);
    REQUIRE(list.removeFromFront() == 3);
}

TEST_CASE("Resizing")
{
    ArrayList<int> list;

    REQUIRE(list.capacity() == 9);
    for (int i = 9; i < 18; i++)
        list.addToBack(i);
    REQUIRE(list.size() == 9);
    REQUIRE(list.capacity() == 9);

    list.addToFront(0);
    REQUIRE(list.capacity() == 18);
    list.removeFromFront();
    REQUIRE(list.capacity() == 18);

    for (int i = 8; i >= 0; i--)
        list.addToFront(i);
    REQUIRE(list.size() == 18);

    for (int i = 17; i >= 9; i--)
        REQUIRE(list.removeFromBack() == i);
    REQUIRE(list.size() == 9);

    for (int i = 0; i < 9; i++)
        REQUIRE(list.removeFromFront() == i);
    REQUIRE(list.size() == 0);
    REQUIRE(list.capacity() == 18);
}

TEST_CASE("Remove throws when empty")
{
    ArrayList<int> list;

    REQUIRE_THROWS_AS(list.removeFromBack(), std::logic_error);
    REQUIRE_THROWS_AS(list.removeFromFront(), std::logic_error);
}
