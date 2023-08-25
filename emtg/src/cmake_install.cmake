# Install script for directory: /home/ml/p/EMTG/emtg/src

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/var/empty/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "0")
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

# Set default install directory permissions.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "/nix/store/bxic6j2whyg3z4h2x3xjyqgp7fl83bnp-gcc-wrapper-12.3.0/bin/objdump")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}/home/ml/p/EMTG/emtg/bin/EMTGv9" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/home/ml/p/EMTG/emtg/bin/EMTGv9")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}/home/ml/p/EMTG/emtg/bin/EMTGv9"
         RPATH "")
  endif()
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/ml/p/EMTG/emtg/bin/EMTGv9")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  file(INSTALL DESTINATION "/home/ml/p/EMTG/emtg/bin" TYPE EXECUTABLE FILES "/home/ml/p/EMTG/emtg/src/EMTGv9")
  if(EXISTS "$ENV{DESTDIR}/home/ml/p/EMTG/emtg/bin/EMTGv9" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/home/ml/p/EMTG/emtg/bin/EMTGv9")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}/home/ml/p/EMTG/emtg/bin/EMTGv9"
         OLD_RPATH "/home/ml/p/EMTG/emtg/Release:/home/ml/p/EMTG/emtg/Debug:/home/ml/p/EMTG/emtg/../cspice/lib:/lib:"
         NEW_RPATH "")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/nix/store/bxic6j2whyg3z4h2x3xjyqgp7fl83bnp-gcc-wrapper-12.3.0/bin/strip" "$ENV{DESTDIR}/home/ml/p/EMTG/emtg/bin/EMTGv9")
    endif()
  endif()
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("/home/ml/p/EMTG/emtg/src/Astrodynamics/cmake_install.cmake")
  include("/home/ml/p/EMTG/emtg/src/Core/cmake_install.cmake")
  include("/home/ml/p/EMTG/emtg/src/Executable/cmake_install.cmake")
  include("/home/ml/p/EMTG/emtg/src/HardwareModels/cmake_install.cmake")
  include("/home/ml/p/EMTG/emtg/src/InnerLoop/cmake_install.cmake")
  include("/home/ml/p/EMTG/emtg/src/Integration/cmake_install.cmake")
  include("/home/ml/p/EMTG/emtg/src/Math/cmake_install.cmake")
  include("/home/ml/p/EMTG/emtg/src/Mission/cmake_install.cmake")
  include("/home/ml/p/EMTG/emtg/src/Propagation/cmake_install.cmake")
  include("/home/ml/p/EMTG/emtg/src/Utilities/cmake_install.cmake")
  include("/home/ml/p/EMTG/emtg/src/Scalatron/cmake_install.cmake")
  include("/home/ml/p/EMTG/emtg/src/SplineEphem/cmake_install.cmake")

endif()

