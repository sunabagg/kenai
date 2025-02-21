function printAllGlobals()
    local seen={}
    local function dump(t,i)
        if t == nil then
            --print("t is nil)
            return
        end
        seen[t]=true
        local s={}
        local n=0
        for k, v in pairs(t) do
            n=n+1
            if s[n] == nil then
                s[n] = ""
            end
            s[n]=tostring(k)
        end
        table.sort(s)
        for k,v in ipairs(s) do
            print(i .. v)
            v=t[v]
            if type(v)=="table" and not seen[v] then
                dump(v,i.."\t")
            elseif type(v)=="userdata" and not seen[v] then
                dump(getmetatable(v),i.."\t")
            end
        end
    end

    dump(_G,"")
end

if _G == nil then
    print("Global table is nil")
else
    print("Global table is not nil")
end

printAllGlobals()

print("Hello, World!")
local vec = Vector3.new(1, 2, 3)
vec.x = 1
vec.y = 2
vec.z = 3
print(vec.x)
print(vec.y)
print(vec.z)

function printEntity(entity, indent)
    print(indent .. "Entity: " .. entity.name)
    local spatialTransform = SpatialTransform.getFromEntity(entity)
    if spatialTransform then
        local position = spatialTransform.position
        local rotation = spatialTransform.rotation
        local scale = spatialTransform.scale
        local global = spatialTransform.global
        --print(position == nil)

        print(indent .. "    Transform: " .. position:tostring() .. ", " .. rotation:tostring() .. ", " .. scale:tostring())
        print(indent .. "    Global Transform: " .. global:tostring())
    end
    for i = 0, entity:getChildCount() do
        local child = entity:getChild(i)
        printEntity(child, indent .. "    ")
    end
end

function printScene(_scene)
    print("Scene")
    for i = 0, _scene:getEntityCount() do
        local entity = _scene:getEntity(i)
        printEntity(entity, "    ")
    end
end

local scene = createScene()
local entity1 = Entity.new()
entity1.name = "Entity1"
local e1transform = SpatialTransform.new()
entity1:addComponent(e1transform, "SpatialTransform")
scene:addEntity(entity1)
e1transform.position = Vector3.new(1, 2, 3)
local child1 = Entity.new()
child1.name = "Child1"
local c1transform = SpatialTransform.new()
child1:addComponent(c1transform, "SpatialTransform")
entity1:addChild(child1)
c1transform.position = Vector3.new(4, 5, 6)
local entity2 = Entity.new()
entity2.name = "Entity2"
local e2transform = SpatialTransform.new()
entity2:addComponent(e2transform, "SpatialTransform")
scene:addEntity(entity2)
e2transform.position = Vector3.new(7, 8, 9)
local entity3 = Entity.new()
entity3.name = "Entity3"
local e3transform = SpatialTransform.new()
entity3:addComponent(e3transform, "SpatialTransform")
local e3camera = Camera.new()
entity3:addComponent(e3camera, "Camera")
scene:addEntity(entity3)
e3transform.position = Vector3.new(0, 0, 1)    
local entity4 = Entity.new()
entity4.name = "Entity4"
local e4transform = SpatialTransform.new()
entity4:addComponent(e4transform, "SpatialTransform")
local e4mesh = MeshRenderer.new()
entity4:addComponent(e4mesh, "MeshRenderer")
local e4capsule = Capsule.new()
entity4:addComponent(e4capsule, "Capsule")
--local e4sphere = Sphere.new()
--entity4:addComponent(e4sphere, "Sphere")
--local e4box = Box.new()
--entity4:addComponent(e4box, "Box")
--e4box.size = Vector3.new(1, 1, 1)
scene:addEntity(entity4)
e4transform.position = Vector3.new(0, 0, -1)

--child1:free()
--child1 = nil

printScene(scene)

local hello = ioManager:loadText("app://hello.txt")
print(hello)