#include "MessageQueue.h"

template <class T>
void MessageQueue<T>::send(T &&msg) {

    //Locking the deque before entering the message onto the queue and so that no other thread accesses the message queue
    std::lock_guard<std::mutex> insertLock(_lock);

    //Placing the message at the back of the queue;
    _queue.emplace_back(msg);

    //This function will not notify
    _condition.notify_one();
}

template <class T>
T MessageQueue<T>::receive() {
    //Locing the deque with a unique lock
    std::unique_lock<std::mutex> retriveLock(_lock);

    //Wait for a message to be placed on the message queue
    _condition.wait(retriveLock, [this](){ return !_queue.empty(); });

    //Once a message is placed on the queue, pop the front of the queue
    T receivedMsg = std::move(_queue.front());
    _queue.pop_front();

    return receivedMsg;
}