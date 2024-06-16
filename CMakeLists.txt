cmake_minimum_required(VERSION 3.27)
project(bank)

set(CMAKE_CXX_STANDARD 17)

add_executable(bank main.cpp
        Client.h
        Client.cpp
        Account.h
        Account.cpp
        Transaction.h
        Transaction.cpp
        Database.h
        Database.cpp)
