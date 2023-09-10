set(SRC_LIST calluserservice.cc ../user.pb.cc mprpcchannel.cc)

add_executable(consumer ${SRC_LIST})
target_link_libraries(provider mprpc protobuf)