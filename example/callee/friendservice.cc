#include <iostream>
#include <string>
#include <vector>
#include "friend.pb.h"
#include "mprpcapplication.h"
#include "mprpcprovider.h"

class FriendService : public ::fixbug::FriendServiceRpc{
public:
    std::vector<std::string> GetFriendList( uint32_t userid ) {
        std::cout << "do GetFriendList service!" << userid << std::endl;;
        std::vector<std::string> vec;
        vec.push_back( "gao yang" );
        vec.push_back( "liu hong" );
        vec.push_back( "wang shuo" );
        return vec;
    }

    // 重写基类方法
    void GetFriendList( ::google::protobuf::RpcController *controller ,
        const ::fixbug::GetFriendListRequest *request ,
        ::fixbug::GetFriendListResponse *response ,
        ::google::protobuf::Closure *done ) {
        uint32_t userid = request->userid();

        std::vector<std::string> friendList = GetFriendList( userid );

        response->mutable_result()->set_errcode( 0 );
        response->mutable_result()->set_errmsg( "" );
        for (std::string &name : friendList) {
            std::string *p = response->add_friends();
            *p = name;
        }
        done->Run();
    }
};

int main(int argc, char **argv) {
    // 调用框架的初始化操作
    MprpcApplication::Init(argc, argv);

    // 把UserService对象发布到rpc节点上
    RpcProvider provider;
    provider.NotifyService( new FriendService() );

    // 启动一个rcp服务发布节点 Run以后，进程进入阻塞状态，等待远程的rpc调用请求
    provider.Run();
}