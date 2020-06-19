// Copyright 2016 Proyectos y Sistemas de Mantenimiento SL (eProsima).
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

/**
 * @file Endpoint.h
 */

#ifndef _FASTDDS_RTPS_ENDPOINT_H_
#define _FASTDDS_RTPS_ENDPOINT_H_

#include <fastrtps/utils/TimedMutex.hpp>
#include <fastdds/rtps/attributes/EndpointAttributes.h>

namespace eprosima {
namespace fastrtps {
namespace rtps {

class Endpoint
{
public:

    virtual ~Endpoint() = default;

    inline RecursiveTimedMutex& getMutex()
    {
        return mutex_;
    }

    EndpointAttributes& getAttributes()
    {
        return attributes_;
    }

#if HAVE_SECURITY
    bool supports_rtps_protection_;
#endif // HAVE_SECURITY

    RecursiveTimedMutex mutex_;
    EndpointAttributes attributes_;
};

} // namespace rtps
} // namespace fastrtps
} // namespace eprosima

#endif // _FASTDDS_RTPS_ENDPOINT_H_
