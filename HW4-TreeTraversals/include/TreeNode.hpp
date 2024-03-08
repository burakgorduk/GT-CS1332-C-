/**
 * Node class used for implementing binary tree.
 *
 */
template <typename T>
class TreeNode
{
private:
    T m_data;
    TreeNode<T> *m_left = nullptr;
    TreeNode<T> *m_right = nullptr;

public:
    /**
     * Constructs a TreeNode with the given data.
     *
     * @param data the data stored in the new node
     */
    TreeNode(T data)
    {
        m_data = data;
    }

    /**
     * Gets the data.
     *
     * @return the data
     */
    T getData() {
        return m_data;
    }

    /**
     * Gets the left child.
     *
     * @return the left child
     */
    TreeNode<T> *getLeft() {
        return m_left;
    }

    /**
     * Gets the right child.
     *
     * @return the right child
     */
    TreeNode<T> *getRight() {
        return m_right;
    }

    /**
     * Sets the data.
     *
     * @param data the new data
     */
    void setData(T data) {
        m_data = data;
    }

    /**
     * Sets the left child.
     *
     * @param left the new left child
     */
    void setLeft(TreeNode<T> *left) {
        m_left = left;
    }

    /**
     * Sets the right child.
     *
     * @param right the new right child
     */
    void setRight(TreeNode<T> *right) {
        m_right = right;
    }
};
