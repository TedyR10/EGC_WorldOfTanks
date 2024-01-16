#include "lab_m1/Tema1/Tema1.h"

#include <vector>
#include <iostream>
#include <cstdlib>
#include <ctime>

#include "lab_m1/Tema1/object2D.h"
#include "lab_m1/Tema1/transform2D.h"

using namespace std;
using namespace m1;


/*
 *  To find out more about `FrameStart`, `Update`, `FrameEnd`
 *  and the order in which they are called, see `world.cpp`.
 */


Tema1::Tema1()
{
}


Tema1::~Tema1()
{
}


void Tema1::Init()
{
    glm::ivec2 resolution = window->GetResolution();
    auto camera = GetSceneCamera();
    camera->SetOrthographic(0, (float)resolution.x, 0, (float)resolution.y, 0.01f, 400);
    camera->SetPosition(glm::vec3(0, 0, 50));
    camera->SetRotation(glm::vec3(0, 0, 0));
    camera->Update();
    GetCameraInput()->SetActive(false);

    glm::vec3 corner = glm::vec3(0, 0, 0);
    float squareSide = 100;

    srand(static_cast<unsigned>(time(nullptr)));

    Mesh* square1 = object2D::CreateSquare("square1", corner, squareSide, glm::vec3(1, 0, 0), true);
    AddMeshToList(square1);

    Mesh* square2 = object2D::CreateSquare("square2", corner, squareSide, glm::vec3(0, 1, 0), true);
    AddMeshToList(square2);

    Mesh* square3 = object2D::CreateSquare("square3", corner, squareSide, glm::vec3(0, 1, 0), true);
    AddMeshToList(square3);

    Mesh* square4 = object2D::CreateSquare("square4", corner, squareSide, glm::vec3(0, 1, 0), true);
    AddMeshToList(square4);

    Mesh* square5 = object2D::CreateSquare("square5", corner, squareSide, glm::vec3(0, 1, 0), true);
    AddMeshToList(square5);

    Mesh* square6 = object2D::CreateSquare("square6", corner, squareSide, glm::vec3(0, 1, 0), true);
    AddMeshToList(square6);

    Mesh* square7 = object2D::CreateSquare("square7", corner, squareSide, glm::vec3(0, 1, 0), true);
    AddMeshToList(square7);

    Mesh* square8 = object2D::CreateSquare("square8", corner, squareSide, glm::vec3(0, 1, 0), true);
    AddMeshToList(square8);

    Mesh* square9 = object2D::CreateSquare("square9", corner, squareSide, glm::vec3(0, 1, 0), true);
    AddMeshToList(square9);

    Mesh* square10 = object2D::CreateSquare("square10", corner, squareSide, glm::vec3(0, 1, 0), true);
    AddMeshToList(square10);

    Mesh* grid1 = object2D::CreateSquare("grid1", corner, squareSide, glm::vec3(0, 0, 0));
    AddMeshToList(grid1);

    Mesh* grid2 = object2D::CreateSquare("grid2", corner, squareSide, glm::vec3(0, 0, 0));
    AddMeshToList(grid2);

    Mesh* grid3 = object2D::CreateSquare("grid3", corner, squareSide, glm::vec3(0, 0, 0));
    AddMeshToList(grid3);

    Mesh* grid4 = object2D::CreateSquare("grid4", corner, squareSide, glm::vec3(0, 0, 0));
    AddMeshToList(grid4);

    Mesh* life1 = object2D::CreateSquare("life1", corner, squareSide, glm::vec3(1, 0, 0), true);
    AddMeshToList(life1);

    Mesh* life2 = object2D::CreateSquare("life2", corner, squareSide, glm::vec3(1, 0, 0), true);
    AddMeshToList(life2);

    Mesh* life3 = object2D::CreateSquare("life3", corner, squareSide, glm::vec3(1, 0, 0), true);
    AddMeshToList(life3);

    Mesh* star1 = object2D::CreateStar("star1", glm::vec3(0.5, 0.5, 0.5), true);
    AddMeshToList(star1);

    Mesh* star2 = object2D::CreateStar("star2", glm::vec3(1, 0.5, 0), true);
    AddMeshToList(star2);

    Mesh* star3 = object2D::CreateStar("star3", glm::vec3(0, 0, 1), true);
    AddMeshToList(star3);

    Mesh* star4 = object2D::CreateStar("star4", glm::vec3(1, 1, 0.5), true);
    AddMeshToList(star4);

    Mesh* star5 = object2D::CreateStar("star5", glm::vec3(0.5, 0, 1), true);
    AddMeshToList(star5);

    Mesh* diamond1 = object2D::CreateDiamond("diamond1", glm::vec3(1, 0.5, 0), true);
    AddMeshToList(diamond1);

    Mesh* diamond2 = object2D::CreateDiamond("diamond2", glm::vec3(0, 0, 1), true);
    AddMeshToList(diamond2);

    Mesh* diamond3 = object2D::CreateDiamond("diamond3", glm::vec3(1, 1, 0), true);
    AddMeshToList(diamond3);

    Mesh* diamond4 = object2D::CreateDiamond("diamond4", glm::vec3(0.5, 0, 1), true);
    AddMeshToList(diamond4);

    Mesh* hex1 = object2D::CreateHex("hex1", glm::vec3(0.5, 0, 1), glm::vec3(0, 0.75, 0), true);
    AddMeshToList(hex1);

    Mesh* hex2 = object2D::CreateHex("hex2", glm::vec3(1, 1, 0), glm::vec3(0, 0.75, 0), true);
    AddMeshToList(hex2);

    Mesh* hex3 = object2D::CreateHex("hex3", glm::vec3(0, 0, 1), glm::vec3(0, 0.75, 0), true);
    AddMeshToList(hex3);

    Mesh* hex4 = object2D::CreateHex("hex4", glm::vec3(1, 0.5, 0), glm::vec3(0, 0.75, 0), true);
    AddMeshToList(hex4);

    Mesh* star6 = object2D::CreateStar("star6", glm::vec3(1, 0, 1), true);
    AddMeshToList(star6);

    // Player lives
    lives.emplace_back(glm::vec3(850, 600, 0), "", 0);
    lives.emplace_back(glm::vec3(975, 600, 0), "", 0);
    lives.emplace_back(glm::vec3(1095, 600, 0), "", 0);

}


