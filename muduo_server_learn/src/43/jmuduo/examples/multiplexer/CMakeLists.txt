add_executable(multiplex_server multiplexer.cc)
target_link_libraries(multiplex_server muduo_net)

add_executable(multiplex_server_simple multiplexer_simple.cc)
target_link_libraries(multiplex_server_simple muduo_net)

add_executable(multiplex_demux demux.cc)
target_link_libraries(multiplex_demux muduo_net)

