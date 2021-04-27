####################
# UNIT TESTS
####################

set(unittest-includes ${unittest-includes}
        ../connectivity/FEATURE_BLE/source/common
        ../connectivity/FEATURE_BLE/source
        ../connectivity/FEATURE_BLE/include/ble
        ../connectivity/FEATURE_BLE/include
        ../connectivity/FEATURE_BLE/libraries/cordio_stack/ble-host/sources/stack/cfg
        ../connectivity/FEATURE_BLE/libraries/cordio_stack/ble-host/include
        ../connectivity/FEATURE_BLE/libraries/cordio_stack/wsf/include

        ../platform/mbed-trace/include/mbed-trace
)

set(unittest-sources
        ../connectivity/FEATURE_BLE/source/common/ble_trace_helpers.cpp

        ../platform/mbed-trace/source/mbed_trace.c
)

set(unittest-test-sources
        ${CMAKE_CURRENT_LIST_DIR}/test_ble_trace_helpers.cpp
)

# BLE requires at least one role 'BROADCASTER' or 'OBSERVER' to be enabled
add_compile_definitions(BLE_ROLE_BROADCASTER=1)
