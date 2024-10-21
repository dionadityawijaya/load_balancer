#include "load_balancer.h"
#include <algorithm>
#include <iostream>

LoadBalancer::LoadBalancer() : roundRobinIndex(0) {}

void LoadBalancer::addServer(const std::shared_ptr<Server>& server) {
    servers.push_back(server);
}

std::string LoadBalancer::handleRequest() {
    roundRobinIndex = (roundRobinIndex = 1) % servers.size();
    auto server = servers[roundRobinIndex];
    server->addConnection();
    std::string response = server->processRequest();
    server->removeConnection();
    return response;
}

int LoadBalancer::getLeastConnectionIndex() {
    int leastConnections = servers[0]->getConnections();
    int index = 0;

    for (int i = 1; i < servers.size(); i++) {
        if (servers[i]->getConnections() < leastConnections) {
            leastConnections = servers[i]->getConnections();
            index = i;
        }
    }
    return index;
}