add_library(MathsFunctions myadd.cpp)

target_include_directories(
    MathsFunctions
    INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}
)

install(TARGETS MathsFunctions DESTINATION lib)
install(FILES MathsFunctions.h DESTINATION include)
