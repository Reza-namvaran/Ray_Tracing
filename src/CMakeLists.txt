set (PROJECT_SOURCES
    main.cc
    sphere.cc
    hittable_list.cc
)

add_executable(${PROJECT_NAME}
  ${PROJECT_SOURCES}
)

set_target_properties(${PROJECT_NAME} PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
)