void Tema1::FrameStart()
{
    // Clears the color buffer (using the previously set color) and depth buffer
    glClearColor(0.15, 0.15, 0.15, 1);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glm::ivec2 resolution = window->GetResolution();
    // Sets the screen area where to draw
    glViewport(0, 0, resolution.x, resolution.y);
}


void Tema1::Update(float deltaTimeSeconds)
{
    // Player grid

    // Back area
    modelMatrix = glm::mat3(1);
    modelMatrix = transform2D::Translate(10, 20);
    modelMatrix *= transform2D::Scale(0.5f, 4.65f);
    RenderMesh2D(meshes["square1"], shaders["VertexColor"], modelMatrix);
    
    // First column
    modelMatrix = glm::mat3(1);
    modelMatrix = transform2D::Translate(80, 20);
    modelMatrix *= transform2D::Scale(1.25f, 1.25f);
    RenderMesh2D(meshes["square2"], shaders["VertexColor"], modelMatrix);
    squares["square2"] = glm::vec3(80, 20, 0);  // Update the square position

    modelMatrix = glm::mat3(1);
    modelMatrix = transform2D::Translate(80, 190);
    modelMatrix *= transform2D::Scale(1.25f, 1.25f);
    RenderMesh2D(meshes["square3"], shaders["VertexColor"], modelMatrix);
    squares["square3"] = glm::vec3(80, 190, 0);  // Update the square position

    modelMatrix = glm::mat3(1);
    modelMatrix = transform2D::Translate(80, 360);
    modelMatrix *= transform2D::Scale(1.25f, 1.25f);
    RenderMesh2D(meshes["square4"], shaders["VertexColor"], modelMatrix);
    squares["square4"] = glm::vec3(80, 360, 0);  // Update the square position

    // Second column
    modelMatrix = glm::mat3(1);
    modelMatrix = transform2D::Translate(250, 20);
    modelMatrix *= transform2D::Scale(1.25f, 1.25f);
    RenderMesh2D(meshes["square5"], shaders["VertexColor"], modelMatrix);
    squares["square5"] = glm::vec3(250, 20, 0);  // Update the square position

    modelMatrix = glm::mat3(1);
    modelMatrix = transform2D::Translate(250, 190);
    modelMatrix *= transform2D::Scale(1.25f, 1.25f);
    RenderMesh2D(meshes["square6"], shaders["VertexColor"], modelMatrix);
    squares["square6"] = glm::vec3(250, 190, 0);  // Update the square position

    modelMatrix = glm::mat3(1);
    modelMatrix = transform2D::Translate(250, 360);
    modelMatrix *= transform2D::Scale(1.25f, 1.25f);
    RenderMesh2D(meshes["square7"], shaders["VertexColor"], modelMatrix);
    squares["square7"] = glm::vec3(250, 360, 0);  // Update the square position

    // Third column
    modelMatrix = glm::mat3(1);
    modelMatrix = transform2D::Translate(420, 20);
    modelMatrix *= transform2D::Scale(1.25f, 1.25f);
    RenderMesh2D(meshes["square8"], shaders["VertexColor"], modelMatrix);
    squares["square8"] = glm::vec3(420, 20, 0);  // Update the square position

    modelMatrix = glm::mat3(1);
    modelMatrix = transform2D::Translate(420, 190);
    modelMatrix *= transform2D::Scale(1.25f, 1.25f);
    RenderMesh2D(meshes["square9"], shaders["VertexColor"], modelMatrix);
    squares["square9"] = glm::vec3(420, 190, 0);  // Update the square position

    modelMatrix = glm::mat3(1);
    modelMatrix = transform2D::Translate(420, 360);
    modelMatrix *= transform2D::Scale(1.25f, 1.25f);
    RenderMesh2D(meshes["square10"], shaders["VertexColor"], modelMatrix);
    squares["square10"] = glm::vec3(420, 360, 0);  // Update the square position


    // Grid for diamonds
    modelMatrix = glm::mat3(1);
    modelMatrix = transform2D::Translate(50, 575);
    modelMatrix *= transform2D::Scale(1.25f, 1.25f);
    RenderMesh2D(meshes["grid1"], shaders["VertexColor"], modelMatrix);

    modelMatrix = glm::mat3(1);
    modelMatrix = transform2D::Translate(250, 575);
    modelMatrix *= transform2D::Scale(1.25f, 1.25f);
    RenderMesh2D(meshes["grid2"], shaders["VertexColor"], modelMatrix);

    modelMatrix = glm::mat3(1);
    modelMatrix = transform2D::Translate(450, 575);
    modelMatrix *= transform2D::Scale(1.25f, 1.25f);
    RenderMesh2D(meshes["grid3"], shaders["VertexColor"], modelMatrix);

    modelMatrix = glm::mat3(1);
    modelMatrix = transform2D::Translate(650, 575);
    modelMatrix *= transform2D::Scale(1.25f, 1.25f);
    RenderMesh2D(meshes["grid4"], shaders["VertexColor"], modelMatrix);

    // Diamond costs
    modelMatrix = glm::mat3(1);
    modelMatrix = transform2D::Translate(60, 550);
    modelMatrix *= transform2D::Scale(15, 15);
    RenderMesh2D(meshes["star1"], shaders["VertexColor"], modelMatrix);

    modelMatrix = glm::mat3(1);
    modelMatrix = transform2D::Translate(260, 550);
    modelMatrix *= transform2D::Scale(15, 15);
    RenderMesh2D(meshes["star1"], shaders["VertexColor"], modelMatrix);

    modelMatrix = glm::mat3(1);
    modelMatrix = transform2D::Translate(310, 550);
    modelMatrix *= transform2D::Scale(15, 15);
    RenderMesh2D(meshes["star1"], shaders["VertexColor"], modelMatrix);

    modelMatrix = glm::mat3(1);
    modelMatrix = transform2D::Translate(460, 550);
    modelMatrix *= transform2D::Scale(15, 15);
    RenderMesh2D(meshes["star1"], shaders["VertexColor"], modelMatrix);

    modelMatrix = glm::mat3(1);
    modelMatrix = transform2D::Translate(510, 550);
    modelMatrix *= transform2D::Scale(15, 15);
    RenderMesh2D(meshes["star1"], shaders["VertexColor"], modelMatrix);

    modelMatrix = glm::mat3(1);
    modelMatrix = transform2D::Translate(660, 550);
    modelMatrix *= transform2D::Scale(15, 15);
    RenderMesh2D(meshes["star1"], shaders["VertexColor"], modelMatrix);

    modelMatrix = glm::mat3(1);
    modelMatrix = transform2D::Translate(710, 550);
    modelMatrix *= transform2D::Scale(15, 15);
    RenderMesh2D(meshes["star1"], shaders["VertexColor"], modelMatrix);

    modelMatrix = glm::mat3(1);
    modelMatrix = transform2D::Translate(760, 550);
    modelMatrix *= transform2D::Scale(15, 15);
    RenderMesh2D(meshes["star1"], shaders["VertexColor"], modelMatrix);

    // Render diamond1
    modelMatrix = glm::mat3(1);
    modelMatrix = transform2D::Translate(105, 635);
    modelMatrix *= transform2D::Scale(50, 50);
    RenderMesh2D(meshes["diamond1"], shaders["VertexColor"], modelMatrix);
    diamonds.emplace_back("diamond1", glm::vec3(105, 635, 0), glm::vec3(1, 0.5, 0), 0, 1);

    // Render diamond2
    modelMatrix = glm::mat3(1);
    modelMatrix = transform2D::Translate(305, 635);
    modelMatrix *= transform2D::Scale(50, 50);
    RenderMesh2D(meshes["diamond2"], shaders["VertexColor"], modelMatrix);
    diamonds.emplace_back("diamond2", glm::vec3(305, 635, 0), glm::vec3(0, 0, 1), 0, 2);

    // Render diamond3
    modelMatrix = glm::mat3(1);
    modelMatrix = transform2D::Translate(505, 635);
    modelMatrix *= transform2D::Scale(50, 50);
    RenderMesh2D(meshes["diamond3"], shaders["VertexColor"], modelMatrix);
    diamonds.emplace_back("diamond3", glm::vec3(505, 635, 0), glm::vec3(1, 1, 0), 0, 3);

    // Render diamond4
    modelMatrix = glm::mat3(1);
    modelMatrix = transform2D::Translate(705, 635);
    modelMatrix *= transform2D::Scale(50, 50);
    RenderMesh2D(meshes["diamond4"], shaders["VertexColor"], modelMatrix);
    diamonds.emplace_back("diamond4", glm::vec3(705, 635, 0), glm::vec3(0.5, 0, 1), 0, 4);

    elapsedTime += deltaTimeSeconds;

    // Spawn pink stars at random intervals
    SpawnPinkStars(deltaTimeSeconds);

    if (maxPoints <= 0 && grayStars.empty()) {
        maxPoints = 10;
    }

    for (const auto& star : stars)
    {
        if (star.isVisible)
        {
            glm::mat3 modelMatrix = glm::mat3(1);
            modelMatrix = transform2D::Translate(star.position.x, star.position.y);
            modelMatrix *= transform2D::Scale(35.0f, 35.0f);
            RenderMesh2D(meshes["pinkStar"], shaders["VertexColor"], modelMatrix);
        }
    }

    for (const auto& star : grayStars)
    {
        if (star.isVisible)
        {
            glm::mat3 modelMatrix = glm::mat3(1);
            modelMatrix = transform2D::Translate(star.position.x, star.position.y);
            modelMatrix *= transform2D::Scale(15.0f, 15.0f);
            RenderMesh2D(meshes["grayStar"], shaders["VertexColor"], modelMatrix);
        }
    }

    // Render diamonds in the grid
    for (const auto& gridDiamond : gridDiamonds)
    {
        if (gridDiamond.isVisible) {
            if (gridDiamond.scaleX <= 0.0f || gridDiamond.scaleY <= 0.0f) {
                gridDiamond.isVisible = false;
            }
            gridDiamond.scaleX -= gridDiamond.dying * deltaTimeSeconds;
            gridDiamond.scaleY -= gridDiamond.dying * deltaTimeSeconds;

            glm::mat3 modelMatrix = glm::mat3(1);
            modelMatrix = transform2D::Translate(gridDiamond.position.x, gridDiamond.position.y);
            modelMatrix *= transform2D::Scale(gridDiamond.scaleX, gridDiamond.scaleY);
            RenderMesh2D(meshes[gridDiamond.name], shaders["VertexColor"], modelMatrix);

            for (auto& hexagon : hexagons) {
                if (hexagon.line == gridDiamond.line && hexagon.type == gridDiamond.type && hexagon.isVisible && hexagon.position.x < resolution.x) {
                    gridDiamond.timer -= deltaTimeSeconds;
                    if (gridDiamond.timer <= 0) {
                        SpawnStar(gridDiamond.color, gridDiamond.position, gridDiamond.type);
                        gridDiamond.timer = 3.0f;
                        break;
                    }
                    break;
                }
                if (distance(gridDiamond.position, hexagon.position) < (gridDiamond.radius * 50.0f + hexagon.radius * 50.0f) && hexagon.isVisible) {
                    gridDiamond.dying = 100.0f;
                    break;
                }
            }            
        }
    }

    for (auto& life : lives) {
        if (life.isVisible) {
			glm::mat3 modelMatrix = glm::mat3(1);
			modelMatrix = transform2D::Translate(life.position.x, life.position.y);
			modelMatrix *= transform2D::Scale(0.85f, 0.85f);
			RenderMesh2D(meshes["life1"], shaders["VertexColor"], modelMatrix);
		}
    }

    // Dragged diamond render
    modelMatrix = glm::mat3(1);
    modelMatrix = transform2D::Translate(draggedDiamond.position.x, draggedDiamond.position.y);
    modelMatrix *= transform2D::Scale(50.0f * isDiamondDragged, 50.0f * isDiamondDragged);
    RenderMesh2D(meshes[draggedDiamond.name], shaders["VertexColor"], modelMatrix);

    if (lives.size() == 0) {
		cout << "Game over!" << endl;
		exit(0);
	} 

    // Hexagons
    elapsedTimeHex += deltaTimeSeconds;

    // Check if it's time to spawn a new hexagon
    if (elapsedTimeHex >= randomSpawnTime)
    {
        // Reset the timer
        elapsedTimeHex = 0.0f;
        randomSpawnTime = rand() % 3 + 2;

        // Generate random y-coordinate for hexagon spawn
        int randomY = rand() % 3; // 0, 1, or 2

        float hexagonY = 80.0f;
        if (randomY == 1) {
            hexagonY = 250.0f;
        }
        else if (randomY == 2) {
            hexagonY = 420.0f;
        }

        // Generate random color for hexagon
        int hexagonColor = rand() % 4; // 0, 1, 2, or 3
        int id = ++hexCount;
        if (hexagonColor == 0) {
            // Spawn hexagon
            modelMatrix = glm::mat3(1);
            modelMatrix = transform2D::Translate(1350, hexagonY);
            modelMatrix *= transform2D::Scale(50, 50) * transform2D::Rotate(15);
            RenderMesh2D(meshes["hex1"], shaders["VertexColor"], modelMatrix);
            // Add hexagon to vector for later reference
            hexagons.emplace_back("hex1", glm::vec3(1350, hexagonY, 0), randomY + 1, 4, id);
        }
        else if (hexagonColor == 1) {
			// Spawn hexagon
			modelMatrix = glm::mat3(1);
			modelMatrix = transform2D::Translate(1350, hexagonY);
			modelMatrix *= transform2D::Scale(50, 50) * transform2D::Rotate(15);
			RenderMesh2D(meshes["hex2"], shaders["VertexColor"], modelMatrix);

			// Add hexagon to vector for later reference
			hexagons.emplace_back("hex2", glm::vec3(1350, hexagonY, 0), randomY + 1, 3, id);
        }
        else if (hexagonColor == 2) {
			// Spawn hexagon
			modelMatrix = glm::mat3(1);
			modelMatrix = transform2D::Translate(1350, hexagonY);
			modelMatrix *= transform2D::Scale(50, 50) * transform2D::Rotate(15);
			RenderMesh2D(meshes["hex3"], shaders["VertexColor"], modelMatrix);

			// Add hexagon to vector for later reference
			hexagons.emplace_back("hex3", glm::vec3(1350, hexagonY, 0), randomY + 1, 2, id);
        }
        else if (hexagonColor == 3) {
			// Spawn hexagon
			modelMatrix = glm::mat3(1);
			modelMatrix = transform2D::Translate(1350, hexagonY);
			modelMatrix *= transform2D::Scale(50, 50) * transform2D::Rotate(15);
			RenderMesh2D(meshes["hex4"], shaders["VertexColor"], modelMatrix);

			// Add hexagon to vector for later reference
			hexagons.emplace_back("hex4", glm::vec3(1350, hexagonY, 0), randomY + 1, 1, id);
		}   

        
    }

    for (auto& diamondStar : diamondStars) {
        if (diamondStar.isVisible) {
            // Render the star
            diamondStar.angularStep += 7 * deltaTimeSeconds;
            diamondStar.position.x += 200 * deltaTimeSeconds;

            modelMatrix = glm::mat3(1);
            modelMatrix *= transform2D::Translate(diamondStar.position.x, diamondStar.position.y);
            modelMatrix *= transform2D::Rotate(-diamondStar.angularStep) * transform2D::Scale(35, 35);
            RenderMesh2D(meshes[diamondStar.name], shaders["VertexColor"], modelMatrix);

            for (auto& hexagon : hexagons) {
                if ((distance(diamondStar.position, hexagon.position) < (diamondStar.radius * 35.0f + hexagon.radius * 50.0f)) && diamondStar.type == hexagon.type && hexagon.isVisible) {
                    if (hexagon.lives > 1) {
                        hexagon.lives--;
                    }
                    else {
                        hexagon.dying = 100;
                    }
                    diamondStar.isVisible = false;
                }
            }
        }
    }

    // Update existing hexagons
    for (auto& hexagon : hexagons)
    {
        if (hexagon.isVisible)
        {
            if (hexagon.position.x <= border) {
                hexagon.scaleX -= 100 * deltaTimeSeconds;
                hexagon.scaleY -= 100 * deltaTimeSeconds;
                if (hexagon.scaleX <= 0.0f || hexagon.scaleY <= 0.0f) {
                    hexagon.isVisible = false;
                    lives.pop_back();
                }
                else {
                    // Render the hexagon
                    modelMatrix = glm::mat3(1);
                    modelMatrix = transform2D::Translate(hexagon.position.x, hexagon.position.y);
                    modelMatrix *= transform2D::Scale(hexagon.scaleX, hexagon.scaleY) * transform2D::Rotate(15);
                    RenderMesh2D(meshes[hexagon.name], shaders["VertexColor"], modelMatrix);
                }
            }
            else {
                if (hexagon.scaleX <= 0.0f || hexagon.scaleY <= 0.0f) {
                    hexagon.isVisible = false;
                }
                hexagon.scaleX -= hexagon.dying * deltaTimeSeconds;
                hexagon.scaleY -= hexagon.dying * deltaTimeSeconds;
                // Move hexagon to the left
                hexagon.position.x -= 35.0f * deltaTimeSeconds;

                // Render the hexagon
                modelMatrix = glm::mat3(1);
                modelMatrix = transform2D::Translate(hexagon.position.x, hexagon.position.y);
                modelMatrix *= transform2D::Scale(hexagon.scaleX, hexagon.scaleY) * transform2D::Rotate(15);
                RenderMesh2D(meshes[hexagon.name], shaders["VertexColor"], modelMatrix);
            } 
        }
    }
}

