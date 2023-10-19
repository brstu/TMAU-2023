cmake_minimum_required (VERSION 3.0.0)

project (TMAU) 

# Search for directories simular to "trunk/as000xxyy/task_0x/src/"
file(GLOB V_GLOB RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} "trunk/*/*/src/")
foreach(item ${V_GLOB})
	message( "Find \"${item}\"" )
	add_subdirectory(${item})		
endforeach()