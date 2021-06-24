#pragma once

#include <iostream>
#include <chrono>

namespace ctmetric
{
    class nstimer
    {
    private:
        using time_t = std::chrono::high_resolution_clock::time_point;
        time_t start;

    public:
        nstimer()
            : start(std::chrono::high_resolution_clock::now()) {}

        ~nstimer()
        {
            report(std::chrono::high_resolution_clock::now());
        }

    private:
        void report(time_t end) const
        {
            auto duration = end - start;
            std::clog << "Finished compiling; total ns = " << std::chrono::nanoseconds(duration).count() << '\n';
        }
    };
}
