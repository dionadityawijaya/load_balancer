#ifndef SERVER_H
#define SERVER_H

#include <string>

class Server {
    public:
        Server(const std::string& name);
        std::string processRequest();
        int getConnections() const;
        void addConnection();
        void removeConnection();

    private:
        std::string serverName;
        int connections;
};


#endif