void Tema1::SpawnPinkStars(float deltaTimeSeconds)
{
    // Check if enough time has passed to spawn a new star
    if (elapsedTime >= spawnInterval && maxPoints > 0)
    {
        // Reset the timer
        elapsedTime = 0.0f;
        spawnInterval = (float) (rand() % 3 + 2.0f);
        if (maxPoints == 1) {
            SpawnPinkStar(glm::vec3(RandomXCoordinate(), RandomYCoordinate(), 0.5));
            maxPoints -= 1;
        }
        else if (maxPoints == 2) {
            SpawnPinkStar(glm::vec3(RandomXCoordinate(), RandomYCoordinate(), 0.5));
            SpawnPinkStar(glm::vec3(RandomXCoordinate(), RandomYCoordinate(), 0.5));
            maxPoints -= 2;
        }
        else {
            SpawnPinkStar(glm::vec3(RandomXCoordinate(), RandomYCoordinate(), 0.5));
            SpawnPinkStar(glm::vec3(RandomXCoordinate(), RandomYCoordinate(), 0.5));
            SpawnPinkStar(glm::vec3(RandomXCoordinate(), RandomYCoordinate(), 0.5));
            maxPoints -= 3;

        }
    }
    if (elapsedTime >= spawnInterval && maxPoints <= 0) {
        elapsedTime = 0.0f;
        spawnInterval = (float) (rand() % 3 + 2.0f);
    }
}

