cmake_minimum_required(VERSION 2.8)

project(hdt)

set(Boost_USE_STATIC_LIBS OFF)
set(Boost_USE_MULTITHREADED ON)
set(Boost_USE_STATIC_RUNTIME OFF)
find_package(Boost 1.69.0 COMPONENTS filesystem regex program_options)

include_directories(/usr/local/mysql-connector-cpp/include)
link_directories(/usr/local/mysql-connector-cpp/lib)

set(SOURCES
   src/main.cpp
   src/command-parser.cpp
   src/init.cpp
   src/filesystem.cpp
   src/config.cpp
   src/tinyxml2.cpp
   src/mysql-connector.cpp
)

set(HEADERS
   include/command-parser.h
   include/init.h
   include/filesystem.h
   include/config.h
   include/fileable.h
   include/tinyxml2.h
   include/connector.h
   include/mysql-connector.h
)

include_directories(include)
#add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})
if(Boost_FOUND)
    add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})
    target_link_libraries(${PROJECT_NAME} ${Boost_LIBRARIES} mysqlcppconn)
endif()

