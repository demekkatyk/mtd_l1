cmake_minimum_required(VERSION 3.10)
project(mtd_l1)

# Указываем стандарт C
set(CMAKE_C_STANDARD 11)

# Target для task3.c
add_executable(task3 task3.c)

# Target для lab6
add_executable(lab6 lab6/lab6.c)
