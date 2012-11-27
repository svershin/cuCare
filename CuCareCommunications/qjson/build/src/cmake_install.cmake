# Install script for directory: /home/mike/4pupsRepo/cucare/CuCareCommunications/qjson/src

# Set the install prefix
IF(NOT DEFINED CMAKE_INSTALL_PREFIX)
  SET(CMAKE_INSTALL_PREFIX "/home/mike/4pupsRepo/cucare/CuCareCommunications/qjson/build/_preferred_path_")
ENDIF(NOT DEFINED CMAKE_INSTALL_PREFIX)
STRING(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
IF(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  IF(BUILD_TYPE)
    STRING(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  ELSE(BUILD_TYPE)
    SET(CMAKE_INSTALL_CONFIG_NAME "RelWithDebInfo")
  ENDIF(BUILD_TYPE)
  MESSAGE(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
ENDIF(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)

# Set the component getting installed.
IF(NOT CMAKE_INSTALL_COMPONENT)
  IF(COMPONENT)
    MESSAGE(STATUS "Install component: \"${COMPONENT}\"")
    SET(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  ELSE(COMPONENT)
    SET(CMAKE_INSTALL_COMPONENT)
  ENDIF(COMPONENT)
ENDIF(NOT CMAKE_INSTALL_COMPONENT)

# Install shared libraries without execute permission?
IF(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  SET(CMAKE_INSTALL_SO_NO_EXE "1")
ENDIF(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Devel")
  list(APPEND CPACK_ABSOLUTE_DESTINATION_FILES
   "/home/mike/4pupsRepo/cucare/CuCareCommunications/qjson/build/_preferred_path_/include/qjson/parser.h;/home/mike/4pupsRepo/cucare/CuCareCommunications/qjson/build/_preferred_path_/include/qjson/parserrunnable.h;/home/mike/4pupsRepo/cucare/CuCareCommunications/qjson/build/_preferred_path_/include/qjson/qobjecthelper.h;/home/mike/4pupsRepo/cucare/CuCareCommunications/qjson/build/_preferred_path_/include/qjson/serializer.h;/home/mike/4pupsRepo/cucare/CuCareCommunications/qjson/build/_preferred_path_/include/qjson/serializerrunnable.h;/home/mike/4pupsRepo/cucare/CuCareCommunications/qjson/build/_preferred_path_/include/qjson/qjson_export.h")
FILE(INSTALL DESTINATION "/home/mike/4pupsRepo/cucare/CuCareCommunications/qjson/build/_preferred_path_/include/qjson" TYPE FILE FILES
    "/home/mike/4pupsRepo/cucare/CuCareCommunications/qjson/src/parser.h"
    "/home/mike/4pupsRepo/cucare/CuCareCommunications/qjson/src/parserrunnable.h"
    "/home/mike/4pupsRepo/cucare/CuCareCommunications/qjson/src/qobjecthelper.h"
    "/home/mike/4pupsRepo/cucare/CuCareCommunications/qjson/src/serializer.h"
    "/home/mike/4pupsRepo/cucare/CuCareCommunications/qjson/src/serializerrunnable.h"
    "/home/mike/4pupsRepo/cucare/CuCareCommunications/qjson/src/qjson_export.h"
    )
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Devel")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  FOREACH(file
      "$ENV{DESTDIR}/home/mike/4pupsRepo/cucare/CuCareCommunications/qjson/build/_preferred_path_/lib/libqjson.so.0.7.1"
      "$ENV{DESTDIR}/home/mike/4pupsRepo/cucare/CuCareCommunications/qjson/build/_preferred_path_/lib/libqjson.so.0"
      "$ENV{DESTDIR}/home/mike/4pupsRepo/cucare/CuCareCommunications/qjson/build/_preferred_path_/lib/libqjson.so"
      )
    IF(EXISTS "${file}" AND
       NOT IS_SYMLINK "${file}")
      FILE(RPATH_CHECK
           FILE "${file}"
           RPATH "")
    ENDIF()
  ENDFOREACH()
  list(APPEND CPACK_ABSOLUTE_DESTINATION_FILES
   "/home/mike/4pupsRepo/cucare/CuCareCommunications/qjson/build/_preferred_path_/lib/libqjson.so.0.7.1;/home/mike/4pupsRepo/cucare/CuCareCommunications/qjson/build/_preferred_path_/lib/libqjson.so.0;/home/mike/4pupsRepo/cucare/CuCareCommunications/qjson/build/_preferred_path_/lib/libqjson.so")
FILE(INSTALL DESTINATION "/home/mike/4pupsRepo/cucare/CuCareCommunications/qjson/build/_preferred_path_/lib" TYPE SHARED_LIBRARY FILES
    "/home/mike/4pupsRepo/cucare/CuCareCommunications/qjson/build/lib/libqjson.so.0.7.1"
    "/home/mike/4pupsRepo/cucare/CuCareCommunications/qjson/build/lib/libqjson.so.0"
    "/home/mike/4pupsRepo/cucare/CuCareCommunications/qjson/build/lib/libqjson.so"
    )
  FOREACH(file
      "$ENV{DESTDIR}/home/mike/4pupsRepo/cucare/CuCareCommunications/qjson/build/_preferred_path_/lib/libqjson.so.0.7.1"
      "$ENV{DESTDIR}/home/mike/4pupsRepo/cucare/CuCareCommunications/qjson/build/_preferred_path_/lib/libqjson.so.0"
      "$ENV{DESTDIR}/home/mike/4pupsRepo/cucare/CuCareCommunications/qjson/build/_preferred_path_/lib/libqjson.so"
      )
    IF(EXISTS "${file}" AND
       NOT IS_SYMLINK "${file}")
      IF(CMAKE_INSTALL_DO_STRIP)
        EXECUTE_PROCESS(COMMAND "/usr/bin/strip" "${file}")
      ENDIF(CMAKE_INSTALL_DO_STRIP)
    ENDIF()
  ENDFOREACH()
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

