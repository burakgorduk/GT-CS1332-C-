#include <stdexcept>
#include <vector>
#include "TreeNode.hpp"

/**
 * Implementation of of the pre-order, in-order, and post-order traversals of a tree.
 */
template <typename T>
class Traversals
{
public:

    /**
     * Given the root of a binary search tree, generate a
     * pre-order traversal of the tree. The original tree
     * should not be modified in any way.
     *
     * This must be done recursively.
     *
     * Must be O(n).
     *
     * @param <T> Generic type.
     * @param root The root of a BST.
     * @return List containing the pre-order traversal of the tree.
     */
    std::vector<T> preorder(TreeNode<T> *root) {
        std::vector<T> res;
        _preorder(root, res);
        return res;
    }

    /**
     * Given the root of a binary search tree, generate an
     * in-order traversal of the tree. The original tree
     * should not be modified in any way.
     *
     * This must be done recursively.
     *
     * Must be O(n).
     *
     * @param <T> Generic type.
     * @param root The root of a BST.
     * @return List containing the in-order traversal of the tree.
     */
    std::vector<T> inorder(TreeNode<T> *root) {
        std::vector<T> res;
        _inorder(root, res);
        return res;
    }

    /**
     * Given the root of a binary search tree, generate a
     * post-order traversal of the tree. The original tree
     * should not be modified in any way.
     *
     * This must be done recursively.
     *
     * Must be O(n).
     *
     * @param <T> Generic type.
     * @param root The root of a BST.
     * @return List containing the post-order traversal of the tree.
     */
    std::vector<T> postorder(TreeNode<T> *root) {
        std::vector<T> res;
        _postorder(root, res);
        return res;
    }

private:
    void _preorder(TreeNode<T> *root, std::vector<T>& res)
    {
        if (root)
        {
            res.push_back(root->getData());
            _preorder(root->getLeft(), res);
            _preorder(root->getRight(), res);
        }
    }

    void _inorder(TreeNode<T> *root, std::vector<T>& res)
    {
        if (root)
        {
            _inorder(root->getLeft(), res);
            res.push_back(root->getData());
            _inorder(root->getRight(), res);
        }
    }

    void _postorder(TreeNode<T> *root, std::vector<T>& res)
    {
        if (root)
        {
            _postorder(root->getLeft(), res);
            _postorder(root->getRight(), res);
            res.push_back(root->getData());
        }
    }
};
