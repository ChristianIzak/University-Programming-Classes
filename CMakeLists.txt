cmake_minimum_required(VERSION 3.20)
project(CSE220 C)

add_executable(BonusQuestion
    "Bonus Question/main.c"
    "Bonus Question/scheduler.c"
)

add_executable(RobotHomework
    "Robot Homework/main.c"
    "Robot Homework/map.c"
    "Robot Homework/rover.c"
)

# -------------------------
# ClassCodes
# -------------------------
add_executable(array_demo
    "Class/ClassCodes/array.c"
    "Class/ClassCodes/utils.c"
)

# -------------------------
# Matrix
# -------------------------
add_executable(matrix_demo
    "Class/Matrix/main.c"
    "Class/Matrix/matrix.c"
)

# -------------------------
# Max
# -------------------------
add_executable(max_demo
    "Class/Max/main.c"
    "Class/Max/max.c"
)

# -------------------------
# Memory Management
# -------------------------
add_executable(calloc_example
    "Class/Memory Management/callocExample.c"
)

add_executable(malloc_example
    "Class/Memory Management/mallocExample.c"
)

add_executable(memory_free
    "Class/Memory Management/memoryFree.c"
)

add_executable(pointer_allocation
    "Class/Memory Management/pointerAllocation.c"
)

add_executable(practice_demo
    "Class/Memory Management/practice.c"
)

add_executable(realloc_example
    "Class/Memory Management/reallocExample.c"
)

add_executable(worked_example1
    "Class/Memory Management/workedExample1.c"
)

# -------------------------
# Practice Problems
# -------------------------
add_executable(snakes_and_ladders
    "Class/Practice Problems/snakesandladders.c"
    "Class/Practice Problems/utils.c"
)

# -------------------------
# Struct
# -------------------------
add_executable(dynamic_arrays_structures
    "Class/Struct/dynamicArraysOfStructures.c"
    "Class/Struct/structures.c"
)

add_executable(struct_main
    "Class/Struct/main.c"
    "Class/Struct/structures.c"
)

add_executable(struct_example
    "Class/Struct/structExample.c"
    "Class/Struct/structures.c"
)

# -------------------------
# TheMovieDatabase
# -------------------------
add_executable(movie_database_utils
    "Class/TheMovieDatabase/utils.c"
)

# -------------------------
# Lab 1
# -------------------------
add_executable(lab1
    "Labs/Lab 1/lab1.c"
)

add_executable(lab1_profile
    "Labs/Lab 1/lab1_profile.c"
)

add_executable(lab1_variables
    "Labs/Lab 1/lab1_variables.c"
)

# -------------------------
# Lab 7
# -------------------------
add_executable(lab7_copy
    "Labs/Lab 7/copy.c"
)

add_executable(lab7_memory
    "Labs/Lab 7/memory.c"
)

add_executable(lab7_range
    "Labs/Lab 7/range.c"
)

add_executable(lab7_riddler
    "Labs/Lab 7/riddler.c"
)

# -------------------------
# Lab 8
# -------------------------
add_executable(lab8_dictionary
    "Labs/Lab 8/dictionary.c"
)

add_executable(lab8_matrix_mult
    "Labs/Lab 8/matrix_mult.c"
)

add_executable(lab8_tensor
    "Labs/Lab 8/tensor.c"
)

# -------------------------
# Lab 9
# -------------------------
add_executable(Lab9Cipher
    "Labs/Lab 9/cipher.c"
)

add_executable(Lab9Clues
    "Labs/Lab 9/clues.c"
)

add_executable(Lab9Hoard
    "Labs/Lab 9/hoard.c"
)

add_executable(Lab9Secrets
    "Labs/Lab 9/secrets.c"
)

# -------------------------
# Lab 10
# -------------------------
add_executable(Lab10Band
    "Labs/Lab 10/band.c"
)

add_executable(Lab10Dairy
    "Labs/Lab 10/dairy.c"
)

add_executable(Lab10Roster
    "Labs/Lab 10/roster.c"
)

add_executable(Lab10Schedule
    "Labs/Lab 10/schedule.c"
)

# -------------------------
# Lab 11
# -------------------------
add_executable(Hogwarts
    "Labs/Lab 11/main.c"
    "Labs/Lab 11/map.c"
)