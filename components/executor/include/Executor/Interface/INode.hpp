// Copyright 2023 Pavel Suprunov
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
//

//
// Created by jadjer on 15.08.23.
//

#pragma once

#include <memory>

/**
 * @namespace Executor
 */
namespace Executor
{

class Executor;

/**
 * @namespace Executor::Interface
 */
namespace Interface
{
/**
 * @class INode
 * Interface for node object
 */
class INode
{
    friend Executor;

public:
    /**
     * Virtual default destructor
     */
    virtual ~INode() = default;

protected:
    virtual void spinOnce() = 0;
};

using INodePtr = std::unique_ptr<INode>;

} // namespace Interface
} // namespace Executor