#include "queue.hpp"
template <typename T>
Queue<T>::Queue(const Queue& oth) : queue{oth.queue} {}

template <typename T>
Queue<T>::Queue(Queue&& oth) : queue{move(oth)} {}

template <typename T>
Queue<T>& Queue<T>::operator=(const Queue& rhs) {
    if (this == &rhs) return *this;
    queue = rhs;
}

template <typename T>
Queue<T>& Queue<T>::operator=(Queue&& rhs) {
    queue = move(rhs);
}

template <typename T>
const T& Queue<T>::front() {
    return queue.front();
}

template <typename T>
const T& Queue<T>::back() {
    return queue.back();
}

template <typename T>
[[nodiscard]] bool Queue<T>::empty() const{
    return queue.empty();
}

template <typename T>
constexpr std::size_t Queue<T>::size() const{
    return queue.size();
}

template <typename T>
void Queue<T>::push(const T& value) {
    queue.push_back(value);
}

template <typename T>
void Queue<T>::push(T&& value) {
    queue.push_back(std::move(value));
}

template <typename T>
template<typename... Args>
void Queue<T>::emplace(Args&&... args) {
    queue.push_back(std::forward<decltype(args)>(args)...);
}

template <typename T>
void Queue<T>::pop() {
    queue.pop_front();
}

template <typename T>
void Queue<T>::swap(Queue& oth) noexcept {
    queue.swap(oth);
}