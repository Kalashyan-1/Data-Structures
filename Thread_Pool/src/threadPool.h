#ifndef THREAD_POOL_
#define THREAD_POOL_

#include <vector>
#include <functional>
#include <queue>
#include <condition_variable>
#include <mutex>
#include <thread>
#include <iostream>

class ThreadPool {
public:
    ThreadPool(std::size_t threadCount);
    ~ThreadPool() noexcept;

    template <typename Function, typename... Args>
    void addThread(Function&& func, Args&&... args);
private:
    bool stop;
    std::condition_variable cnd;
    std::mutex quMutex;
    std::queue<std::function<void()>> tasks;
    std::vector<std::thread> threads;
};

template <typename Function, typename... Args>
void ThreadPool::addThread(Function&& func, Args&&... args) {
    {
        std::unique_lock<std::mutex> lock(quMutex);
        if (stop) {
            throw std::runtime_error("adding thread on stopped ThreadPool");
        }
        tasks.emplace([&] { std::forward<Function>(func)(std::forward<Args>(args)...); });

    }
    cnd.notify_one();
}


#endif  //THREAD_POOL_