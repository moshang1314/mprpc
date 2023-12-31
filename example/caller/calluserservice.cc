#include <iostream>
#include "mprpcapplication.h"
#include "user.pb.h"
#include "mprpcchannel.h"

int main( int argc , char **argv ) {
    MprpcApplication::Init( argc , argv );

    // 调用远程发布的rpc方法Login
    fixbug::UserServiceRpc_Stub stub( new MprpcChannel() );
    // rpc方法的请求参数
    fixbug::LoginRequest request;
    request.set_name( "zhang san" );
    request.set_pwd( "123456" );
    // rpc方法的响应
    fixbug::LoginResponse response;
    // 发起rpc方法的调用 同步的rpc调用过程
    stub.Login( nullptr , &request , &response , nullptr );   // RpcChannel->RpcChannel::callMethod 集中做所有rpc方法调用的参数序列化和网络发送

    // 读取调用结果
    if (0 == response.result().errcode()) {
        std::cout << "rpc login response success:" << response.success() << std::endl;
    }
    else {
        std::cout << "rpc login response error:" << response.result().errmsg() << std::endl;
    }

    // 调用远程发布的rpc方法Register
    fixbug::RegisterRequest req;
    req.set_id( 2000 );
    req.set_name( "mprpc" );
    req.set_pwd( "li123" );
    fixbug::RegisterResponse rsp;

    // 以同步方式发起rpc调用请求，等待返回结果
    stub.Register( nullptr , &req , &rsp , nullptr );
     // 读取调用结果
    if (0 == rsp.result().errcode()) {
        std::cout << "rpc register response success:" << rsp.success() << std::endl;
    }
    else {
        std::cout << "rpc register response error:" << rsp.result().errmsg() << std::endl;
    }
    return 0;
}