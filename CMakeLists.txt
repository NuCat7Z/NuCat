cmake_minimum_required (VERSION 3.8)

if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("NuCat")
set(CMAKE_CXX_STANDARD 26)
set(CMAKE_POLICY_DEFAULT_CMP0077 NEW)
set(BIT7Z_AUTO_FORMAT true)

if(MSVC)
	add_compile_options("$<$<C_COMPILER_ID:MSVC>:/utf-8>")
	add_compile_options("$<$<CXX_COMPILER_ID:MSVC>:/utf-8>")
endif()
add_subdirectory ("NuCat")
add_subdirectory("Dependencies/bit7z")
# 移动NUCAT资源文件进主程序 Debug目录
file(COPY "${CMAKE_CURRENT_SOURCE_DIR}/Resource/" DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/NuCat/)