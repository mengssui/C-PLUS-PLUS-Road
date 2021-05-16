# Install script for directory: /home/mengbw/muduo_server_learn/src/13/jmuduo/muduo/base

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Debug")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "/home/mengbw/muduo_server_learn/src/13/jmuduo/tests/lib/libmuduo_base.a")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/muduo/base" TYPE FILE FILES
    "/home/mengbw/muduo_server_learn/src/13/jmuduo/muduo/base/Types.h"
    "/home/mengbw/muduo_server_learn/src/13/jmuduo/muduo/base/Timestamp.h"
    "/home/mengbw/muduo_server_learn/src/13/jmuduo/muduo/base/CurrentThread.h"
    "/home/mengbw/muduo_server_learn/src/13/jmuduo/muduo/base/copyable.h"
    "/home/mengbw/muduo_server_learn/src/13/jmuduo/muduo/base/Thread.h"
    "/home/mengbw/muduo_server_learn/src/13/jmuduo/muduo/base/Atomic.h"
    "/home/mengbw/muduo_server_learn/src/13/jmuduo/muduo/base/Exception.h"
    )
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("/home/mengbw/muduo_server_learn/src/13/jmuduo/tests/muduo/base/tests/cmake_install.cmake")

endif()

