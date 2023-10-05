#include "threadPool.h"

ThreadPool::ThreadPool(std::size_t threadCount) : stop{false} {
    for (std::size_t i = 0; i < threadCount; ++i) {
        threads.emplace_back([this]{
            while (true) {
                std::function<void()> task;
                {
                    std::unique_lock<std::mutex> lock(quMutex);
                    cnd.wait(lock, [this]{return stop || !tasks.empty();});
                    if (stop && tasks.empty()){return;}
                    task = std::move(tasks.front());
                    tasks.pop();
                }
                task();
            }
        });
    }
}

ThreadPool::~ThreadPool() noexcept {
    {
        std::unique_lock<std::mutex> lock(quMutex);
        stop = true;
    }
    cnd.notify_all();
    for (auto& thrd : threads) {
        thrd.join();
    }
}
