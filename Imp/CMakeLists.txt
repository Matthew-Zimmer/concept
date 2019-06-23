Target_Include_Directories(Concept INTERFACE 
	$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}> 
	$<INSTALL_INTERFACE:include/Concept>)
	
Set(Imps 
	)

Install(FILES ${Imps} DESTINATION include/Concept)