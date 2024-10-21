#include <iostream>
#include <crow.h>
#include <nlohmann/json.hpp>
#include "load_balancer.h"
#include "server.h"

std::string readFile(const std::string& filePath) {
    std::ifstream file(filePath);
    std::stringstream buffer;
    buffer << file.rdbuf();
    return buffer.str();
}

int main(int argc, char const *argv[])
{
    crow::SimpleApp app;

    auto server1 = std::make_shared<Server>("Server 1");
    auto server2 = std::make_shared<Server>("Server 2");
    auto server3 = std::make_shared<Server>("Server 3");
    
    LoadBalancer* lb = new LoadBalancer;
    lb->addServer(server1);
    lb->addServer(server2);
    lb->addServer(server3);

    CROW_ROUTE(app, "/")([](){
        return crow::response(readFile("templates/index.html"));
    });

    CROW_ROUTE(app, "/api/request").methods(crow::HTTPMethod::GET)([&lb](){
        return lb->handleRequest();
    });

    app.port(18080).multithreaded().run();

    delete lb;

}
