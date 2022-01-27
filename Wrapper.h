#ifndef WRAPPER_H
#define WRAPPER_H

// A template class that holds a pointer to a T object. This is essentially a smart_ptr class
// Consider implementing smart_ptr instead.
template <typename T>
class Wrapper
{
private:
    T* m_Ptr;
public:
    Wrapper() : m_Ptr{ nullptr } {}
    Wrapper(const T& inner) : m_Ptr{ inner.clone() } {}

    Wrapper(const Wrapper<T>& other)
    {
        if (other.m_Ptr != 0)
        {
            m_Ptr = other.m_Ptr->clone();
        }
        else
            m_Ptr = nullptr;
    }

    Wrapper& operator=(const Wrapper<T>& other)
    {
        if (this != &other)
        {
            if (m_Ptr != 0)
            {
                delete m_Ptr;
            }
            
            m_Ptr = (other.m_Ptr->clone() != 0) ? other.m_Ptr->clone() : nullptr;
        }
    
        return *this;
    }

    T& operator*()
    {
        return *m_Ptr;
    }
    
    const T& operator*() const
    {
        return *m_Ptr;
    }


    T* operator->()
    {
        return m_Ptr;
    }
    
    const T* operator->() const
    {
        return m_Ptr;
    }

    ~Wrapper()
    {
        if (m_Ptr != 0)
        {
            delete m_Ptr;
        }
    }
};

#endif