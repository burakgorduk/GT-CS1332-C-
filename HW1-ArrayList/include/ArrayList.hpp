#include <exception>
#include <stdexcept>

template <typename T>
class ArrayList
{
private:
    int m_capacity = 9;
    int m_size = 0;
    T *m_backingArray;

public:
    ArrayList<T>()
    {
        m_backingArray = new T[m_capacity];
    }

    ~ArrayList()
    {
        delete[] m_backingArray;
    }

    /**
     * Adds the data to the back of the list.
     *
     * Method should run in amortized O(1) time.
     *
     * @param data the data to add to the back of the list
     */
    void addToBack(const T &data)
    {
        if (m_size == m_capacity)
        {
            resize();
        }

        m_backingArray[m_size] = data;
        m_size++;
    }

    /**
     * Adds the data to the front of the list.
     *
     * This add may require elements to be shifted.
     *
     * Method should run in O(n) time.
     *
     * @param data the data to add to the front of the list
     */
    void addToFront(const T &data)
    {
        if (m_size == m_capacity)
        {
            resize();
        }

        for (int i = m_size; i > 0; i--)
        {
            m_backingArray[i] = m_backingArray[i - 1];
        }
        m_backingArray[0] = data;
        m_size++;
    }

    /**
     * Removes and returns the last data of the list.
     *
     * Do not shrink the backing array.
     *
     * Method should run in O(1) time.
     *
     * @return the data formerly located at the back of the list
     * @throws logic_error if the list is empty
     */
    T removeFromBack()
    {
        if (m_size == 0)
        {
            throw std::logic_error("Attempted to remove element from an empty ArrayList");
        }

        m_size--;
        return m_backingArray[m_size];
    }

    /**
     * Removes and returns the first data of the list.
     *
     * Do not shrink the backing array.
     *
     * This remove may require elements to be shifted.
     *
     * Method should run in O(n) time.
     *
     * @return the data formerly located at the front of the list
     * @throws logic_error if the list is empty
     */
    T removeFromFront()
    {
        if (m_size == 0)
        {
            throw std::logic_error("Attempted to remove element from an empty ArrayList");
        }

        T data = m_backingArray[0];
        m_size--;
        for (int i = 0; i < m_size; i++) {
            m_backingArray[i] = m_backingArray[i+1];
        }
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
    void resize()
    {
        T *oldArray = m_backingArray;
        m_capacity *= 2;
        m_backingArray = new T[m_capacity];
        for (int i = 0; i < m_size; i++)
        {
            m_backingArray[i] = oldArray[i];
        }
        delete[] oldArray;
    }
};
