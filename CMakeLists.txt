
cmake_minimum_required(VERSION 3.16)

project(geant4-cosmics)

set(CMAKE_CXX_STANDARD 17)

set(EXECUTABLE_NAME ${PROJECT_NAME})

find_package(Geant4 REQUIRED ui_all vis_all)
find_package(ROOT REQUIRED)

add_executable(
        ${EXECUTABLE_NAME}
        main.cpp
)

file(GLOB SOURCES ${PROJECT_SOURCE_DIR}/src/*.cpp)
target_include_directories(${EXECUTABLE_NAME} PUBLIC ${ROOT_INCLUDE_DIRS} ${PROJECT_SOURCE_DIR}/include)
target_sources(${EXECUTABLE_NAME} PRIVATE ${SOURCES})
target_link_libraries(${EXECUTABLE_NAME} ${Geant4_LIBRARIES} ${ROOT_LIBRARIES})
