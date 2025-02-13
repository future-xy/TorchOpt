// Copyright 2022 MetaOPT Team. All Rights Reserved.
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
// ==============================================================================

#pragma once
#include <torch/extension.h>

#include <vector>

#include "common.h"

namespace TorchOpt {
TensorArray<3> adamForwardInplace(torch::Tensor &updates, torch::Tensor &mu,
                                  torch::Tensor &nu, const float b1,
                                  const float b2, const float eps,
                                  const float eps_root, const int count);

torch::Tensor adamForwardMu(const torch::Tensor &updates,
                            const torch::Tensor &mu, const float b1);

torch::Tensor adamForwardNu(const torch::Tensor &updates,
                            const torch::Tensor &nu, const float b2);

torch::Tensor adamForwardUpdates(const torch::Tensor &new_mu,
                                 const torch::Tensor &new_nu, const float b1,
                                 const float b2, const float eps,
                                 const float eps_root, const int count);

TensorArray<2> adamBackwardMu(const torch::Tensor &dmu,
                              const torch::Tensor &updates,
                              const torch::Tensor &mu, const float b1);

TensorArray<2> adamBackwardNu(const torch::Tensor &dnu,
                              const torch::Tensor &updates,
                              const torch::Tensor &nu, const float b2);

TensorArray<2> adamBackwardUpdates(const torch::Tensor &dupdates,
                                   const torch::Tensor &updates,
                                   const torch::Tensor &new_mu,
                                   const torch::Tensor &new_nu, const float b1,
                                   const float b2, const int count);
}  // namespace TorchOpt
