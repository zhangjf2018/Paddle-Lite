// Copyright (c) 2020 PaddlePaddle Authors. All Rights Reserved.
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

#pragma once

#include <string>
#include <vector>
#include "lite/core/scope.h"
#include "lite/core/tensor.h"
#include "lite/model_parser/flatbuffers/param_desc.h"
#include "lite/model_parser/flatbuffers/program_desc.h"

namespace paddle {
namespace lite {
namespace fbs {

void LoadModel(const std::string& path, ProgramDesc* prog);

void SetParamWithTensor(const std::string& name,
                        const lite::Tensor& tensor,
                        ParamDescWriteAPI* prog);
void SetTensorWithParam(const lite::Tensor& tensor, ParamDescReadAPI* prog);

void SetCombinedParamsWithScope(const lite::Scope& scope,
                                const std::vector<std::string>& params_name,
                                CombinedParamsDescWriteAPI* params);
void SetScopeWithCombinedParams(lite::Scope* scope,
                                const CombinedParamsDescReadAPI& params);

}  // namespace fbs
}  // namespace lite
}  // namespace paddle