cmake_minimum_required (VERSION 3.2.2)
project (CYOND)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED on)

if(MSVC)
    add_definitions(/W4 /WX)
else()
	add_definitions(-pedantic -Wall -Werror)
endif()

#add_subdirectory(Engine)
add_subdirectory(Core)
add_subdirectory(Compiler)
add_subdirectory(Server)
add_subdirectory(Client)
add_subdirectory(Hub)
add_subdirectory(Tests)