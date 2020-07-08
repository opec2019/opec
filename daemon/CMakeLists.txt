#Opec daemon module CmakeLists.txt

set(DEAMON_DEPENDS_LIB ssl crypto)

# -- Opec_Opecd -- #
set(BIN_Opec_ID Opecd)

add_executable(${BIN_Opec_ID} ./Opec/main.cpp)


IF (${OS_NAME} MATCHES "OS_LINUX")  
    MESSAGE(STATUS "current platform: Linux ")  
	target_link_libraries(${BIN_Opec_ID} -Wl,-dn ${DEAMON_DEPENDS_LIB} ${Opec_LINKER_FLAGS})
ELSE ()  
	MESSAGE(STATUS "current platform: MAC ")  
	target_link_libraries(${BIN_Opec_ID} -Wl, ${DEAMON_DEPENDS_LIB} ${Opec_LINKER_FLAGS})
ENDIF () 



target_compile_options(${BIN_Opec_ID}
    PUBLIC -std=c++11
    PUBLIC -D${OS_NAME}
)

install(TARGETS ${BIN_Opec_ID}
    RUNTIME DESTINATION ${OpecCHAIN}/bin
)

