/// Copyright 2025 HarvestX Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef __MG400_PLUGIN_PLUGIN_UTILS_HPP__
#define __MG400_PLUGIN_PLUGIN_UTILS_HPP__

#include <string>
#include <rclcpp/rclcpp.hpp>

namespace mg400_plugin
{

namespace plugin_utils
{


const uint8_t SPEED_FACTOR_MIN = 1, SPEED_FACTOR_MAX = 100;
const uint8_t SPEED_J_MIN = 1, SPEED_J_MAX = 100;
const uint8_t SPEED_L_MIN = 1, SPEED_L_MAX = 100;
const uint8_t ACC_J_MIN = 1, ACC_J_MAX = 100;
const uint8_t ACC_L_MIN = 1, ACC_L_MAX = 100;
const uint8_t CP_MIN = 0, CP_MAX = 100;


template<typename T>
inline T clampWithWarning(
  T value, T min, T max, const rclcpp::Logger & logger, const std::string & arg_name)
{
  if (value < min) {
    RCLCPP_WARN(
      logger, "%s clamped from %d to %d",
      arg_name.c_str(), static_cast<int>(value), static_cast<int>(min));
    return min;
  } else if (value > max) {
    RCLCPP_WARN(
      logger, "%s clamped from %d to %d",
      arg_name.c_str(), static_cast<int>(value), static_cast<int>(max));
    return max;
  }
  return value;
}

}  // namespace plugin_utils

}  // namespace mg400_plugin

#endif  // __MG400_PLUGIN_PLUGIN_UTILS_HPP__
