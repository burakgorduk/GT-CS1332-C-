#include <vector>
#include "Traversals.hpp"
#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>

TEST_CASE("Preorder")
{
    Traversals<int> t;
    TreeNode<int> root(0);
    TreeNode<int> left(1);
    TreeNode<int> right(2);

    root.setLeft(&left);
    root.setRight(&right);

    std::vector<int> out = t.preorder(&root);
    REQUIRE(3 == out.size());
    REQUIRE(0 == out[0]);
    REQUIRE(1 == out[1]);
    REQUIRE(2 == out[2]);
}

TEST_CASE("Inorder")
{
    Traversals<int> t;
    TreeNode<int> root(0);
    TreeNode<int> left(1);
    TreeNode<int> right(2);

    root.setLeft(&left);
    root.setRight(&right);

    std::vector<int> out = t.inorder(&root);
    REQUIRE(3 == out.size());
    REQUIRE(1 == out[0]);
    REQUIRE(0 == out[1]);
    REQUIRE(2 == out[2]);
}

TEST_CASE("Postorder")
{
    Traversals<int> t;
    TreeNode<int> root(0);
    TreeNode<int> left(1);
    TreeNode<int> right(2);

    root.setLeft(&left);
    root.setRight(&right);

    std::vector<int> out = t.postorder(&root);
    REQUIRE(3 == out.size());
    REQUIRE(1 == out[0]);
    REQUIRE(2 == out[1]);
    REQUIRE(0 == out[2]);
}
