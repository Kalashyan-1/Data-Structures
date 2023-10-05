#ifndef QUEUE_HPP_
#define QUEUE_HPP_

#include <list>

template <typename T>
class Queue {
public:

    Queue() = default;
    ~Queue() = default;

    Queue(const Queue&);
    Queue(Queue&&);
    Queue& operator=(const Queue&);
    Queue& operator=(Queue&&);

    const T& front();
    const T& back();

    [[nodiscard]] bool empty() const;
    
    constexpr std::size_t size() const;

    void push(const T& value);
    void push(T&& value);

    template<typename... Args>
    void emplace(Args&&... args);
    
    void pop();

    void swap(Queue& other) noexcept;

private:
    std::list<T> queue;
};

#include "queue.tpp"

#endif  //QUEUE_HPP_