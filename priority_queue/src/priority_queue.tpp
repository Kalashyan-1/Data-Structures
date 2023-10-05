#ifndef PR_QUEUE_TPP_
#define PR_QUEUE_TPP_
#include "priority_queue.hpp"

template <typename T, typename Container, typename Compare> 
Priority_queue<T, Container, Compare>::Priority_queue() : Priority_queue(Compare(), Container()) { }

template <typename T, typename Container, typename Compare> 
Priority_queue<T, Container, Compare>::Priority_queue(const Compare& compare) 
        : Priority_queue(compare, Container()) { }

template <typename T, typename Container, typename Compare> 
Priority_queue<T, Container, Compare>::Priority_queue(const Compare& compare, const Container& cont)
        : heap (cont), comp(compare) 
{
    make_heap(heap.begin(), heap.end(), comp);
}
    
template <typename T, typename Container, typename Compare> 
    Priority_queue<T, Container, Compare>::Priority_queue(const Compare& compare, Container&& cont)
        : heap(std::move(cont)), comp(compare) 
{
    make_heap(heap.begin(), heap.end(), comp);
}
    

template <typename T, typename Container, typename Compare> 
Priority_queue<T, Container, Compare>::Priority_queue(const Priority_queue& other) 
    : heap(other.heap), comp(other.comp) { }

template <typename T, typename Container, typename Compare> 
Priority_queue<T, Container, Compare>::Priority_queue(Priority_queue&& other) 
    : heap(std::move(other.heap), comp(std::move(other.comp))) { }


template <typename T, typename Container, typename Compare> 
template <typename InputIt>
Priority_queue<T, Container, Compare>::Priority_queue(InputIt first, InputIt last, const Compare& compare, const Container& cont)
    :  heap(first, last, cont), comp(compare) 
{
    make_heap(heap.begin(), heap.end(), comp);
}

template <typename T, typename Container, typename Compare> 
template <typename InputIt>
Priority_queue<T, Container, Compare>::Priority_queue(InputIt first, InputIt last, const Compare& compare, Container&& cont)
    :  heap(first, last, std::move(cont)), comp(compare) 
{
    make_heap(heap.begin(), heap.end(), comp);
}

template <typename T, typename Container, typename Compare> 
template <typename Alloc>
Priority_queue<T, Container, Compare>::Priority_queue(const Alloc& alloc)
    : heap(alloc), comp() { }

template <typename T, typename Container, typename Compare> 
template <typename Alloc>
Priority_queue<T, Container, Compare>::Priority_queue(const Compare& compare, const Alloc& alloc)
    : heap(alloc), comp(compare) { }

template <typename T, typename Container, typename Compare> 
template <typename Alloc>
Priority_queue<T, Container, Compare>::Priority_queue(const Compare& compare, const Container& cont, const Alloc& alloc)
    : heap(cont, alloc), comp(compare) 
{
    make_heap(heap.begin(), heap.end(), comp);
}
    

template <typename T, typename Container, typename Compare> 
template <typename Alloc>
Priority_queue<T, Container, Compare>::Priority_queue(const Compare& compare, Container&& cont, const Alloc& alloc)
    : heap(std::move(cont), alloc), comp(compare) 
{
    make_heap(heap.begin(), heap.end(), comp);
}


    
template <typename T, typename Container, typename Compare> 
template <typename Alloc>
Priority_queue<T, Container, Compare>::Priority_queue(const Priority_queue& other, const Alloc& alloc)
    : heap(other.heap, alloc), comp(other.comp) 
{
    make_heap(heap.begin(), heap.end(), comp);
}

template <typename T, typename Container, typename Compare> 
template <typename Alloc>
Priority_queue<T, Container, Compare>::Priority_queue(Priority_queue&& other, const Alloc& alloc)
    : heap(std::move(other.heap), alloc), comp(std::move(other.comp)) 
{
    make_heap(heap.begin(), heap.end(), comp);
}

template <typename T, typename Container, typename Compare> 
template <typename InputIt, typename Alloc>
Priority_queue<T, Container, Compare>::Priority_queue(InputIt first, InputIt last, const Alloc& alloc)
    : heap(first, last, alloc), comp() 
{
    make_heap(heap.begin(), heap.end(), comp);
}

template <typename T, typename Container, typename Compare> 
template <typename InputIt, typename Alloc>
Priority_queue<T, Container, Compare>::Priority_queue(InputIt first, InputIt last, const Compare& compare, const Alloc& alloc)
    : heap(first, last, alloc), comp(compare) 
{
    make_heap(heap.begin(), heap.end(), comp);
}

