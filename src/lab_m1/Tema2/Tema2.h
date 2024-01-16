// Copyright Theodor-Ioan Rolea 333CA 2023
#pragma once

#include "components/simple_scene.h"
#include "lab_m1/Tema2/lab_camera.h"
#include "components/transform.h"


namespace m1
{
    class Tema2 : public gfxc::SimpleScene
    {
    public:
        Tema2();
        ~Tema2();

        void Init() override;

    private:
        struct Building
        {
            glm::vec3 position;
            glm::vec3 scale;
            Building(const glm::vec3& pos, const glm::vec3& scl) : position(pos), scale(scl) {}
            // Default constructor
            Building() : position(glm::vec3(0.0f)), scale(glm::vec3(0.0f)) {}
        };

        struct Projectile
        {
            glm::vec3 position;
            float rotation;
            float barrelRotation;
            float time;
            glm::vec3 speed;
            bool active;
            bool playerProjectile;

            Projectile(const glm::vec3& pos, float rot, float barrelRot) : position(pos), rotation(rot), barrelRotation(barrelRot), time(0.0f), speed(glm::vec3(25.0f)), active(true), playerProjectile(false) {}
            // Default constructor
            Projectile() : position(glm::vec3(0.0f)), rotation(0.0f), barrelRotation(0.0f), time(0.0f), speed(glm::vec3(25.0f)), active(true), playerProjectile(false) {}
        };

        struct Tank
        {
            glm::vec3 position;
            float rotation;
            float turretRotation;
            float barrelRotation;
            int health;
            bool hit;
            float timer;
            bool active;
            int facingDirection;
            float hitTimer;
            int id;

            Tank(const glm::vec3& pos, float rot, float turretRot, int i) : position(pos), rotation(rot), active(true), health(4), turretRotation(turretRot), hit(false), timer(0.0f), facingDirection(0), barrelRotation(0.0f), id(i), hitTimer(0.0f) {}
            // Default constructor
            Tank() : position(glm::vec3(0.0f)), rotation(0.0f), active(true), health(4), turretRotation(0.0f), hit(false), timer(0.0f), facingDirection(0), barrelRotation(0.0f), id(0), hitTimer(0.0f) {}
        };

        void FrameStart() override;
        void Update(float deltaTimeSeconds) override;
        void RandomPrint();
        void TankMovement(float deltaTimeseconds, Tank& tank);
        int GetNextMovementState(const int currentState);
        void SpawnTanks();
        bool CheckBuildingCollision(Tank& tank, std::vector<Building> buildings);
        bool CheckTankCollision(float translateX, float translateZ, Tank& tank);
        void TankShoot(Tank& tank, float deltaTimeSeconds);
        void SpawnProjectile(float translateX, float barrelRotation, float translateZ, float rotation);
        void SpawnBuildings();
        float RandomXCoordinate();
        float RandomZCoordinate();
        void FrameEnd() override;

        void RenderMesh(Mesh* mesh, Shader* shader, const glm::mat4& modelMatrix) override;
        void RenderSimpleMesh(Mesh* mesh, Shader* shader, const glm::mat4& modelMatrix, const glm::vec3& color, const int health);

        void OnInputUpdate(float deltaTime, int mods) override;
        void OnKeyPress(int key, int mods) override;
        void OnKeyRelease(int key, int mods) override;
        void OnMouseMove(int mouseX, int mouseY, int deltaX, int deltaY) override;
        void OnMouseBtnPress(int mouseX, int mouseY, int button, int mods) override;
        void OnMouseBtnRelease(int mouseX, int mouseY, int button, int mods) override;
        void OnMouseScroll(int mouseX, int mouseY, int offsetX, int offsetY) override;
        void OnWindowResize(int width, int height) override;

        std::vector<Building> buildings;
        std::vector<Tank> tanks;

    protected:
        implemented::Camera* camera;
        glm::mat4 projectionMatrix;
        bool renderCameraTarget;

        // TODO(student): If you need any other class variables, define them here.

        float fov;
        float left, right;
        float bottom, top;
        float z_near = 0.01;
        float z_far = 200;
        char projectionType = 'P';

        std::vector<Projectile> projectiles;
        int score = 0;
        float gameCounter = 0.0f;
        float translateX = 0, translateY = 0, translateZ = 0;
        float previousTranslateX = 0, previousTranslateY = 0, previousTranslateZ = 0;
        float cameraPreviousTranslateX = 0, cameraPreviousTranslateY = 1.65f, cameraPreviousTranslateZ = 0;
        float gravity = 9.8f;
        float rotation = 0;
        float areaSize = 30;
        int lastKeyPressed = 0;
        int health = 4;
        bool game = true;
        bool tanksHit = false;
        float turretRotation = 0;
        float barrelRotation = 0;
        float shootTimer = 0;
        float moveSpeed = 5;
        float rotateSpeed = 2;
        float newCamera = 0;
    };
}   // namespace m1