#ifndef MESSAGE_RECEIVER_H
#define MESSAGE_RECEIVER_H

#include <thread>
#include <atomic>

class MessageReceiver {
public:
    explicit MessageReceiver(int sockfd);
    ~MessageReceiver();

    void start();
    void stop();

private:
    void receiveMessages();
    int sockfd;
    std::atomic<bool> running;
    std::thread receiverThread;
};

#endif // MESSAGE_RECEIVER_H