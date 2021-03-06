add_subdirectory(buffer)
add_subdirectory(channel)
add_subdirectory(event)
add_subdirectory(hash)
add_subdirectory(stats)
add_subdirectory(stream)
add_subdirectory(time)

set(SOURCE
    ${SOURCE}
    cc_array.c
    cc_bstring.c
    cc_debug.c
    cc_log.c
    cc_mm.c
    cc_option.c
    cc_print.c
    cc_rbuf.c
    cc_ring_array.c
    cc_signal.c)

# targets to build: here we have both static and dynamic libs
set(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/lib)
add_library(${PROJECT_NAME}-static STATIC ${SOURCE})
add_library(${PROJECT_NAME}-shared SHARED ${SOURCE})
if (OS_PLATFORM STREQUAL "OS_LINUX")
  target_link_libraries(${PROJECT_NAME}-static rt m pthread)
  target_link_libraries(${PROJECT_NAME}-shared rt m pthread)
endif(OS_PLATFORM STREQUAL "OS_LINUX")
set_target_properties(${PROJECT_NAME}-static
    PROPERTIES
    OUTPUT_NAME ${PROJECT_NAME}-${${PROJECT_NAME}_VERSION})
set_target_properties (${PROJECT_NAME}-shared
    PROPERTIES
    OUTPUT_NAME ${PROJECT_NAME}
    VERSION ${${PROJECT_NAME}_VERSION}
    SOVERSION 0)

# install instructions
install(TARGETS ${PROJECT_NAME}-static DESTINATION lib)
install(TARGETS ${PROJECT_NAME}-shared DESTINATION lib)
install(DIRECTORY ../include/
    DESTINATION include/${PROJECT_NAME}-${${PROJECT_NAME}_RELEASE_VERSION}
    FILES_MATCHING PATTERN "*")
