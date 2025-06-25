#ifndef CURVE3D_H
#define CURVE3D_H

#include <godot_cpp/classes/curve3d.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <sol/sol.hpp>

#define GodotCurve3D godot::Curve3D

#include "../core/resource.h"

using namespace godot;
using namespace lucidware::core;

namespace lucidware::spatial {
    void bindCurve3D(sol::state_view& lua);

    class Curve3D : public lucidware::core::Resource {
    private:
        GodotCurve3D* curve = nullptr;
    public:
        Curve3D() {
            setCurve3D(memnew(GodotCurve3D));
        }

        Curve3D(GodotCurve3D* c) {
            setCurve3D(c);
        }

        GodotCurve3D* getCurve3D() {
            return curve;
        }

        void setCurve3D(GodotCurve3D* c) {
            curve = c;
            curve->reference();
            setResource(curve);
        }

        float getBakeInterval() {
            return curve->get_bake_interval();
        }

        void setBakeInterval(float interval) {
            curve->set_bake_interval(interval);
        }

        bool getClosed() {
            return curve->is_closed();
        }

        void setClosed(bool closed) {
            curve->set_closed(closed);
        }

        int getPointCount() {
            return curve->get_point_count();
        }

        void setPointCount(int count) {
            curve->set_point_count(count);
        }

        bool getUpVectorEnabled() {
            return curve->is_up_vector_enabled();
        }

        void setUpVectorEnabled(bool enable) {
            curve->set_up_vector_enabled(enable);
        }

        void addPoint(Vector3 pos, Vector3 in = Vector3(), Vector3 out = Vector3(), int index = -1) {
            curve->add_point(pos, in, out, index);
        }

        void clearPoints() {
            curve->clear_points();
        }

        float getBakedLength() {
            return curve->get_baked_length();
        }

        std::vector<Vector3> getBakedPoints() {
            PackedVector3Array arr = curve->get_baked_points();
            std::vector<Vector3> points;
            for (int i = 0; i < arr.size(); i++) {
                points.push_back(arr[i]);
            }
            return points;
        }

        std::vector<float> getBakedTilts() {
            PackedFloat32Array arr = curve->get_baked_tilts();
            std::vector<float> tilts;
            for (int i = 0; i < arr.size(); i++) {
                tilts.push_back(arr[i]);
            }
            return tilts;
        }

        std::vector<Vector3> getBakedUpVectors() {
            PackedVector3Array arr = curve->get_baked_up_vectors();
            std::vector<Vector3> upVectors;
            for (int i = 0; i < arr.size(); i++) {
                upVectors.push_back(arr[i]);
            }
            return upVectors;
        }

        float getClosestOffset(Vector3 point) {
            return curve->get_closest_offset(point);
        }

        Vector3 getClosestPoint(Vector3 point) {
            return curve->get_closest_point(point);
        }

        Vector3 getPointIn(int index) {
            return curve->get_point_in(index);
        }

        Vector3 getPointOut(int index) {
            return curve->get_point_out(index);
        }

        Vector3 getPointPosition(int index) {
            return curve->get_point_position(index);
        }

        float getPointTilt(int index) {
            return curve->get_point_tilt(index);
        }

        void removePoint(int index) {
            curve->remove_point(index);
        }

        Vector3 sample(int idx, float t) {
            return curve->sample(idx, t);
        }

        Vector3 sampleBaked(float offset = 0.0f, bool cubic = false) {
            return curve->sample_baked(offset, cubic);
        }

        Vector3 sampleBakedUpVector(float offset, bool applyTilt = false) {
            return curve->sample_baked_up_vector(offset, applyTilt);
        }

        Transform3D sampleBakedWithRotation(float offset = 0.0f, bool cubic = false, bool applyTilt = false) {
            return curve->sample_baked_with_rotation(offset, cubic, applyTilt);
        }

        Vector3 samplef(float fofs) {
            return curve->samplef(fofs);
        }

        void setPointIn(int index, Vector3 in) {
            curve->set_point_in(index, in);
        }

        void setPointOut(int index, Vector3 out) {
            curve->set_point_out(index, out);
        }

        void setPointPosition(int index, Vector3 pos) {
            curve->set_point_position(index, pos);
        }

        void setPointTilt(int index, float tilt) {
            curve->set_point_tilt(index, tilt);
        }

        std::vector<Vector3> tessellate(int maxStages = 5, float toleranceDegrees = 4) {
            PackedVector3Array arr = curve->tessellate(maxStages, toleranceDegrees);
            std::vector<Vector3> points;
            for (int i = 0; i < arr.size(); i++) {
                points.push_back(arr[i]);
            }
            return points;
        }

        std::vector<Vector3> tessellateEvenLength(int maxStages = 5, float toleranceLength = 0.2) {
            PackedVector3Array arr = curve->tessellate_even_length(maxStages, toleranceLength);
            std::vector<Vector3> points;
            for (int i = 0; i < arr.size(); i++) {
                points.push_back(arr[i]);
            }
            return points;
        }
    };
}

#endif // CURVE3D_H