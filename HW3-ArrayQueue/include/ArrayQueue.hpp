#include <stdexcept>

/**
 * Implementation of an ArrayQueue.
 */
template <typename T>
class ArrayQueue
{
private:
    int m_capacity = 9;
    int m_size = 0;
    int m_front = 0;
    T *m_backingArray;

public:
    ArrayQueue()
    {
        m_backingArray = new T[m_capacity];
    }

    ~ArrayQueue()
    {
        delete[] m_backingArray;
    }

    /**
     * Adds the data to the back of the queue.
     *
     * If sufficient space is not available in the backing array, resize it to
     * double the current length. When resizing, copy elements to the
     * beginning of the new array and reset front to 0.
     *
     * Method should run in amortized O(1) time.
     *
     * @param data the data to add to the back of the queue
     */
    void enqueue(T data)
    {
        if (m_size == m_capacity)
            resize();

        int index = wrapIndex(m_front + m_size);
        m_backingArray[index] = data;
        m_size++;
    }

    /**
     * Removes and returns the data from the front of the queue.
     *
     * Do not shrink the backing array.
     *
     * If the queue becomes empty as a result of this call, do not reset
     * front to 0.
     *
     * Method should run in O(1) time.
     *
     * @return the data formerly located at the front of the queue
     * @throws logic_error if the list is empty
     */
    T dequeue()
    {
        if (m_size == 0)
            throw std::logic_error("Attempted to dequeue from an empty ArrayQueue");

        T data = m_backingArray[m_front];
        m_front = wrapIndex(m_front + 1);
        m_size--;
        return data;
    }

    /**
     * Returns the backing array of the list.
     *
     * For grading purposes only. You shouldn't need to use this method since
     * you have direct access to the variable.
     *
     * @return the backing array of the list
     */
    T *getBackingArray()
    {
        return m_backingArray;
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

    /**
     * Returns the capacity of the list.
     *
     * @return the capacity of the list
     */
    int capacity()
    {
        return m_capacity;
    }

private:
    int wrapIndex(int index)
    {
        return index % m_capacity;
    }

    void resize()
    {
        T *oldArray = m_backingArray;
        m_backingArray = new T[m_capacity * 2];
        for (int i = 0; i < m_size; i++)
        {
            int oldIndex = wrapIndex(m_front + i);
            m_backingArray[i] = oldArray[oldIndex];
        }

        m_front = 0;
        m_capacity *= 2;
        delete[] oldArray;
    }
};
