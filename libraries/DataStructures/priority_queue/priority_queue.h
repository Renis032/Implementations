#pragma once

#include "../vector/vector.h"
#include <iostream>

namespace rsm
{

template <typename T>
class priority_queue
{
public:
    auto empty() const -> const bool
    {
        return m_heap.empty();
    }

    void push(const T& value)
    {
        m_heap.push_back(value);
        heapifyUp(m_heap.size() - 1);
    }

    auto top() -> const T&
    {
        if(empty())
        {
            std::out_of_range("Priority Queue is empty");
        }

        return m_heap.front();
    }

    void pop()
    {
        if(empty())
        {
            std::out_of_range("Priority Queue is empty");
        }

        m_heap[0] = m_heap.back();
        m_heap.pop_back();
        if(false == empty())
        {
            heapifyDown(0);
        }
    }

    auto size() const -> const size_t
    {
        return m_heap.size();
    }

private:
    auto parent(const int idx) -> int
    {
        return (idx - 1) / 2;
    }

    auto leftChild(const int idx) -> int
    {
        return 2 * idx + 1;
    }

    auto rightChild(const int idx) -> int
    {
        return 2 * idx + 2;
    }

    void heapifyUp(int idx)
    {
        while (idx > 0 && m_heap[parent(idx)] < m_heap[idx])
        {
            auto temp = m_heap[parent(idx)];
            m_heap[parent(idx)] = m_heap[idx];
            m_heap[idx] = temp;
            idx = parent(idx);
        }
    }

    void heapifyDown(int idx)
    {
        int size = m_heap.size();
        int largest = idx;
        int left = leftChild(idx);
        int right = rightChild(idx);

        if(left < size && m_heap[left] > m_heap[largest])
        {
            largest = left;
        }

        if(right < size && m_heap[right] > m_heap[largest])
        {
            largest = right;
        }
        
        if(largest != idx)
        {
            auto temp = m_heap[largest];
            m_heap[largest] = m_heap[idx];
            m_heap[idx] = temp;

            heapifyDown(largest);
        }
    }

private:
    rsm::vector<T> m_heap;
};

} // end of namespace rsm

