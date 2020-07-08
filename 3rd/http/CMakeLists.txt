#Opec http module CmakeLists.txt -- libOpec_http.a

set(LIB_Opec_HTTP Opec_http)
aux_source_directory(${Opec_SRC_DIR}/3rd/http/ HTTP_SRC)

add_library(${LIB_Opec_HTTP} ${HTTP_SRC})

target_compile_options(${LIB_Opec_HTTP}
    PUBLIC -std=c++11 
    PUBLIC -DASIO_STANDALONE
    PUBLIC -D${OS_NAME}
)
