#pragma once

#include "nstimer.hpp"
#define CL_USE_DEPRECATED_OPENCL_1_1_APIS
#if defined(__APPLE__) || defined(__MACOSX)
#include <OpenCL/opencl.h>
#else
#include <CL/opencl.h>
#endif

namespace ctmetric
{
    inline cl_int clBuildProgram(cl_program program,
                                 cl_uint num_devices,
                                 const cl_device_id *device_list,
                                 const char *options,
                                 void (*pfn_notify)(cl_program, void *user_data),
                                 void *user_data)
    {
        ctmetric::nstimer timer;
        return ::clBuildProgram(program, num_devices, device_list, options, pfn_notify, user_data);
    }
}
