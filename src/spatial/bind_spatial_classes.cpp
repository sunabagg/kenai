#include "bind_spatial_classes.h"

#include "transform.h"
#include "camera.h"
#include "i_visual_instance.h"
#include "i_geometry_instance.h"
#include "mesh/bind_mesh_classes.h"
#include "occluder3d.h"
#include "array_occluder3d.h"
#include "base_material3d.h"
#include "box_occluder3d.h"
#include "camera_attributes.h"
#include "camera_attributes_physical.h"
#include "camera_attributes_practical.h"
#include "cubemap.h"
#include "cubemap_array.h"
#include "curve3d.h"
#include "fog_material.h"
#include "orm_material3d.h"
#include "panorama_sky_material.h"
#include "physical_sky_material.h"
#include "procedural_sky_material.h"
#include "quad_occluder3d.h"
#include "skeleton_profile.h"
#include "skeleton_profile_humanoid.h"
#include "skin.h"
#include "sphere_occluder3d.h"
#include "standard_material3d.h"
#include "texture3d.h"
#include "texture3drd.h"
#include "../core/environment.h"
#include "world3d.h"

void lucidware::spatial::bindSpatialClasses(sol::state& lua) {
    bindOccluder3D(lua);
    bindArrayOccluder3D(lua);
    bindBaseMaterial3D(lua);
    bindBoxOccluder3D(lua);
    bindCameraAttributes(lua);
    bindCameraAttributesPhysical(lua);
    bindCameraAttributesPractical(lua);
    bindCubemap(lua);
    bindCubemapArray(lua);
    bindCurve3D(lua);
    bindFogMaterial(lua);
    bindOrmMaterial3D(lua);
    bindPanoramaSkyMaterial(lua);
    bindPhysicalSkyMaterial(lua);
    bindProceduralSkyMaterial(lua);
    bindQuadOccluder3D(lua);
    bindSkeletonProfile(lua);
    bindSkeletonProfileHumanoid(lua);
    bindSkin(lua);
    bindSphereOccluder3D(lua);
    bindStandardMaterial3D(lua);
    bindTexture3D(lua);
    bindTexture3DRD(lua);
    core::bindEnvironment(lua);
    bindWorld3D(lua);
    
    bindSpatialTransform(lua);
    bindCamera(lua);
    bindVisualInstance(lua);
    bindGeometryInstance(lua);
    mesh::bindMeshClasses(lua);
}