void Tema1::SpawnPinkStar(const glm::vec3& position)
{
    // Create a pink star mesh
    Mesh* pinkStar = object2D::CreateStar("pinkStar", glm::vec3(1, 0, 1), true);
    AddMeshToList(pinkStar);

    // Add the star to the vector
    stars.emplace_back(position, "", 0);

}

float Tema1::RandomXCoordinate()
{
    return (float) (rand() % 1200 + 10.0f);
}

float Tema1::RandomYCoordinate()
{
    return (float) (rand() % 500 + 10.0f);
}

void Tema1::SpawnGrayStar()
{
    Mesh* grayStar = object2D::CreateStar("grayStar", glm::vec3(0.5, 0.5, 0.5), true);
    AddMeshToList(grayStar);

    // Add the gray star to the vector
    grayStars.emplace_back(nextGrayStarPosition, "", 0);

    nextGrayStarPosition.x += 50;
}

void Tema1::SpawnStar(const glm::vec3 color, const glm::vec3 pos, const int type)
{
    starCount++;
    std::string name = "diamondStar" + std::to_string(starCount);
    Mesh* diamondStar = object2D::CreateStar(name, color, true);
    AddMeshToList(diamondStar);

    // Add the star to the vector
    diamondStars.emplace_back(pos, name, type);

    diamondStars.at(diamondStars.size() - 1).position.x += 40;

}


