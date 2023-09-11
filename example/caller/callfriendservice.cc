#include <iostream>
#include "mprpcapplication.h"
#include "friend.pb.h"

int main( int argc , char **argv ) {
    MprpcApplication::Init( argc , argv );

    // 调用远程发布的rpc方法Login
    fixbug::FriendServiceRpc_Stub stub( new MprpcChannel() );
    // rpc方法的请求参数
    fixbug::GetFriendListRequest request;
    request.set_userid( 1000 );
    // rpc方法的响应
    fixbug::GetFriendListResponse response;
    MprpcController controller;
    // 发起rpc方法的调用 同步的rpc调用过程
    stub.GetFriendList( &controller , &request , &response , nullptr );   // RpcChannel->RpcChannel::callMethod 集中做所有rpc方法调用的参数序列化和网络发送

    // 读取调用结果
    if (controller.Failed()) {
        std::cout << controller.ErrorText() << std::endl;
    }
    else {
        if (0 == response.result().errcode()) {
            std::cout << "rpc GetFriendList response success!" << std::endl;
            int size = response.friends_size();
            for (int i = 0; i < size; ++i) {
                std::cout << "index:" << ( i + 1 ) << " name:" << response.friends( i ) << std::endl;
            }
        }
        else {
            std::cout << "rpc GetFriendList response error:" << response.result().errmsg() << std::endl;
        }
    }
    
    return 0;
}