#include <pistache/endpoint.h>
#include <pistache/http.h>
#include <pistache/router.h>
#include "services/user.h"

using namespace Pistache;

int main(int argc, char* argv[]) 
{
    using namespace Rest;

    Router router;
    Port port(8080);
    Address addr(Ipv4::any(), port);
    std::shared_ptr<Http::Endpoint> endpoint = std::make_shared<Http::Endpoint>(addr);
    auto opts = Http::Endpoint::options().threads(1);
    endpoint->init(opts);

    Routes::Get(router, "/users", Routes::bind(&UserService().readAll));
    Routes::Get(router, "/users/:id", Routes::bind(&UserService().read));
    Routes::Post(router, "/users", Routes::bind(&UserService().create));
    Routes::Put(router, "/users/:id", Routes::bind(&UserService().update));
    Routes::Delete(router, "/users/:id", Routes::bind(&UserService().remove));

    endpoint->setHandler(router.handler());
    endpoint->serve();
}