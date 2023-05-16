#ifndef PR_QUEUE_HPP_
#define PR_QUEUE_HPP_

#include <vector>
#include <functional>
#include <stdexcept>

template<
    typename T,
    typename Container = std::vector<T>,
    typename Compare = std::less<typename Container::value_type>
> 
class Priority_queue
{
private:
    Container heap;
    Compare comp;

public:
    using const_reference = typename Container::const_reference;
    using size_type = typename Container::size_type;
    using value_type = typename Container::value_type;

    Priority_queue();
    explicit Priority_queue(const Compare& compare);
    Priority_queue(const Compare& compare, const Container& cont);
    Priority_queue(const Compare& compare, Container&& cont);
    Priority_queue(const Priority_queue& other);
    Priority_queue(Priority_queue&& other);

    template <typename InputIt>
    Priority_queue(InputIt first, InputIt last,
                    const Compare& comapre,
                    const Container& cont);

    template <typename InputIt>
    Priority_queue(InputIt first, InputIt last,
                    const Compare& compare, Container&& cont);

    template <typename Alloc>
    explicit Priority_queue(const Alloc& alloc);

    template <typename Alloc>
    Priority_queue(const Compare& compare, const Alloc& alloc);

    template <typename Alloc>
    Priority_queue(const Compare& compare, const Container& cont,
                    const Alloc& alloc);
    
    template <typename Alloc>
    Priority_queue(const Compare& compare, Container&& cont,
                    const Alloc& alloc);
    
    template <typename Alloc>
    Priority_queue(const Priority_queue& other, const Alloc& alloc);

    template <typename Alloc>
    Priority_queue(Priority_queue&& other, const Alloc& alloc);

    template <typename InputIt, typename Alloc>
    Priority_queue(InputIt first, InputIt last, const Alloc& alloc);

    template <typename InputIt, typename Alloc>
    Priority_queue(InputIt first, InputIt last, const Compare& compare,
                    const Alloc& alloc);

    template <typename InputIt, typename Alloc>
    Priority_queue(InputIt first, InputIt last, const Compare& compare,
                    const Container& cont, const Alloc& alloc);

    template <typename InputIt, typename Alloc>
    Priority_queue(InputIt first, InputIt last, const Compare& compare, 
                    Container&& cont, const Alloc& alloc);

    ~Priority_queue() = default;

public:
    Priority_queue& operator=(const Priority_queue& rhs);
    Priority_queue& operator=(Priority_queue&& rhs);

    const_reference top() const;

    [[nodiscard]] bool empty() const;

    size_type size() const;

    void push(const value_type& value);
    void push(value_type&& value);

    template <typename... Args>
    void emplace(Args&&... args);

    void pop();

    void swap(Priority_queue& other) noexcept;

private:
    void make_heap(typename Container::iterator first, typename Container::iterator last, Compare comp = Compare());
    void sift_down(typename Container::iterator first, std::ptrdiff_t start, std::ptrdiff_t end, Compare comp = Compare());
    void sift_up(typename Container::iterator first, typename Container::iterator last, Compare compare);
};

#include "priority_queue.tpp"

#endif //PR_QUEUE_HPP_