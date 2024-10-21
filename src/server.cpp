#include "server.h"

Server::Server(const std::string& name) : serverName(name), connections(0) {}

std::string Server::processRequest() {
    return "Processing request on server: " + serverName;
}
int Server::getConnections() const {
    return connections;
}
void Server::addConnection() {
    connections++;
}
void Server::removeConnection() {
    connections--;
}