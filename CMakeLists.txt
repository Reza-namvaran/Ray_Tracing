cmake_minimum_required(VERSION 3.26.1)

project(ray_tracer
    HOMEPAGE_URL "https://github.com/Reza-namvaran/Ray_Tracing"
    LANGUAGES CXX
    VERSION 0.1
)

include_directories(./include)

add_subdirectory(./src)
