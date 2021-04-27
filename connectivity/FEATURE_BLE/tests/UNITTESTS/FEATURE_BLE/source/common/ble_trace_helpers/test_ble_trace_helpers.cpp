/* mbed Microcontroller Library
 * Copyright (c) 2021 ARM Limited
 * SPDX-License-Identifier: Apache-2.0
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "gtest/gtest.h"

#include "ble_trace_helpers.h"
#include "ble/common/UUID.h"

TEST(to_string, UUID)
{
    static constexpr const size_t HYPHENS_DELIMITER_COUNT    = 4;
    static constexpr const size_t LENGTH_OF_LONG_UUID_STRING = \
            2 * UUID::LENGTH_OF_LONG_UUID + HYPHENS_DELIMITER_COUNT + 1;

    static constexpr const char *STRING_UUID_0  = "53880000-65FD-4651-BA8E-91527F06C887";
    static constexpr const char *STRING_UUID_1  = "53880001-65FD-4651-BA8E-91527F06C887";
    static constexpr const char *STRING_UUID_2  = "53880002-65FD-4651-BA8E-91527F06C887";
    static constexpr const char *STRING_UUID_3  = "53880003-65FD-4651-BA8E-91527F06C887";

    const UUID UUID_0 = UUID(STRING_UUID_0);
    const UUID UUID_1 = UUID(STRING_UUID_1);
    const UUID UUID_2 = UUID(STRING_UUID_2);
    const UUID UUID_3 = UUID(STRING_UUID_3);

    EXPECT_TRUE(0 == std::memcmp(ble::to_string(UUID_0), STRING_UUID_0, LENGTH_OF_LONG_UUID_STRING));
    EXPECT_TRUE(0 == std::memcmp(ble::to_string(UUID_1), STRING_UUID_1, LENGTH_OF_LONG_UUID_STRING));
    EXPECT_TRUE(0 == std::memcmp(ble::to_string(UUID_2), STRING_UUID_2, LENGTH_OF_LONG_UUID_STRING));
    EXPECT_TRUE(0 == std::memcmp(ble::to_string(UUID_3), STRING_UUID_3, LENGTH_OF_LONG_UUID_STRING));
}
