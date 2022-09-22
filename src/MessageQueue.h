#include <deque>
#include <mutex>
#include <condition_variable>

template <class T>
class MessageQueue {
public:
    T receive();
    void send(T &&msg);
    //void trigger();

private:
    std::deque<T> _queue;
    std::mutex _lock;
    std::condition_variable _condition;
};