project(foreign-softpy-test C CXX)

find_package(PythonLibs)
#message("PYTHONLIBS_VERSION_STRING=${PYTHONLIBS_VERSION_STRING}")
set(Python_ADDITIONAL_VERSIONS "${PYTHONLIBS_VERSION_STRING}")
find_package(PythonInterp)


if(PYTHONINTERP_FOUND AND PYTHONLIBS_FOUND)

  set(CMAKE_INCLUDE_CURRENT_DIR ON)

  add_test(${PROJECT_NAME}
    ${PYTHON_EXECUTABLE} ${CMAKE_CURRENT_SOURCE_DIR}/softpy-test.py)

  # Set environment
  if(UNIX)
    set_property(TEST ${PROJECT_NAME} PROPERTY
      ENVIRONMENT "LD_LIBRARY_PATH=${LD_LIBRARY_PATH}:$ENV{LD_LIBRARY_PATH}")
  else()
    set_property(TEST ${PROJECT_NAME} PROPERTY
      ENVIRONMENT "PATH=${PATH}:$ENV{PATH}")
  endif()

  set_property(TEST ${PROJECT_NAME} APPEND PROPERTY
    ENVIRONMENT "SOFTSTORAGE=${SOFTSTORAGE}:$ENV{SOFTSTORAGE}")

  set_property(TEST ${PROJECT_NAME} APPEND PROPERTY
    ENVIRONMENT "PYTHONPATH=${softpy_BINARY_DIR}:$ENV{PYTHONPATH}")

else()
  message("Python not found - skipping tests")
endif()
