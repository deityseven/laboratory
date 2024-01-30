project(ansic)

#C标准
set(CMAKE_C_STANDARD 90)
set(CMAKE_C_STANDARD_REQUIRED ON)

set(TEMPLATE_METHOD_SRC
    template-method.h
    template-method.c
    template-method.struct
)

set(SINGLETON_SRC
    singleton.h
    singleton.c
    singleton.struct
)

set(MAN_SRC
    man.h
    man.c
)

set(PERSON_SRC
    person.h
    person.c
)

set(MAIN_SRC
	main.c
)

set(SRCS 
	${MAIN_SRC}
	${PERSON_SRC}
	${MAN_SRC}
	${SINGLETON_SRC}
	${TEMPLATE_METHOD_SRC}
)

#筛选显示
source_group(main FILES ${MAIN_SRC})

#包含目录
include_directories(${CMAKE_CURRENT_BINARY_DIR}
					${CMAKE_SOURCE_DIR}/external
)

#库目录
link_directories(
	#${CMAKE_CURRENT_BINARY_DIR}
    ${CMAKE_LIBRARY_OUTPUT_DIRECTORY}
)

#预编译宏
add_definitions(-Dnullptr=0)
add_definitions(-Dbool=__u_char)
add_definitions(-Dtrue=1)
add_definitions(-Dfalse=0)

if(WIN32)
#链接库
link_libraries( 
)
endif(WIN32)

if(UNIX)
#链接库
link_libraries( 
) 
endif(UNIX)

#可执行文件
add_executable(${PROJECT_NAME} ${SRCS})
#共享库
#add_library(${PROJECT_NAME} SHARED ${SRCS} ${UI_FILES} ${IMAGE_RCC_SRCS})

set_property(TARGET ${PROJECT_NAME} PROPERTY VS_DEBUGGER_WORKING_DIRECTORY ${output_dir}/bin/${CMAKE_CFG_INTDIR})
set_property(TARGET ${PROJECT_NAME} PROPERTY VS_DEBUGGER_ENVIRONMENT "Path=$(Path);${CMAKE_PREFIX_PATH}/bin")

#链接库
target_link_libraries(${PROJECT_NAME}
)
