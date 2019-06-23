Target_Include_Directories(Concept INTERFACE 
	$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}> 
	$<INSTALL_INTERFACE:include/Concept>)

Set(Headers 
	Concept.hpp)

Install(FILES ${Headers} DESTINATION include/Concept)