template <typename T, typename Container, typename Compare> 
template <typename InputIt, typename Alloc>
Priority_queue<T, Container, Compare>::Priority_queue(InputIt first, InputIt last, const Compare& compare, const Container& cont, const Alloc& alloc)
    : heap(cont, alloc), comp(compare)
{
    heap.insert(heap.end(), first, last);
    make_heap(heap.begin(), heap.end(), comp);
}

template <typename T, typename Container, typename Compare> 
template <typename InputIt, typename Alloc>
Priority_queue<T, Container, Compare>::Priority_queue(InputIt first, InputIt last, const Compare& compare, Container&& cont, const Alloc& alloc)
    : heap(std::move(cont), alloc), comp(compare)
{
    heap.insert(heap.end(), first, last);
    make_heap(heap.begin(), heap.end(), comp);
}

template<typename T, typename Container, typename Compare>
Priority_queue<T, Container, Compare>& Priority_queue<T, Container, Compare>::operator=(const Priority_queue& rhs)
{
    if (&rhs != this) {
        heap = rhs.heap;
        comp = rhs.comp;
    }
    return *this;
}

template<typename T, typename Container, typename Compare>
Priority_queue<T, Container, Compare>& Priority_queue<T, Container, Compare>::operator=(Priority_queue&& rhs)
{
    heap = std::move(rhs.heap);
    comp = std::move(rhs.comp);
    return *this;
}

template<typename T, typename Container, typename Compare>
typename Priority_queue<T, Container, Compare>::const_reference Priority_queue<T, Container, Compare>::top() const {
    if (heap.empty()) {
        throw std::out_of_range("Priority_queue is empty");
    }
    return heap.front();
}

template<typename T, typename Container, typename Compare>
[[nodiscard]] bool Priority_queue<T, Container, Compare>::empty() const {
    return heap.empty();
}

template<typename T, typename Container, typename Compare>
typename Priority_queue<T, Container, Compare>::size_type Priority_queue<T, Container, Compare>::size() const {
    return heap.size();
}

template<typename T, typename Container, typename Compare>
void Priority_queue<T, Container, Compare>::push(const value_type& value) {
    heap.push_back(value);
    sift_up(heap.begin(), heap.end() - 1, comp);
}

template<typename T, typename Container, typename Compare>
void Priority_queue<T, Container, Compare>::push(value_type&& value) {
    heap.push_back(std::move(value));
    sift_up(heap.begin(), heap.end() - 1, comp);
}

template<typename T, typename Container, typename Compare>
template <typename... Args>
void Priority_queue<T, Container, Compare>::emplace(Args&&... args) {
   heap.emplace_back(std::forward<Args>(args)...);
   sift_up(heap.begin(), heap.end() - 1, comp);
}

template<typename T, typename Container, typename Compare>
void Priority_queue<T, Container, Compare>::pop() {
    if (heap.empty()) {
        throw std::out_of_range("Priority_queue is empty");
    }
    heap[0] = std::move(heap.back());
    heap.pop_back();
    sift_down(heap.begin(), 0, heap.size(), comp);
}

template<typename T, typename Container, typename Compare>
void Priority_queue<T, Container, Compare>::swap(Priority_queue& other) noexcept {
    std::swap(heap, other.heap);
    std::swap(comp, other.comp);
}

template<typename T, typename Container, typename Compare>
void Priority_queue<T, Container, Compare>::make_heap(typename Container::iterator first, typename Container::iterator last, Compare comp) {
    auto n = std::distance(first, last);
    for (auto i = n/2; i >= 0; i--) {
        sift_down(first, i, n, comp);
    }
}

template<typename T, typename Container, typename Compare>
void Priority_queue<T, Container, Compare>::sift_down(typename Container::iterator first, std::ptrdiff_t start, std::ptrdiff_t end, Compare comp) {
    auto root = start;
    while (2 * root + 1 < end) {
        auto child = 2 * root + 1;
        if (child + 1 < end && comp(*(first + child), *(first + child + 1))) {
            ++child;
        }
        if (comp(*(first + root), *(first + child))) {
            std::iter_swap(first + root, first + child);
            root = child;
        } else {
            return;
        }
    }
}

template<typename T, typename Container, typename Compare>
void Priority_queue<T, Container, Compare>::sift_up(typename Container::iterator first, typename Container::iterator last, Compare compare) {
    auto start = first;
    auto child = last;
    while (start != child) {
        auto paret = start + (child - start -1)/2;
        if (compare(*paret, *child)) {
            std::iter_swap(paret, child);
            child = paret;
        } else {
            return;
        }
    }
}

#endif // PR_QUEUE_TPP_
