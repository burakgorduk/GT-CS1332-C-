/**
 * Node class used for implementing the SinglyLinkedList.
 *
 */
template <typename T>
class SinglyLinkedListNode
{
private:
    T m_data;
    SinglyLinkedListNode<T> *m_next = nullptr;

public:
    /**
     * Constructs a new SinglyLinkedListNode with the given data and next node
     * reference.
     *
     * @param data the data stored in the new node
     * @param next the next node in the list
     */
    SinglyLinkedListNode(const T &data, const SinglyLinkedListNode<T> *next)
    {
        m_data = data;
        m_next = next;
    }

    /**
     * Creates a new SinglyLinkedListNode with only the given data.
     *
     * @param data the data stored in the new node
     */
    SinglyLinkedListNode(const T data)
    {
        m_data = data;
    }

    /**
     * Gets the data.
     *
     * @return the data
     */
    T getData()
    {
        return m_data;
    }

    /**
     * Gets the next node.
     *
     * @return the next node
     */
    SinglyLinkedListNode<T> *getNext()
    {
        return m_next;
    }

    /**
     * Sets the next node.
     *
     * @param next the new next node
     */
    void setNext(SinglyLinkedListNode<T> *next)
    {
        m_next = next;
    }
};
