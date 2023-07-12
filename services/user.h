#include <pistache/router.h>
// #include <mongocxx/client.hpp>
// #include <mongocxx/instance.hpp>

using namespace Pistache;

class UserService
{
public:
    void static read(const Rest::Request &req, Http::ResponseWriter resp)
    {
        resp.send(Http::Code::Ok, "read!");
    };

    void static readAll(const Rest::Request &req, Http::ResponseWriter resp)
    {

        // const auto uri = mongocxx::uri{"mongodb+srv://rafaellevissa:N8bkl2Xrsy8J4s2r@cluster0.pwzrre6.mongodb.net/?retryWrites=true&w=majority"};
        // mongocxx::database db = client["rest-api"];
        // mongocxx::collection coll = db["users"];

        // mongocxx::cursor cursor = coll.find({});

        // for (auto &&doc : cursor)
        // {
        //     std::cout << bsoncxx::to_json(doc) << std::endl;
        // }

        resp.send(Http::Code::Ok, "readAll!");
    };

    void static create(const Rest::Request &req, Http::ResponseWriter resp)
    {
        resp.send(Http::Code::Ok, "create!");
    };

    void static update(const Rest::Request &req, Http::ResponseWriter resp)
    {
        resp.send(Http::Code::Ok, "update!");
    };

    void static remove(const Rest::Request &req, Http::ResponseWriter resp)
    {
        resp.send(Http::Code::Ok, "remove!");
    };
};
