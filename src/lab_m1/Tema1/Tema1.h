#pragma once

#include "components/simple_scene.h"


namespace m1
{
    class Tema1 : public gfxc::SimpleScene
    {
    public:
        Tema1();
        ~Tema1();

        void Init() override;

    private:
        void FrameStart() override;
        void Update(float deltaTimeSeconds) override;
        void SpawnPinkStars(float deltaTimeSeconds);
        void SpawnPinkStar(const glm::vec3& position);
        float RandomXCoordinate();
        float RandomYCoordinate();
        void SpawnGrayStar();
        void SpawnStar(const glm::vec3 color, const glm::vec3 pos, const int type);
        std::string FindSquare(int mouseX, int mouseY);
        void FrameEnd() override;

        void OnInputUpdate(float deltaTime, int mods) override;
        void OnKeyPress(int key, int mods) override;
        void OnKeyRelease(int key, int mods) override;
        void OnMouseMove(int mouseX, int mouseY, int deltaX, int deltaY) override;
        void OnMouseBtnPress(int mouseX, int mouseY, int button, int mods) override;
        bool CheckStarIntersection(int mouseX, int mouseY, const glm::vec3& objPosition);
        bool CheckSquareIntersection(int mouseX, int mouseY, const glm::vec3& objPosition);
        bool CheckDiamondIntersection(int mouseX, int mouseY, const glm::vec3& objPosition);
        void OnMouseBtnRelease(int mouseX, int mouseY, int button, int mods) override;
        void OnMouseScroll(int mouseX, int mouseY, int offsetX, int offsetY) override;
        void OnWindowResize(int width, int height) override;

        struct Star
        {
            glm::vec3 position;
            std::string name;
            bool isVisible;
            float angularStep;
            float radius;
            int type;
            Star(const glm::vec3& pos, const std::string na, const int type) : position(pos), name(na), isVisible(true), angularStep(0.0f), radius(1.4f), type(type) {}
        };

        struct Diamond
        {
            std::string name;
            glm::vec3 position;
            glm::vec3 color;
            int line;
            int type;
            mutable float timer;
            mutable bool isVisible;
            mutable float dying;
            mutable float scaleX;
            mutable float scaleY;
            float radius;

            Diamond(const std::string na, const glm::vec3& pos, const glm::vec3 col, const int line, const int type) : name(na), position(pos), color(col), isVisible(true), line(line), type(type), timer(1.0f), radius(1.0f), dying(0.0f), scaleX(50.0f), scaleY(50.0f) {}

            // Default constructor
            Diamond() : name(""), position(glm::vec3(0.0f)), color(glm::vec3(1.0f)), isVisible(true), line(0), type(0), timer(1.0f), radius(1.0f), dying(0.0f), scaleX(50.0f), scaleY(50.0f) {}
        };

        struct Hexagon
        {
            std::string name;
            glm::vec3 position;
            float scaleX, scaleY;
            int line;
            int type;
            bool isVisible;
            float radius;
            mutable int lives;
            float dying;
            int id;

            Hexagon(const std::string na, const glm::vec3& pos, const int line, const int type, const int id) : name(na), position(pos), isVisible(true), scaleX(50.0f), scaleY(50.0f), line(line), type(type), radius(1.0f), lives(3), dying(0.0f), id(id) {}

            // Default constructor
            Hexagon() : name(""), position(glm::vec3(0.0f)), isVisible(true), scaleX(50.0f), scaleY(50.0f), line(0), type(0), radius(1.0f), lives(3), dying(0.0f), id(0) {}
        };

    protected:
        float cx, cy, cx2, cy2;
        glm::ivec2 resolution = window->GetResolution();
        glm::mat3 modelMatrix;
        float translateX, translateY, tx = 0, ty = 0, maxX = 0, translateX2, translateY2;
        float scaleHexX = 50, scaleHexY = 50;
        float angularStep1, angularStep2, angularStep, angularStep3;
        int ok1 = 0, ok2 = 0, ok3 = 0, ok4 = 0;
        float elapsedTime = 0.0f, elapsedTimeHex = 0.0f;
        std::vector<Star> stars;
        std::vector<Star> grayStars;
        glm::vec3 nextGrayStarPosition = glm::vec3(850, 575, 0);
        bool isDiamondDragged = false;
        Diamond draggedDiamond;
        std::unordered_map<std::string, glm::vec3> squares;
        std::vector<Diamond> diamonds;
        std::vector<Hexagon> hexagons;
        std::vector<Diamond> gridDiamonds;
        std::vector<Star> diamondStars;
        std::vector<Star> lives;
        int randomSpawnTime = rand() % 3 + 2;
        float spawnInterval = rand() % 3 + 2;
        int livesLeft = 3;
        int diamondCount = 0;
        int starCount = 0;
        int maxPoints = 10;
        int hexCount = 0;
        float border = 40.0f;
    };
}   // namespace m1
