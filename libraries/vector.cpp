#include "vector.h"

using namespace rsm;

vector::vector()
{
    m_array = new int[1];
}

vector::~vector()
{
    delete[] m_array;
}

void vector::reserve(int capacityToReserve)
{
    m_capacity = capacityToReserve;
}

void vector::resize(int indexToResizeTo)
{
    while(m_capacity < indexToResizeTo)
    {
        m_capacity *= 2;
    }

    int* temp = new int[m_capacity];
    for(size_t i = 0; i < indexToResizeTo; i++)
    {
        temp[i] = 0;
    }

    for(size_t i = 0; i < m_size; i++)
    {
        temp[i] = m_array[i];
    }

    m_size = indexToResizeTo;
    while(m_size < m_capacity / 2)
    {
        m_capacity /= 2;
    }

    delete[] m_array;
    m_array = temp;
}

void vector::push_back(int elementToPush)
{
    if(m_size == m_capacity)
    {
        m_capacity *= 2;
        int* temp = new int[m_capacity];

        for (size_t i = 0; i < m_size; i++)
        {
            temp[i] = m_array[i];
        }

        delete[] m_array;
        m_array = temp;
    }

    m_array[m_size] = elementToPush;
    m_size++;
}

void vector::pop_back()
{
    m_size--;
    if(m_size <= m_capacity / 2)
    {
        m_capacity /= 2;
        int* temp = new int[m_capacity];

        for (size_t i = 0; i < m_size; i++)
        {
            temp[i] = m_array[i];
        }

        delete[] m_array;
        m_array = temp;
    }

}

int vector::at(int index)
{
    if(index < m_size)
    {
        return m_array[index];
    }

    return -1;
}

bool vector::empty()
{
    return m_size = 0;
}

int vector::size() const
{
    return m_size;
}

int vector::capacity() const
{
    return m_capacity;
}
