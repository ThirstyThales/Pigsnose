#
#
#

cmake_minimum_required(VERSION 3.7)

project(Pigsnose)

add_executable(Pigsnose startup.c receptor.c)



if (APPLE)
	target_link_libraries(Pigsnose pcap )
    #屏蔽一些在Apple上的warnning
    add_definitions(-Wno-parentheses -fvisibility=hidden -fvisibility-inlines-hidden)
elseif(WIN32)
	#设定WinPcap的路径
	target_link_libraries(Pigsnose "C:/Program Files (x86)/WinPcap/Lib/wpcap.lib")
	include_directories("C:/Program Files (x86)/WinPcap/Include")
endif()
