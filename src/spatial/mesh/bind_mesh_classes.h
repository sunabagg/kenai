#ifndef BIND_MESH_CLASSES_H
#define BIND_MESH_CLASSES_H

#include <sol/sol.hpp>

namespace kenai::spatial::mesh
{
    void bindMeshClasses(sol::state& lua);
}

#endif