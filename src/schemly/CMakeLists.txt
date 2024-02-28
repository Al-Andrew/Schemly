add_executable(schemly)

target_include_directories(schemly PRIVATE ${CMAKE_BINARY_DIR}/include)

target_sources(schemly
    PRIVATE
        main.cpp
)

target_link_libraries(schemly
    PRIVATE
    raylib
)