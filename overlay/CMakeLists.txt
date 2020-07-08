#Opec overlay module CmakeLists.txt -- libOpec_overlay.a

set(LIB_Opec_OVERLAY Opec_overlay)
#Automatically get src files from the specified directory
aux_source_directory(${Opec_SRC_DIR}/overlay/ OVERLAY_SRC)

#Generate static library files
add_library(${LIB_Opec_OVERLAY} ${OVERLAY_SRC})

#Specify compiling options for the target objects
target_compile_options(${LIB_Opec_OVERLAY}
    PUBLIC -std=c++11 
    PUBLIC -DASIO_STANDALONE
    PUBLIC -D_WEBSOCKETPP_CPP11_STL_
    PUBLIC -D${OS_NAME}
)