void Tema1::FrameEnd()
{
}


/*
 *  These are callback functions. To find more about callbacks and
 *  how they behave, see `input_controller.h`.
 */


void Tema1::OnInputUpdate(float deltaTime, int mods)
{
}


void Tema1::OnKeyPress(int key, int mods)
{
    // Add key press event
}


void Tema1::OnKeyRelease(int key, int mods)
{
    // Add key release event
}


void Tema1::OnMouseMove(int mouseX, int mouseY, int deltaX, int deltaY)
{
    // Add mouse move event
    if (isDiamondDragged == 1) {
        draggedDiamond.position.x = (float)mouseX;
        draggedDiamond.position.y = (float) (resolution.y - mouseY);
    }
}


void Tema1::OnMouseBtnPress(int mouseX, int mouseY, int button, int mods)
{
    // Add mouse button press event
    if (button == GLFW_MOUSE_BUTTON_LEFT + 1)
    {
        // Check for intersection with stars
        for (auto& star : stars)
        {
            if (star.isVisible && CheckStarIntersection(mouseX, mouseY, star.position))
            {
                star.isVisible = false;
                SpawnGrayStar();
                break;
            }
        }

        // Check if a diamond in the grid is clicked
        for (auto& diamond : diamonds)
        {
            if (CheckDiamondIntersection(mouseX, mouseY, diamond.position))
            {
                if (diamond.name == "diamond1" && grayStars.size() < 1) {
                    cout << "Not enough stars for diamond1" << endl;
                    break;
				}
                else if (diamond.name == "diamond2" && grayStars.size() < 2) {
                    cout << "Not enough stars for diamond2" << endl;
                    break;
				}
                else if (diamond.name == "diamond3" && grayStars.size() < 2) {
                    cout << "Not enough stars for diamond3" << endl;
                    break;
				}
                else if (diamond.name == "diamond4" && grayStars.size() < 3) {
                    cout << "Not enough stars for diamond4" << endl;
                    break;
                }
                else {
                    isDiamondDragged = true;
                    draggedDiamond.name = diamond.name;
                    draggedDiamond.position = diamond.position;
                    draggedDiamond.color = diamond.color;
                    break;
                }
            }
        }
    }
    else if (button == GLFW_MOUSE_BUTTON_RIGHT + 1) {
        // Check if a diamond in the grid is clicked
        for (auto& diamond : gridDiamonds)
        {
            if (CheckDiamondIntersection(mouseX, mouseY, diamond.position) && diamond.isVisible)
            {
                diamond.dying = 100.0f;
                break;
            }
        }

    }
    else if (button == GLFW_MOUSE_BUTTON_MIDDLE + 1) {
        if (maxPoints <= 0) {
            cout << "Special ability triggered!" << endl;
            for (auto& hexagon : hexagons) {
                hexagon.dying = 100;
            }
            for (auto& star : grayStars) {
                grayStars.pop_back();
                nextGrayStarPosition.x -= 50;
            }
        }
    }
}

