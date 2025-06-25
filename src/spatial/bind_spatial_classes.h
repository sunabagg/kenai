#ifndef BIND_SPATIAL_H
#define BIND_SPATIAL_H

#include <sol/sol.hpp>

namespace lucidfx::spatial
{
    void bindSpatialClasses(sol::state& lua);
}

#endif