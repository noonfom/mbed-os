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
    static constexpr const char UUID_STRINGS[][sizeof "AB581451-AC37-462D-A54E-DB48C5A55EA3"] = {
            "AB581451-AC37-462D-A54E-DB48C5A55EA3",
            "221933EE-73EE-4765-9CD6-CC4ADB018113",
            "A1B23DA3-85E3-4A8A-AC3D-B2D70B68B275",
            "6318EFB9-CFCC-48CE-97BF-CD3EF34DC528"
    };

    for (auto &uuid_string : UUID_STRINGS) {
        ASSERT_STREQ(uuid_string, ble::to_string(UUID(uuid_string)));
    }
}
