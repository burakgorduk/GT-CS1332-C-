#include "ArrayQueue.hpp"
#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>

TEST_CASE("Test basic enqueue dequeue")
{
    ArrayQueue<int> aq;

    aq.enqueue(1);
    REQUIRE(1 == aq.size());

    aq.enqueue(2);
    REQUIRE(2 == aq.size());

    aq.enqueue(3);
    REQUIRE(3 == aq.size());

    REQUIRE(1 == aq.dequeue());
    REQUIRE(2 == aq.size());

    REQUIRE(2 == aq.dequeue());
    REQUIRE(1 == aq.size());

    REQUIRE(3 == aq.dequeue());
    REQUIRE(0 == aq.size());

    aq.enqueue(1);
    REQUIRE(1 == aq.size());

    REQUIRE(1 == aq.dequeue());
    REQUIRE(0 == aq.size());
}

TEST_CASE("Test wrap around")
{
    ArrayQueue<int> aq;

    for (int i = 0; i < 9; i++)
        aq.enqueue(i);

    REQUIRE(9 == aq.size());
    for (int i = 0; i < 9; i++)
    {
        REQUIRE(i == aq.dequeue());
        aq.enqueue(i);
    }

    REQUIRE(9 == aq.size());
    for (int i = 0; i < 5; i++)
        REQUIRE(i == aq.dequeue());

    REQUIRE(4 == aq.size());
    for (int i = 9; i < 14; i++)
        aq.enqueue(i);

    REQUIRE(9 == aq.size());
    for (int i = 5; i < 14; i++)
        REQUIRE(i == aq.dequeue());

    REQUIRE(0 == aq.size());
}

TEST_CASE("Test basic resize")
{
    ArrayQueue<int> aq;

    for (int i = 0; i < 9; i++)
        aq.enqueue(i);

    REQUIRE(9 == aq.size());
    REQUIRE(9 == aq.capacity());
    aq.enqueue(9);

    REQUIRE(10 == aq.size());
    REQUIRE(18 == aq.capacity());
    for (int i = 10; i < 18; i++)
        aq.enqueue(i);

    REQUIRE(18 == aq.size());
    REQUIRE(18 == aq.capacity());
    for (int i = 0; i < 18; i++)
        REQUIRE(i == aq.dequeue());

    REQUIRE(0 == aq.size());
    REQUIRE(18 == aq.capacity());
}

TEST_CASE("Test resize with unroll")
{
    // 5 6 7 8 0 1 2 3 4
    ArrayQueue<int> aq;
    int *backing = aq.getBackingArray();
    for (int i = 0; i < 4; i++)
    {
        aq.enqueue(i);
        REQUIRE(i == (int)aq.dequeue());
    }

    REQUIRE(0 == aq.size());
    for (int i = 0; i < 9; i++)
        aq.enqueue(i);

    REQUIRE(9 == aq.size());
    REQUIRE(9 == aq.capacity());
    REQUIRE(5 == backing[0]);
    REQUIRE(4 == backing[8]);

    aq.enqueue(9);
    backing = aq.getBackingArray();
    REQUIRE(10 == aq.size());
    REQUIRE(18 == aq.capacity());

    REQUIRE(0 == backing[0]);
    REQUIRE(8 == backing[8]);
    REQUIRE(9 == backing[9]);

    for (int i = 0; i < 10; i++)
        REQUIRE(i == (int)aq.dequeue());

    REQUIRE(0 == aq.size());
    REQUIRE(18 == aq.capacity());
}

TEST_CASE("Dequeue throws when empty")
{
    ArrayQueue<int> aq;

    REQUIRE_THROWS_AS(aq.dequeue(), std::logic_error);
}
