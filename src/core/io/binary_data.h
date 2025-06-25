#ifndef BINARY_DATA_H
#define BINARY_DATA_H

#include "byte.h"

#include <godot_cpp/variant/packed_byte_array.hpp>
#include <godot_cpp/variant/utility_functions.hpp>
#include <vector>

using namespace godot;

namespace lucidfx::core::io {
    void bindBinaryData(sol::state& lua);

    class BinaryData {
    private:
        std::vector<Byte*> data;

    public:
        BinaryData() = default;

        BinaryData(const std::vector<Byte*>& data) : data(data) {}

        BinaryData(const std::vector<uint8_t>& data) {
            for (const auto& byte : data) {
                this->data.emplace_back(new Byte(byte));
            }
        }

        BinaryData(const PackedByteArray& packed_data) {
            for (int i = 0; i < packed_data.size(); ++i) {
                this->data.emplace_back(new Byte(packed_data[i]));
            }
        }

        BinaryData(const sol::table & table) {
            for (const auto& byte : table) {
                if (!byte.first.is<int>()) {
                    UtilityFunctions::printerr("Invalid index in table");
                }
                int index = byte.first.as<int>();
                if (index < 0) {
                    UtilityFunctions::printerr("Index out of range");
                }
                if (byte.second.is<Byte>()) {
                    this->data[index] = byte.second.as<Byte*>();
                } else if (byte.second.is<double>()) {
                    this->data[index] = new Byte(byte.second.as<double>());
                } else if (byte.second.is<float>()) {
                    this->data[index] = new Byte(byte.second.as<float>());
                } else if (byte.second.is<int>()) {
                    this->data[index] = new Byte(byte.second.as<int>());
                } else if (byte.second.is<uint8_t>()) {
                    this->data[index] = new Byte(byte.second.as<uint8_t>());
                } else {
                    UtilityFunctions::printerr("Invalid type in table");
                }
            }
        }

        size_t size() const {
            return data.size();
        }

        Byte* get(int index) const {
            if (index < 0 || index >= static_cast<int>(data.size())) {
                UtilityFunctions::printerr("Index out of range");
            }
            return data[index];
        }

        void set(int index, Byte* byte) {
            if (index < 0 || index >= static_cast<int>(data.size())) {
                UtilityFunctions::printerr("Index out of range");
            }
            data[index] = byte;
        }

        void resize(int new_size) {
            data.resize(static_cast<size_t>(new_size));
        }

        void append(Byte* byte) {
            data.push_back(byte);
        }

        void insert(int index, Byte* byte) {
            if (index < 0 || index > static_cast<int>(data.size())) {
                UtilityFunctions::printerr("Index out of range");
            }
            data.insert(data.begin() + index, byte);
        }

        void removeAt(int index) {
            if (index < 0 || index >= static_cast<int>(data.size())) {
                UtilityFunctions::printerr("Index out of range");
            }
            data.erase(data.begin() + index);
        }

        void clear() {
            data.clear();
        }

        std::string toString() const {
            std::string result;
            for (const auto& byte : data) {
                int i = byte->getInt();
                result += std::to_string(i) + " ";
            }
            return result;
        }

        std::vector<uint8_t> toVector() const {
            std::vector<uint8_t> result;
            for (const auto& byte : data) {
                result.push_back(byte->getData());
            }
            return result;
        }

        PackedByteArray toPackedByteArray() const {
            PackedByteArray packed_data;
            for (const auto& byte : data) {
                packed_data.append(byte->getData());
            }
            return packed_data;
        }

        sol::table toTable(sol::state& lua) const {
            sol::table table = lua.create_table();
            for (size_t i = 0; i < data.size(); ++i) {
                table[i] = data[i]->getDouble();
            }
            return table;
        }
    };
}

#endif // BINARY_DATA_H