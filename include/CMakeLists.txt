target_include_directories(concept INTERFACE 
	$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}> 
	$<INSTALL_INTERFACE:include/concept>)

set(headers 
	concept.hpp)

install(FILES ${headers} DESTINATION include/concept)