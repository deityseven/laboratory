project(template)

#C++标准 
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#全局moc
set(CMAKE_AUTOMOC ON)

#使用rcc处理qrc
set(IMAGE_RCCS ../resource/resource.qrc)
qt5_add_resources(IMAGE_RCC_SRCS ${IMAGE_RCCS})

#ui文件
file(GLOB uis "${CMAKE_SOURCE_DIR}/src/ui/*.ui")

#uic
QT5_WRAP_UI(UI_FILES
  ${uis}
)

set(UI_SRC
	${uis}
)

set(WIDGET_SRC
)
set(MAIN_SRC
	main.cpp
)

set(DATA_SRC
	datamanager.h
)

set(STRUCT_SRC
	${CMAKE_SOURCE_DIR}/external/common/common.h
)

set(UTIL_SRC
	${CMAKE_SOURCE_DIR}/external/common/util.h
	config.h
	config.cpp
)

set(SRCS 
	${WIDGET_SRC}
	${MAIN_SRC}
	${DATA_SRC}
	${STRUCT_SRC}
	${UTIL_SRC}
)

#筛选显示
source_group(struct FILES ${STRUCT_SRC})
source_group(util FILES ${UTIL_SRC})
source_group(data FILES ${DATA_SRC})
source_group(main FILES ${MAIN_SRC})
source_group(widget FILES ${WIDGET_SRC})
source_group(ui FILES ${UI_SRC})

#包含目录
include_directories(${CMAKE_CURRENT_BINARY_DIR}
					${CMAKE_SOURCE_DIR}/external
					${CMAKE_SOURCE_DIR}/external/common
)

#库目录
link_directories(
	#${CMAKE_CURRENT_BINARY_DIR}
    ${CMAKE_LIBRARY_OUTPUT_DIRECTORY}
)

#指定编译字符集
if(WIN32)
add_compile_options(/utf-8)
endif(WIN32)

#预编译宏
#add_definitions(XXXX)

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
add_executable(${PROJECT_NAME} WIN32 ${SRCS} ${UI_FILES} ${IMAGE_RCC_SRCS})
#共享库
#add_library(${PROJECT_NAME} SHARED ${SRCS} ${UI_FILES} ${IMAGE_RCC_SRCS})

set_property(TARGET ${PROJECT_NAME} PROPERTY VS_DEBUGGER_WORKING_DIRECTORY ${output_dir}/bin/${CMAKE_CFG_INTDIR})
set_property(TARGET ${PROJECT_NAME} PROPERTY VS_DEBUGGER_ENVIRONMENT "Path=$(Path);${CMAKE_PREFIX_PATH}/bin")

#链接库
target_link_libraries(${PROJECT_NAME}
  ${Qt5Core_LIBRARIES}
  ${Qt5Gui_LIBRARIES}
  ${Qt5Widgets_LIBRARIES}
  ${Qt5Sql_LIBRARIES}
  ${Qt5Charts_LIBRARIES}
  ${Qt5Xml_LIBRARIES}
  ${Qt5PrintSupport_LIBRARIES}
  ${Qt5WebEngineWidgets_LIBRARIES}
  ${Qt5Network_LIBRARIES}
)
