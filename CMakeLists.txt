#
#
#

cmake_minimum_required(VERSION 3.7)

project(Pigsnose)


add_executable(Pigsnose startup.c receptor.c)

target_link_libraries(Pigsnose pcap )

if (APPLE)
    #屏蔽一些在Apple上的warnning
    add_definitions(-Wno-parentheses -fvisibility=hidden -fvisibility-inlines-hidden)
endif()
