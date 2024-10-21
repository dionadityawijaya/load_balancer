#ifndef LOAD_BALANCER_H
#define LOAD_BALANCER_H

#include <vector>
#include <string>
#include <memory>
#include "server.h"

class LoadBalancer {
    public:
        LoadBalancer();
        void addServer(const std::shared_ptr<Server>& server);
        std::string handleRequest();

    private:
        std::vector<std::shared_ptr<Server>> servers;
        int roundRobinIndex;
        int getLeastConnectionIndex();

};

#endif