cmake_minimum_required(VERSION 4.0)
project(C_CORP_ERP C)

set(CMAKE_C_STANDARD 23)

add_executable(C_CORP_ERP main.c
        structs.h
        tools.c
        tools.h
        personel.c
        personel.h
        dosya.c
        dosya.h)
