#pragma once

#include <memory>
#include <sys/epoll.h>
#include <Network/Socket.hpp>
#include <functional>

namespace Network
{
    class SocketEventManager
    {
    public:
        typedef std::function<void(int, uint8_t *, size_t)> dataReceiveDelegate_t;
        typedef std::function<void(int, uint32_t)> disconnectDelegate_t;

        SocketEventManager();
        ~SocketEventManager();
        SocketEventManager(const SocketEventManager &) = delete;
        SocketEventManager &operator=(const SocketEventManager &) = delete;
        SocketEventManager(const SocketEventManager &&) = delete;
        SocketEventManager &operator=(const SocketEventManager &&) = delete;

        /**
         * @brief This function is used to crate event monitor instance
         * 
         * @return true operation was successful
         * @return false operation was unsuccessful
         */
        bool create();

        /**
         * @brief This function is used to add socket to the list of monitored sockets
         * 
         * @param socket Socket to monitor
         * @return true operation was successful
         * @return false operation was unsuccessful
         */
        bool addSocketForMonitoring(Socket &socket);

        /**
         * @brief This function is used to remove socket from the list of monitored sockets
         * 
         * @param socket_fd sockets file description
         * @return true operation was successful
         * @return false operation was unsuccesful
         */
        bool removeSocketFromMonitoring(int socket_fd);
        /**
         * @brief This is the main event loop
         * 
         */
        void eventLoop();

        /**
         * @brief This function is used to stom main event loop
         * 
         */
        void stop();

        /**
         * @brief Set the data received delegate
         * 
         * @param dataRecivedDelegate_t delegate for received data
         */
        void setDataReceivedDelegate(dataReceiveDelegate_t);

        /**
         * @brief Set the disconnect delegate
         * 
         */
        void setDisconnectDelegate(disconnectDelegate_t);

    private:
        struct impl;
        std::unique_ptr<impl> pimpl;
    };
} // namespace Network
