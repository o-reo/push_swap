project(Pushswap)

set(CMAKE_CXX_STANDARD 11)


file(GLOB_RECURSE PS_SRCS ${PS_SRCS} src/*.c)
file(GLOB_RECURSE PS_SRCS ${PS_SRCS} libft/*.c)
file(GLOB_RECURSE PS_SRCS ${PS_SRCS} *.h)

include_directories(includes)
include_directories(libft/includes)

add_executable(Pushswap ${PS_SRCS})