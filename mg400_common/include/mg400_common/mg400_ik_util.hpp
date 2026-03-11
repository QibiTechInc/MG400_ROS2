// Copyright 2023 HarvestX Inc.
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

#ifndef __MG400_COMMON_MG400_IK_UTIL_HPP__
#define __MG400_COMMON_MG400_IK_UTIL_HPP__

#include <cmath>
#include <vector>
#include <eigen3/Eigen/Dense>

#include "mg400_common/kinematics.hpp"

namespace mg400_common
{
const double J1_MIN = kinematics::J1_MIN;
const double J1_MAX = kinematics::J1_MAX;
const double J2_MIN = kinematics::J2_MIN;
const double J2_MIN_NO_COLLISION = kinematics::J2_MIN_NO_COLLISION;
const double J2_MAX = kinematics::J2_MAX;
const double J3_MIN = kinematics::J3_MIN;
const double J3_MAX = kinematics::J3_MAX;
const double J31_MIN = kinematics::J3_1_MIN;
const double J31_MAX = kinematics::J3_1_MAX;
const double J4_MIN = kinematics::J4_MIN;
const double J4_MAX = kinematics::J4_MAX;

const double LINK1_X = kinematics::LINK1(0);
const double LINK1_Y = kinematics::LINK1(1);
const double LINK1_Z = kinematics::LINK1(2);

const double LINK2_X = kinematics::LINK2(0);
const double LINK2_Y = kinematics::LINK2(1);
const double LINK2_Z = kinematics::LINK2(2);

const double LINK3_X = kinematics::LINK3(0);
const double LINK3_Y = kinematics::LINK3(1);
const double LINK3_Z = kinematics::LINK3(2);

const double LINK4_X = kinematics::LINK4(0);
const double LINK4_Y = kinematics::LINK4(1);
const double LINK4_Z = kinematics::LINK4(2);

class MG400IKUtil
{
private:
  static constexpr double ROUND_DECIMALS = 8;

public:
  MG400IKUtil() = default;
  bool InMG400Range(const std::vector<double> &);
  std::vector<double> InverseKinematics(const std::vector<double> &);
  std::vector<double> ToolCoordToBaseCoord(
    const std::vector<double> &,
    const std::vector<double> &);
};

}  // namespace mg400_common
#endif
