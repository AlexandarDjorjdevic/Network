#ifndef THREAD_POOL_H_INC
#define THREAD_POOL_H_INC

#include <memory>

namespace Network
{
    namespace Datagram{
    class Client
    {
    public:
        Client();
        ~Client();
        Client(const Client &) = delete;
        Client &operator=(const Client &) = delete;
        Client(Client &&) = delete;
        Client &operator=(Client &&) = delete;

    private:
        struct impl;
        std::unique_ptr<impl> pimpl;
    };        
    } // namespace Stream
} // namespace Network

#endif //THREAD_POOL_H_INC