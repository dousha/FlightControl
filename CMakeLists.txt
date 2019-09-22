SET(CMAKE_SYSTEM_NAME Generic)
SET(CMAKE_SYSTEM_VERSION 1)
cmake_minimum_required(VERSION 3.7)

SET(CMAKE_C_COMPILER_WORKS 1)
SET(CMAKE_C_COMPILER arm-none-eabi-gcc)
SET(CMAKE_CXX_COMPILER_WORKS 1)
SET(CMAKE_CXX_COMPILER arm-none-eabi-g++)
set(CMAKE_ASM_COMPILER arm-none-eabi-gcc)
set(CMAKE_AR arm-none-eabi-ar)
set(CMAKE_OBJCOPY arm-none-eabi-objcopy)
set(CMAKE_OBJDUMP arm-none-eabi-objdump)
set(SIZE arm-none-eabi-size)

SET(LINKER_SCRIPT ${CMAKE_SOURCE_DIR}/TM4C123GH6PM.ld)

SET(FPU_FLAGS "-mfloat-abi=softfp -mfpu=fpv4-sp-d16")
add_definitions(-DARM_MATH_CM4 -DARM_MATH_MATRIX_CHECK -DARM_MATH_ROUNDING -D__FPU_PRESENT=1)

SET(COMMON_FLAGS
		"-mcpu=cortex-m4 ${FPU_FLAGS} -mthumb -ffunction-sections -fdata-sections \
    -fno-common -fmessage-length=0 -specs=nosys.specs -specs=nano.specs -O2")

SET(CMAKE_CXX_FLAGS_INIT "${COMMON_FLAGS} -std=c++11")
SET(CMAKE_C_FLAGS_INIT "${COMMON_FLAGS} -std=gnu99")
SET(CMAKE_EXE_LINKER_FLAGS_INIT "-Wl,--static,--gc-sections,--print-memory-usage -T ${LINKER_SCRIPT}")

PROJECT(FlightControl C CXX ASM)
set(CMAKE_CXX_STANDARD 11)

add_compile_definitions(PART_TM4C123GH6PM TARGET_IS_BLIZZARD_RA1 gcc)

file(GLOB_RECURSE SOURCES "User/*.*" "Libraries/driverlib/*.c" "Libraries/driverlib/gcc/*.*" "src/*.*" "src/**/*.*")

include_directories(Libraries Libraries/inc Libraries/utils Libraries/driverlib driverlib/ Libraries/driverlib/gcc)

add_executable(${PROJECT_NAME}.elf ${SOURCES} ${LINKER_SCRIPT})
target_link_libraries(${PROJECT_NAME}.elf m ${PROJECT_SOURCE_DIR}/Libraries/driverlib/gcc/libdriver.a nosys)

set(CMAKE_EXE_LINKER_FLAGS
		"${CMAKE_EXE_LINKER_FLAGS} -Wl,-Map=${PROJECT_BINARY_DIR}/${PROJECT_NAME}.map")

set(HEX_FILE ${PROJECT_BINARY_DIR}/${PROJECT_NAME}.hex)
set(BIN_FILE ${PROJECT_BINARY_DIR}/${PROJECT_NAME}.bin)

#add_custom_command(TARGET ${PROJECT_NAME}.elf POST_BUILD
#        COMMAND ${CMAKE_OBJCOPY} -Oihex $<TARGET_FILE:${PROJECT_NAME}.elf> ${HEX_FILE}
#        COMMAND ${CMAKE_OBJCOPY} -Obinary $<TARGET_FILE:${PROJECT_NAME}.elf> ${BIN_FILE}
#        COMMENT "Building ${HEX_FILE}
#Building ${BIN_FILE}")

add_custom_command(TARGET ${PROJECT_NAME}.elf POST_BUILD
		COMMAND ${CMAKE_OBJCOPY} -Obinary $<TARGET_FILE:${PROJECT_NAME}.elf> ${BIN_FILE}
		COMMENT "Building ${BIN_FILE}")

add_custom_target(UPLOAD
		arm-none-eabi-gdb -iex "target remote tcp:127.0.0.1:3333"
		-iex "monitor program $<TARGET_FILE:${PROJECT_NAME}.elf>"
		-iex "monitor reset init"
		-iex "disconnect" -iex "quit")
