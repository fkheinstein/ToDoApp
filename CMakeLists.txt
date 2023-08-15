cmake_minimum_required(VERSION 3.14)


get_filename_component(PROJ_NAME ${CMAKE_CURRENT_SOURCE_DIR} NAME)
string(REPLACE " " "_" PROJ_NAME ${PROJ_NAME})

project(${PROJ_NAME})



if( UNIX )
	set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -fPIC" )
	set( CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS} -O3")
else()

	set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /std:c++17" )

	set( CMAKE_CXX_STANDARD 17 )
	set( CMAKE_CXX_STANDARD_REQUIRED ON )
	set( CMAKE_CXX_EXTENSIONS ON )


	if( CMAKE_BUILD_TYPE STREQUAL "Debug" )
		# disabling SAFESEH
		message( STATUS "Disabling Safe Exception Handlers.." )
		set( CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /SAFESEH:NO" )

		# edit and continue
		message( STATUS "Enabling Edit and Continue.." )
		add_definitions( /Zi )

		# incremental linking
		message( STATUS "Enabling Incremental Linking.." )
		set( CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /INCREMENTAL" )
  endif()
endif()



# Collect sources into the variable Engine_Core_Src
file (GLOB_RECURSE Core_SRC
"${PROJECT_SOURCE_DIR}/Src/*.txt"
"${PROJECT_SOURCE_DIR}/Src/*.h"
"${PROJECT_SOURCE_DIR}/Src/*.hpp"
"${PROJECT_SOURCE_DIR}/Src/*.cpp")



set(All_SRC
	${Core_SRC}
)

set(SOURCES
	Src/main.cpp
	${All_SRC}
)


add_executable(${PROJ_NAME}   ${SOURCES})