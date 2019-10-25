cmake_minimum_required (VERSION 2.8)

set (PROJECT_NAME EventManager)

project (${PROJECT_NAME})

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/../Bin)

#include_directories("FastDelegate")

set ( HDR

    )

set ( SRC
        main.cpp
    )
	
# Executable
add_executable(${PROJECT_NAME}
                ${HDR} 
                ${SRC} 
            )


target_link_libraries(${PROJECT_NAME} 
#                            FEngine
                     )

