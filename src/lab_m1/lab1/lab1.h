#pragma once

#include "components/simple_scene.h"



namespace m1
{
    class Lab1 : public gfxc::SimpleScene
    {
     public:
        Lab1();
        ~Lab1();

        void Init() override;

     private:
         int red = 0;
         int green = 0;
         int blue = 0;
         int cycle = 0;
         char name[10] = "box";
         float x = 1;
         float y = 0.5;
         float z = 0;
         glm::vec3 initialPosition = glm::vec3(x, y, z);
         bool isJumping = false;
         bool isFalling = false;
         float jumpSpeed = 0.05;
         float timer = 0;
        void FrameStart() override;
        void Update(float deltaTimeSeconds) override;
        void FrameEnd() override;

        void OnInputUpdate(float deltaTime, int mods) override;
        void OnKeyPress(int key, int mods) override;
        void OnKeyRelease(int key, int mods) override;
        void OnMouseMove(int mouseX, int mouseY, int deltaX, int deltaY) override;
        void OnMouseBtnPress(int mouseX, int mouseY, int button, int mods) override;
        void OnMouseBtnRelease(int mouseX, int mouseY, int button, int mods) override;
        void OnMouseScroll(int mouseX, int mouseY, int offsetX, int offsetY) override;
        void OnWindowResize(int width, int height) override;

        // TODO(student): Class variables go here

    };
}   // namespace m1
