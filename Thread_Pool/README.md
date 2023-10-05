# ThreadPool

ThreadPool is a C++ class that implements a simple thread pool, allowing you to efficiently parallelize and distribute tasks across multiple threads. It is particularly useful for handling a large number of tasks or computations concurrently.

## Table of Contents
- [Overview](#overview)
- [API](#api)
- [ThreadPool Usage](#threadpool-usage)
- [Complexity](#complexity)
- [Contributing](#contributing)

## Overview

A ThreadPool manages a fixed number of worker threads that continuously wait for tasks to be added to a queue. As tasks are added, the threads execute them concurrently, allowing you to take advantage of multi-core processors and improve the performance of your application.

### Features

- Thread management: Automatically creates and manages worker threads.
- Task scheduling: Efficiently schedules and executes tasks concurrently.
- Graceful shutdown: Stops all threads when the ThreadPool is destroyed.

## API

### Constructor

#### `ThreadPool(std::size_t threadCount)`
Creates a ThreadPool with the specified number of worker threads.

### Member Functions

#### `template <typename Function, typename... Args> void addThread(Function&& func, Args&&... args)`
Adds a task to the ThreadPool for execution. The task is defined by a callable function `func` and its arguments `args`. The function and arguments are forwarded to the task. This function is templated to allow for various callable function types.

### Destructor

#### `~ThreadPool() noexcept`
Destroys the ThreadPool and stops all worker threads gracefully.

## ThreadPool Usage

1. Create a ThreadPool object by specifying the desired number of worker threads.
2. Add tasks to the ThreadPool using the `addThread` method. Each task is a callable function along with its arguments.
3. The worker threads will automatically execute the added tasks concurrently.
4. When the ThreadPool is destructed, it will stop all worker threads gracefully.


## Complexity

- Creating the ThreadPool with threadCount threads: O (threadCount)
- Adding a task to the ThreadPool: O(1)
- Graceful shutdown of the ThreadPool: O(threadCount)


## Contributing

Contributions to the ThreadPool class are welcome! If you have ideas for improvements, new features, or bug fixes, please open an issue or create a pull request. Make sure to follow C++ coding standards and include appropriate test cases.