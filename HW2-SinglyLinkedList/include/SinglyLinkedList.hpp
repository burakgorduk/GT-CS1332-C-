#include "SinglyLinkedListNode.hpp"
#include <stdexcept>

/**
 * Implementation of a Singly-Linked List.
 */
template <typename T>
class SinglyLinkedList
{
private:
    SinglyLinkedListNode<T> *m_head = nullptr;
    SinglyLinkedListNode<T> *m_tail = nullptr;
    int m_size = 0;

public:
    ~SinglyLinkedList()
    {
        SinglyLinkedListNode<T> *node = m_head;
        while (node)
        {
            SinglyLinkedListNode<T> *tmp = node;
            node = node->getNext();
            delete tmp;
        }
    }

    /**
     * Adds the element to the back of the list.
     *
     * Method should run in O(1) time.
     *
     * @param data the data to add to the back of the list
     */
    void addToBack(T data)
    {
        SinglyLinkedListNode<T> *node = new SinglyLinkedListNode(data);
        if (!m_head)
            m_head = node;
        else
            m_tail->setNext(node);

        m_tail = node;
        m_size++;
    }

    /**
     * Adds the element to the front of the list.
     *
     * Method should run in O(1) time.
     *
     * @param data the data to add to the front of the list
     */
    void addToFront(T data)
    {
        SinglyLinkedListNode<T> *node = new SinglyLinkedListNode(data);
        if (!m_head)
            m_tail = node;
        else
            node->setNext(m_head);

        m_head = node;
        m_size++;
    }

    /**
     * Removes and returns the last data of the list.
     *
     * Method should run in O(n) time.
     *
     * @return the data formerly located at the back of the list
     * @throws logic_error if the list is empty
     */
    T removeFromBack()
    {
        if (m_size == 0)
            throw std::logic_error("Attempted to remove element from an empty list");

        T data = m_tail->getData();
        SinglyLinkedListNode<T> *node = m_head;
        while (node != m_tail && node->getNext() != m_tail)
            node = node->getNext();

        delete m_tail;
        m_tail = node;
        m_tail->setNext(nullptr);
        if (m_size == 1)
        {
            m_head = nullptr;
            m_tail = nullptr;
        }

        m_size--;
        return data;
    }

    /**
     * Removes and returns the first data of the list.
     *
     * Method should run in O(1) time.
     *
     * @return the data formerly located at the front of the list
     * @throws logic_error if the list is empty
     */
    T removeFromFront()
    {
        if (m_size == 0)
            throw std::logic_error("Attempted to remove element from an empty list");

        T data = m_head->getData();
        SinglyLinkedListNode<T> *node = m_head->getNext();
        delete m_head;
        m_head = node;
        if (!m_head)
        {
            m_tail = nullptr;
        }

        m_size--;
        return data;
    }

    /**
     * Returns the head node of the list.
     *
     * For grading purposes only. You shouldn't need to use this method since
     * you have direct access to the variable.
     *
     * @return the node at the head of the list
     */
    SinglyLinkedListNode<T> *getHead()
    {
        return m_head;
    }

    /**
     * Returns the tail node of the list.
     *
     * For grading purposes only. You shouldn't need to use this method since
     * you have direct access to the variable.
     *
     * @return the node at the tail of the list
     */
    SinglyLinkedListNode<T> *getTail()
    {
        return m_tail;
    }

    /**
     * Returns the size of the list.
     *
     * For grading purposes only. You shouldn't need to use this method since
     * you have direct access to the variable.
     *
     * @return the size of the list
     */
    int size()
    {
        return m_size;
    }
};
