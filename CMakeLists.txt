CMake_Minimum_Required(VERSION 3.13)

Project(Concept)

If(DEFINED TESTING)
	If(${TESTING} STREQUAL true)
		Add_Executable(Concept "Test/Main.cpp")
		Target_Compile_Definitions(Concept PRIVATE TESTING)
		Add_Subdirectory(Test)
	Else()
		Add_Library(Concept INTERFACE)
	EndIf()
	Unset(TESTING CACHE)
ELSE()
	Add_Library(Concept INTERFACE)
EndIf()

Add_Subdirectory(Source)
Add_Subdirectory(Include)
Add_Subdirectory(Imp)

Target_Compile_Features(Concept 
    INTERFACE cxx_std_17)

Set(CMAKE_CXX_STANDARD "libc++")
#Set(CMAKE_CXX_FLAGS "-Wall" "-Wextra")

Install(TARGETS Concept EXPORT Concept DESTINATION lib/Concept)
Install(EXPORT Concept DESTINATION lib/Concept)
Install(FILES ConceptConfig.cmake DESTINATION lib/Concept)