bool Tema1::CheckStarIntersection(int mouseX, int mouseY, const glm::vec3& objPosition)
{
    return mouseX >= objPosition.x - 17.5 && mouseX <= objPosition.x + 17.5 &&
        (resolution.y - mouseY) >= objPosition.y - 17.5 && (resolution.y - mouseY) <= objPosition.y + 17.5;
}

bool Tema1::CheckSquareIntersection(int mouseX, int mouseY, const glm::vec3& objPosition)
{
    return mouseX >= objPosition.x && mouseX <= objPosition.x + 100 &&
        (resolution.y - mouseY) >= objPosition.y && (resolution.y - mouseY) <= objPosition.y + 100;
}

bool Tema1::CheckDiamondIntersection(int mouseX, int mouseY, const glm::vec3& objPosition)
{
    return mouseX >= objPosition.x - 25 && mouseX <= objPosition.x + 25 &&
        (resolution.y - mouseY) >= objPosition.y - 25 && (resolution.y - mouseY) <= objPosition.y + 25;
}


void Tema1::OnMouseBtnRelease(int mouseX, int mouseY, int button, int mods)
{
    // Add mouse button release event
    if (button == GLFW_MOUSE_BUTTON_LEFT + 1)
    {

        // Check if a diamond was being dragged
        if (isDiamondDragged)
        {
            // Check which square the mouse is over
            for (int i = 2; i <= 10; ++i)
            {
                std::string squareName = "square" + std::to_string(i);
                if (CheckSquareIntersection(mouseX, mouseY, squares[squareName]))
                {
                    int occupiedSquare = 0;
                    for (auto& diamond : gridDiamonds)
                    {
                        if (CheckDiamondIntersection(mouseX, mouseY, diamond.position) && diamond.isVisible)
                        {
                            occupiedSquare = 1;
                            break;
                        }
                    }
                    if (!occupiedSquare) {

                        // Place the diamond in the square
                        glm::vec3 squarePosition = squares[squareName];

                        // Create a duplicate of the diamond and add it to the gridDiamonds vector
                        diamondCount++;
                        std::string gridDiamondName = "gridDiamond" + std::to_string(diamondCount);
                        Mesh* gridDiamondMesh = object2D::CreateDiamond(gridDiamondName, draggedDiamond.color, true);
                        AddMeshToList(gridDiamondMesh);

                        int line, type;
                        if (i == 2 || i == 5 || i == 8) {
                            line = 1;
                        }
                        else if (i == 3 || i == 6 || i == 9) {
                            line = 2;
                        }
                        else {
                            line = 3;
                        }

                        if (draggedDiamond.name == "diamond1") {
                            grayStars.pop_back();
                            nextGrayStarPosition.x -= 50;
                            maxPoints++;
                            type = 1;
                        }
                        else if (draggedDiamond.name == "diamond2") {
                            grayStars.pop_back();
                            nextGrayStarPosition.x -= 50;
                            grayStars.pop_back();
                            nextGrayStarPosition.x -= 50;
                            maxPoints += 2;
                            type = 2;
                        }
                        else if (draggedDiamond.name == "diamond3") {
                            grayStars.pop_back();
                            nextGrayStarPosition.x -= 50;
                            grayStars.pop_back();
                            nextGrayStarPosition.x -= 50;
                            maxPoints += 2;
                            type = 3;
                        }
                        else if (draggedDiamond.name == "diamond4") {
                            grayStars.pop_back();
                            nextGrayStarPosition.x -= 50;
                            grayStars.pop_back();
                            nextGrayStarPosition.x -= 50;
                            grayStars.pop_back();
                            nextGrayStarPosition.x -= 50;
                            maxPoints += 3;
                            type = 4;
                        }

                        gridDiamonds.emplace_back(gridDiamondName, glm::vec3(squarePosition.x + 60, squarePosition.y + 60, 1), draggedDiamond.color, line, type);
                        break;
                    }
                    else {
                        cout << "This square is currently occupied" << endl;
                    }
                }
            }

            isDiamondDragged = false;
            draggedDiamond.name = "";
            draggedDiamond.position = glm::vec3(0.0f);
            draggedDiamond.color = glm::vec3(1.0f);
        }
    }
}


void Tema1::OnMouseScroll(int mouseX, int mouseY, int offsetX, int offsetY)
{
}


void Tema1::OnWindowResize(int width, int height)
{
}
