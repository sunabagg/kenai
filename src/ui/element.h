#ifndef ELEMENT_H
#define ELEMENT_H

#include <godot_cpp/classes/node.hpp>
#include <sol/sol.hpp>

#include "../core/base_object.h"

using namespace sunaba::core;
using namespace godot;

namespace sunaba::ui {
    void bindElement(sol::state &lua);
    
    class Element : public BaseObject {    
    private:
        Node* node = nullptr; // Pointer to the Node instance

        std::vector<Element*> children; // List of child elements
        Element* parent = nullptr; // Pointer to the parent element
    protected:
        // Protected constructor to prevent direct instantiation
        Element(Node* p_node) : node(p_node) {
            onInit();
        }

        void setParent(Element* p_parent) {
            parent = p_parent;
            if (node != nullptr && p_parent != nullptr && p_parent->getNode() != nullptr) {
                // Add this node as a child of the parent node
                node->add_child(p_parent->getNode());
            }
        }
    public:
        Element* findE(PackedStringArray & p_array, int p_index) {
            if (p_index >= 0 && p_index < p_array.size()) {
                String name = p_array[p_index];
                for (Element* child : children) {
                    if (child != nullptr) {
                        if (child->getName().c_str() == name) {
                            return child;
                        } else {
                            Element* found = child->findE(p_array, p_index + 1);
                            if (found != nullptr) {
                                return found;
                            }
                        }
                    }
                    
                }
            }
            return nullptr;
        }
        
        Element* find(const std::string& name) {
            String name_str = String(name.c_str());
            PackedStringArray name_array = name_str.split("/");
            return findE(name_array, 0);
        }

        template<typename T>
        T* findT(const std::string& name) {
            Element* found = find(name);
            if (found != nullptr) {
                return static_cast<T*>(found);
            }
            return nullptr;
        }

        Element() {
            node = new Node();
            node->set_name("Element");
            onInit();
        }

        Element* getParent() {
            return parent;
        }

        void addChild(Element* child) {
            if (child != nullptr) {
                children.push_back(child);
                child->setParent(this);
            }
        }

        void addSibling(Element* sibling) {
            if (sibling != nullptr && parent != nullptr) {
                parent->addChild(sibling);
            }
        }

        void removeChild(Element* child) {
            auto it = std::find(children.begin(), children.end(), child);
            if (it != children.end()) {
                children.erase(it);
                child->setParent(nullptr);
            }
        }

        std::vector<Element*> getChildren() {
            std::vector<Element*> result;
            for (Element* child : children) {
                if (child != nullptr) {
                    result.push_back(child);
                }
            }
            return result;
        }

        virtual void onInit() {
            // Initialization logic for the element
        }

        void setNode(Node* p_node) {
            node = p_node;
        }

        Node* getNode() {
            return node;
        }

        std::string getName() {
            return String(node->get_name()).utf8().get_data();
        }

        void setName(const std::string& name) {
            node->set_name(name.c_str());
        }

        void onFree() override {
            // Freeing logic for the element
            if (node != nullptr) {
                node->queue_free();
                node = nullptr;
            }
            if (parent != nullptr) {
                parent->removeChild(this);
                parent = nullptr;
            }
            for (Element* child : children) {
                if (child != nullptr) {
                    child->onFree();
                }
            }
            children.clear();
        }
    };
}

#endif // WIDGET_H