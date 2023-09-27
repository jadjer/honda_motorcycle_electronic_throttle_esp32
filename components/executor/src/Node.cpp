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
// Created by jadjer on 25.09.23.
//

#include "Executor/Interface/Node.hpp"

#include "esp_timer.h"

uint32_t convertFrequencyToPeriod_InUS(double frequency)
{
    auto period_InSecond = static_cast<float>(1.0 / frequency);
    auto period_InUS = static_cast<uint32_t>(period_InSecond * 1000000);

    return period_InUS;
}

Executor::Interface::Node::Node(uint32_t frequency) :
    m_updatePeriod_InUS(convertFrequencyToPeriod_InUS(frequency)), m_lastSpinTime_InUS(0)
{
}

void Executor::Interface::Node::setFrequency(uint32_t frequency)
{
    m_updatePeriod_InUS = convertFrequencyToPeriod_InUS(frequency);
}

void Executor::Interface::Node::spinOnce()
{
    auto currentTime_InUS = esp_timer_get_time();
    auto diffTime_InUS = (currentTime_InUS - m_lastSpinTime_InUS);
    if (diffTime_InUS >= m_updatePeriod_InUS)
    {
        m_lastSpinTime_InUS = currentTime_InUS;

        process();
    }
}