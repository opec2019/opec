#Opec tools module CmakeLists.txt -- libOpectools.so

set(LIB_Opec_TOOLS Opectools)
set(TOOLS_SRC
    lib_Opec_tools.cpp
)

set(INNER_TOOLS_LIBS Opec_common Opec_utils Opec_ed25519)
set(Opec_TOOLS_DEPENDS_LIBS json ssl crypto scrypt)


#Generate share library files
add_library(${LIB_Opec_TOOLS} SHARED ${TOOLS_SRC}) 

target_link_libraries(${LIB_Opec_TOOLS} ${INNER_TOOLS_LIBS} ${Opec_TOOLS_DEPENDS_LIBS})

#Specify compiling options for target objects
target_compile_options(${LIB_Opec_TOOLS}
    PUBLIC -std=c++11 
    PUBLIC -DASIO_STANDALONE
    PUBLIC -D_WEBSOCKETPP_CPP11_STL_
    PUBLIC -D${OS_NAME}
)
