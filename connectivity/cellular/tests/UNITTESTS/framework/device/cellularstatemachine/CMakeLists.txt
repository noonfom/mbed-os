# Copyright (c) 2021 ARM Limited. All rights reserved.
# SPDX-License-Identifier: Apache-2.0

set(TEST_NAME cellular-framework-device-cellular-state-machine-unittest)

add_executable(${TEST_NAME})

target_compile_definitions(${TEST_NAME}
    PRIVATE
        MDMRTS=PTC0
        MDMCTS=PTC1
        MDMTXD=NC
        MDMRXD=NC
        CELLULAR_DEVICE=myCellularDevice
        DEVICE_SERIAL_FC=1
        MBED_CONF_RTOS_PRESENT=1
        DEVICE_SERIAL=1
        DEVICE_INTERRUPTIN=1
        MBED_CONF_PLATFORM_DEFAULT_SERIAL_BAUD_RATE=115200
)

target_sources(${TEST_NAME}
    PRIVATE
        ${mbed-os_SOURCE_DIR}/connectivity/cellular/source/framework/device/CellularStateMachine.cpp
        cellularstatemachinetest.cpp
)

target_link_libraries(${TEST_NAME}
    PRIVATE
        mbed-headers
        mbed-stubs
        mbed-stubs-headers
        gmock_main
)

add_test(NAME "${TEST_NAME}" COMMAND ${TEST_NAME})

set_tests_properties(${TEST_NAME} PROPERTIES LABELS "cellular")
