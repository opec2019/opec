#Opec monitor module CmakeLists.txt -- libOpec_monitor.a
set(LIB_Opec_MONITOR Opec_monitor)

#Automatically get src files from the specified directory
aux_source_directory(${Opec_SRC_DIR}/monitor/ MONITOR_SRC)

#Generate static library files
add_library(${LIB_Opec_MONITOR} ${MONITOR_SRC})

#Specify compiling options for the target objects
target_compile_options(${LIB_Opec_MONITOR}
    PUBLIC -std=c++11 
    PUBLIC -DASIO_STANDALONE
    PUBLIC -D_WEBSOCKETPP_CPP11_STL_
    PUBLIC -D${OS_NAME}
)
