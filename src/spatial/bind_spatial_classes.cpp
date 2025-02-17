#include "bind_spatial_classes.h"

#include "transform.h"
#include "camera.h"
#include "i_visual_instance.h"
#include "i_geometry_instance.h"
#include "mesh/bind_mesh_classes.h"

void sunaba::spatial::bindSpatialClasses(sol::state& lua) {
    bindSpatialTransform(lua);
    bindCamera(lua);
    bindVisualInstance(lua);
    bindGeometryInstance(lua);
    mesh::bindMeshClasses(lua);
}