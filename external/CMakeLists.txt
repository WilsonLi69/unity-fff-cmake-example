set(UNITY_DIR "Unity")
set(FFF_DIR "fff")

add_library(Unity STATIC ${UNITY_DIR}/src/unity.c)
target_include_directories(Unity PUBLIC ${UNITY_DIR}/src)

add_library(fff INTERFACE)
target_include_directories(fff INTERFACE ${FFF_DIR})
