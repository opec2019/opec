#Opec main module CmakeLists.txt -- Opec

set(APP_Opec Opec)

set(APP_Opec_SRC
    main.cpp
    configure.cpp
    ../api/web_server.cpp
    ../api/web_server_query.cpp
    ../api/web_server_update.cpp
    ../api/web_server_command.cpp
    ../api/web_server_helper.cpp
    ../api/websocket_server.cpp
    ../api/console.cpp
)

set(INNER_LIBS Opec_glue Opec_ledger Opec_consensus Opec_overlay Opec_common Opec_utils Opec_proto Opec_http Opec_ed25519 Opec_monitor)
set(V8_LIBS v8_base v8_libbase v8_external_snapshot v8_libplatform v8_libsampler icui18n icuuc inspector)

#Generate executable files
add_executable(${APP_Opec} ${APP_Opec_SRC})

#Specify dependent libraries for target objects
	
IF (${OS_NAME} MATCHES "OS_LINUX")  
    MESSAGE(STATUS "current platform: Linux ")  
	target_link_libraries(${APP_Opec}
    -Wl,-dn ${INNER_LIBS} -Wl,--start-group ${V8_LIBS} -Wl,--end-group ${Opec_DEPENDS_LIBS} ${Opec_LINKER_FLAGS})
ELSE ()  
	MESSAGE(STATUS "current platform: MAC ")  
	add_definitions(${Opec_LINKER_FLAGS})
	target_link_libraries(${APP_Opec} ${INNER_LIBS} ${V8_LIBS} ${Opec_DEPENDS_LIBS})
ENDIF () 


#Specify compiling options for target objets
target_compile_options(${APP_Opec}
    PUBLIC -std=c++11 
    PUBLIC -DASIO_STANDALONE
    PUBLIC -D_WEBSOCKETPP_CPP11_STL_
    PUBLIC -D${OS_NAME}
)

install(TARGETS ${APP_Opec}
    RUNTIME DESTINATION ${OpecCHAIN}/bin
)
