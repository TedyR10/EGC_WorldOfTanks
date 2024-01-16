// Copyright Theodor-Ioan Rolea 333CA 2023
#include "lab_m1/Tema2/Tema2.h"
#include "lab_m1/Tema2/lab_camera.h"

#include <vector>
#include <string>
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;
using namespace m1;


/*
 *  To find out more about `FrameStart`, `Update`, `FrameEnd`
 *  and the order in which they are called, see `world.cpp`.
 */


Tema2::Tema2()
{
}


Tema2::~Tema2()
{
}


void Tema2::Init()
{

    camera = new implemented::Camera();
    camera->Set(glm::vec3(0, 1.65f, -2.0f), glm::vec3(0, 1, 0), glm::vec3(0, 1, 0));
    srand(static_cast<unsigned>(time(nullptr)));

    {
        Mesh* mesh = new Mesh("senile");
        mesh->LoadMesh(PATH_JOIN(window->props.selfDir, RESOURCE_PATH::MODELS, "primitives"), "senile.fbx");
        meshes[mesh->GetMeshID()] = mesh;
    }

    {
        Mesh* mesh = new Mesh("corp");
        mesh->LoadMesh(PATH_JOIN(window->props.selfDir, RESOURCE_PATH::MODELS, "primitives"), "corp.fbx");
        meshes[mesh->GetMeshID()] = mesh;
    }

    {
        Mesh* mesh = new Mesh("turela");
        mesh->LoadMesh(PATH_JOIN(window->props.selfDir, RESOURCE_PATH::MODELS, "primitives"), "turela.fbx");
        meshes[mesh->GetMeshID()] = mesh;
    }

    {
        Mesh* mesh = new Mesh("teava");
        mesh->LoadMesh(PATH_JOIN(window->props.selfDir, RESOURCE_PATH::MODELS, "primitives"), "teava.fbx");
        meshes[mesh->GetMeshID()] = mesh;
    }

    {
        Mesh* mesh = new Mesh("plane");
        mesh->LoadMesh(PATH_JOIN(window->props.selfDir, RESOURCE_PATH::MODELS, "primitives"), "plane50.obj");
        meshes[mesh->GetMeshID()] = mesh;
    }

    {
        Mesh* mesh = new Mesh("box");
        mesh->LoadMesh(PATH_JOIN(window->props.selfDir, RESOURCE_PATH::MODELS, "primitives"), "box.obj");
        meshes[mesh->GetMeshID()] = mesh;
    }

    {
		Mesh* mesh = new Mesh("sphere");
		mesh->LoadMesh(PATH_JOIN(window->props.selfDir, RESOURCE_PATH::MODELS, "primitives"), "sphere.obj");
		meshes[mesh->GetMeshID()] = mesh;
	}

    // Create a shader program for drawing face polygon with the color of the normal
    {
        Shader* shader = new Shader("LabShader");
        shader->AddShader(PATH_JOIN(window->props.selfDir, SOURCE_PATH::M1, "Tema2", "shaders", "VertexShader.glsl"), GL_VERTEX_SHADER);
        shader->AddShader(PATH_JOIN(window->props.selfDir, SOURCE_PATH::M1, "Tema2", "shaders", "FragmentShader.glsl"), GL_FRAGMENT_SHADER);
        shader->CreateAndLink();
        shaders[shader->GetName()] = shader;
    }

    SpawnBuildings();
    SpawnTanks();

    projectionMatrix = glm::perspective(RADIANS(60), window->props.aspectRatio, 0.01f, 200.0f);

}


void Tema2::FrameStart()
{
    // Clears the color buffer (using the previously set color) and depth buffer
    glClearColor(0, 0.5, 1, 1);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glm::ivec2 resolution = window->GetResolution();
    // Sets the screen area where to draw
    glViewport(0, 0, resolution.x, resolution.y);
}


void Tema2::Update(float deltaTimeSeconds)
{
    gameCounter += deltaTimeSeconds;
    shootTimer += deltaTimeSeconds;
    if (gameCounter >= 90.0f && game) {
        cout<<"Time is up!"<<endl;
        game = false;
	}
    {
        glm::mat4 modelMatrix = glm::mat4(1);
        modelMatrix = glm::translate(modelMatrix, glm::vec3(translateX, 0.2f, translateZ));
        modelMatrix = glm::rotate(modelMatrix, RADIANS(-90.0f), glm::vec3(1, 0, 0));
        modelMatrix = glm::rotate(modelMatrix, rotation, glm::vec3(0, 0, 1));
        modelMatrix = glm::scale(modelMatrix, glm::vec3(0.5f));
        RenderSimpleMesh(meshes["senile"], shaders["LabShader"], modelMatrix, glm::vec3(0.5, 0.5, 0.5), health);

    }

    {
        glm::mat4 modelMatrix = glm::mat4(1);
        modelMatrix = glm::translate(modelMatrix, glm::vec3(translateX, 0.6f, translateZ));
        modelMatrix = glm::rotate(modelMatrix, RADIANS(-90.0f), glm::vec3(1, 0, 0));
        modelMatrix = glm::rotate(modelMatrix, rotation, glm::vec3(0, 0, 1));
        modelMatrix = glm::scale(modelMatrix, glm::vec3(0.5f));
        RenderSimpleMesh(meshes["corp"], shaders["LabShader"], modelMatrix, glm::vec3(0, 0.25, 0), health);

    }

    {
        glm::mat4 modelMatrix = glm::mat4(1);
        modelMatrix = glm::translate(modelMatrix, glm::vec3(translateX, 1.185f, translateZ - 0.1f));
        modelMatrix = glm::translate(modelMatrix, glm::vec3(0.0f, 0.0f, +0.1f));
        modelMatrix = glm::rotate(modelMatrix, RADIANS(-90.0f), glm::vec3(1, 0, 0));
        modelMatrix = glm::rotate(modelMatrix, rotation + turretRotation, glm::vec3(0, 0, 1));
        modelMatrix = glm::translate(modelMatrix, glm::vec3(0.0f, 0.0f, -0.1f));
        modelMatrix = glm::scale(modelMatrix, glm::vec3(0.25f));
        RenderSimpleMesh(meshes["turela"], shaders["LabShader"], modelMatrix, glm::vec3(0, 0.5, 0), health);
    }

    {
        glm::mat4 modelMatrix = glm::mat4(1);
        modelMatrix = glm::translate(modelMatrix, glm::vec3(translateX, 1.085f, translateZ + 1.0f));
        modelMatrix = glm::translate(modelMatrix, glm::vec3(0.0f, 0.0f, -1.0f));
        modelMatrix = glm::rotate(modelMatrix, rotation + turretRotation, glm::vec3(0, 1, 0));
        modelMatrix = glm::translate(modelMatrix, glm::vec3(0.0f, 0.0f, 1.0f));
        modelMatrix = glm::translate(modelMatrix, glm::vec3(0.0f, 0.0f, -1.0f));
        modelMatrix = glm::rotate(modelMatrix, -barrelRotation, glm::vec3(1, 0, 0));
        modelMatrix = glm::translate(modelMatrix, glm::vec3(0.0f, 0.0f, 1.0f));
        modelMatrix = glm::scale(modelMatrix, glm::vec3(0.5f));
        RenderSimpleMesh(meshes["teava"], shaders["LabShader"], modelMatrix, glm::vec3(0.5, 0.5, 0.5), health);
    }

    // Render ground
    {
        glm::mat4 modelMatrix = glm::mat4(1);
        modelMatrix = glm::translate(modelMatrix, glm::vec3(0, 0.02f, 0));
        modelMatrix = glm::scale(modelMatrix, glm::vec3(50.0f));
        // TODO(student): Add or change the object colors
        RenderSimpleMesh(meshes["plane"], shaders["LabShader"], modelMatrix, glm::vec3(0.4, 0.75, 0.2), -1);

    }

    //Render buildings
    for (auto& building : buildings) {
		glm::mat4 modelMatrix = glm::mat4(1);
		modelMatrix = glm::translate(modelMatrix, building.position);
		modelMatrix = glm::scale(modelMatrix, building.scale);
		RenderSimpleMesh(meshes["box"], shaders["LabShader"], modelMatrix, glm::vec3(0.8f, 0.8f, 0.8f), -1);
	}

    // Check tank collision with buildings
    for (auto& building : buildings) {
        if (translateX + 1.45f > building.position.x - building.scale.x / 2 &&
            translateX - 1.45f < building.position.x + building.scale.x / 2 &&
            translateZ + 1.45f > building.position.z - building.scale.z / 2 &&
            translateZ - 1.45f < building.position.z + building.scale.z / 2) {
            if (lastKeyPressed == 0) {
                translateX -= 0.5f * sin(rotation);
                translateZ -= 0.5f * cos(rotation);
                camera->MoveForward(-0.5f * cos(newCamera));
                camera->TranslateRight(-0.5f * sin(newCamera));
            }
            else {
				translateX += 0.5f * sin(rotation);
				translateZ += 0.5f * cos(rotation);
				camera->MoveForward(0.5f * cos(newCamera));
				camera->TranslateRight(0.5f * sin(newCamera));
			}
            break;
        }
    }

    // Check projectile collision 
    for (auto& projectile : projectiles) {
        if (projectile.active) {

            // Update projectile position
            projectile.position.x += projectile.speed.x * sin(projectile.rotation) * deltaTimeSeconds;
            projectile.position.y += projectile.speed.y * deltaTimeSeconds;
            projectile.position.z += projectile.speed.z * cos(projectile.rotation) * deltaTimeSeconds;

            // Apply gravity
            projectile.speed.y -= gravity * deltaTimeSeconds;

            // Render projectile
            glm::mat4 modelMatrix = glm::mat4(1);
            modelMatrix = glm::translate(modelMatrix, glm::vec3(projectile.position.x + 0.9f * sin(projectile.rotation), projectile.position.y + 0.01f * sin(projectile.barrelRotation * 1.0f), projectile.position.z + 0.9f * cos(projectile.rotation)));
            modelMatrix = glm::scale(modelMatrix, glm::vec3(0.10f));
            RenderSimpleMesh(meshes["sphere"], shaders["LabShader"], modelMatrix, glm::vec3(0, 0, 0), -1);

            // Check collision with player
            glm::vec3 playerPosition = glm::vec3(translateX, 0.02f, translateZ);
            if (projectile.position.x > playerPosition.x - 1.45f &&
                projectile.position.x < playerPosition.x + 1.45f &&
                projectile.position.z > playerPosition.z - 1.45f &&
                projectile.position.z < playerPosition.z + 1.45f &&
                projectile.position.y < playerPosition.y + 1.25f &&
                projectile.playerProjectile == false) {
                projectile.active = false;

                if (health > 0)
                    health -= 1;

                if (health <= 0) {
                    cout << "You got wrecked!" << endl;
                    game = false;
                }

                break;
            }

            // Check projectile collision with buildings
            for (auto& building : buildings) {
                if (projectile.position.x > building.position.x - building.scale.x / 2 &&
                    projectile.position.x < building.position.x + building.scale.x / 2 &&
                    projectile.position.z > building.position.z - building.scale.z / 2 &&
                    projectile.position.z < building.position.z + building.scale.z / 2 &&
                    projectile.position.y < building.position.y + building.scale.y / 2) {
                    projectile.active = false;
                    break;
                }
            }

            // Check projectile collision with other tanks
            for (auto& tank : tanks) {
                if (tank.active && projectile.playerProjectile == true) {
                    if (projectile.position.x > tank.position.x - 1.45f &&
                        projectile.position.x < tank.position.x + 1.45f &&
                        projectile.position.z > tank.position.z - 1.45f &&
                        projectile.position.z < tank.position.z + 1.45f &&
                        projectile.position.y < tank.position.y + 1.25f ) {
                        projectile.active = false;
                        tank.health -= 1;
                        if (tank.health <= 0) {
                            tank.active = false;
                            RandomPrint();
                            score += 1;
                        }
                        break;
                    }
                }
            }

            // Check if projectile hit the ground
            if (projectile.position.y <= 0) {;
                projectile.active = false;
            }
        }
    }

    // Render tanks
    for (auto& tank : tanks) {

        // Check collision with player
        if (CheckTankCollision(translateX, translateZ, tank)) {
            if (tank.health > 0) {
                tank.health -= 1;
                RandomPrint();
            }
            tank.active = false;
		}
        if (tank.active) {
            tank.timer += deltaTimeSeconds;

            glm::vec3 playerPosition = glm::vec3(translateX, 0.02f, translateZ);
            float distance = glm::distance(playerPosition, tank.position);
            if (game) {
                if (distance > areaSize)
                    TankMovement(deltaTimeSeconds, tank);
                else
                    TankShoot(tank, deltaTimeSeconds);
            }

            // Check tank-tank collision
            for (auto& otherTank : tanks) {
                if (otherTank.id != tank.id) {
                    float distanceBetweenTanks = glm::length(tank.position - otherTank.position);
                    float sumOfRadii = 4.5f - (4.0f - max(otherTank.health, tank.health)) / 4.0f;

                    if (distanceBetweenTanks < sumOfRadii) {
                        // Tanks have collided
                        float overlapDistance = sumOfRadii - distanceBetweenTanks;
                        glm::vec3 collisionDirection = glm::normalize(otherTank.position - tank.position);
                        glm::vec3 displacement = overlapDistance * collisionDirection;

                        // Move tanks in opposite directions to resolve collision
                        tank.position -= displacement * 0.5f;
                        otherTank.position += displacement * 0.5f;
                    }
                }
            }
        }

        // Check tank collision with buildings
        for (auto& building : buildings) {
            if (tank.position.x + 1.45f > building.position.x - building.scale.x / 2 &&
                tank.position.x - 1.45f < building.position.x + building.scale.x / 2 &&
                tank.position.z + 1.45f > building.position.z - building.scale.z / 2 &&
                tank.position.z - 1.45f < building.position.z + building.scale.z / 2) {
                if (tank.facingDirection == 0) {
                    tank.position.x -= 0.5f * sin(tank.rotation);
                    tank.position.z -= 0.5f * cos(tank.rotation);
                }
                else if (tank.facingDirection == 1) {
                    tank.position.x += 0.5f * sin(tank.rotation);
                    tank.position.z += 0.5f * cos(tank.rotation);
                }
                else {
                    tank.position.x -= 0.5f * sin(tank.rotation);
                    tank.position.z -= 0.5f * cos(tank.rotation);
                }
                break;
            }
        }
        {
            glm::mat4 modelMatrix = glm::mat4(1);
            modelMatrix = glm::translate(modelMatrix, glm::vec3(tank.position.x, 0.2f, tank.position.z));
            modelMatrix = glm::rotate(modelMatrix, RADIANS(-90.0f), glm::vec3(1, 0, 0));
            modelMatrix = glm::rotate(modelMatrix, tank.rotation, glm::vec3(0, 0, 1));
            modelMatrix = glm::scale(modelMatrix, glm::vec3(0.5f));
            RenderSimpleMesh(meshes["senile"], shaders["LabShader"], modelMatrix, glm::vec3(0.5, 0.5, 0.5), tank.health);

        }

        {
            glm::mat4 modelMatrix = glm::mat4(1);
            modelMatrix = glm::translate(modelMatrix, glm::vec3(tank.position.x, 0.6f, tank.position.z));
            modelMatrix = glm::rotate(modelMatrix, RADIANS(-90.0f), glm::vec3(1, 0, 0));
            modelMatrix = glm::rotate(modelMatrix, tank.rotation, glm::vec3(0, 0, 1));
            modelMatrix = glm::scale(modelMatrix, glm::vec3(0.5f));
            RenderSimpleMesh(meshes["corp"], shaders["LabShader"], modelMatrix, glm::vec3(0, 0.25, 0), tank.health);

        }

        {
            glm::mat4 modelMatrix = glm::mat4(1);
            modelMatrix = glm::translate(modelMatrix, glm::vec3(tank.position.x, 1.185f, tank.position.z - 0.1f));
            modelMatrix = glm::translate(modelMatrix, glm::vec3(0.0f, 0.0f, +0.1f));
            modelMatrix = glm::rotate(modelMatrix, RADIANS(-90.0f), glm::vec3(1, 0, 0));
            modelMatrix = glm::rotate(modelMatrix, tank.rotation + tank.turretRotation, glm::vec3(0, 0, 1));
            modelMatrix = glm::translate(modelMatrix, glm::vec3(0.0f, 0.0f, -0.1f));
            modelMatrix = glm::scale(modelMatrix, glm::vec3(0.25f));
            RenderSimpleMesh(meshes["turela"], shaders["LabShader"], modelMatrix, glm::vec3(0, 0.5, 0), tank.health);
        }

        {
            glm::mat4 modelMatrix = glm::mat4(1);
            modelMatrix = glm::translate(modelMatrix, glm::vec3(tank.position.x, 1.085f, tank.position.z + 1.0f));
            modelMatrix = glm::translate(modelMatrix, glm::vec3(0.0f, 0.0f, -1.0f));
            modelMatrix = glm::rotate(modelMatrix, tank.rotation + tank.turretRotation, glm::vec3(0, 1, 0));
            modelMatrix = glm::translate(modelMatrix, glm::vec3(0.0f, 0.0f, 1.0f));
            modelMatrix = glm::translate(modelMatrix, glm::vec3(0.0f, 0.0f, -1.0f));
            modelMatrix = glm::rotate(modelMatrix, -tank.barrelRotation, glm::vec3(1, 0, 0));
            modelMatrix = glm::translate(modelMatrix, glm::vec3(0.0f, 0.0f, 1.0f));
            modelMatrix = glm::scale(modelMatrix, glm::vec3(0.5f));
            RenderSimpleMesh(meshes["teava"], shaders["LabShader"], modelMatrix, glm::vec3(0.5, 0.5, 0.5), tank.health);
        }
    }

}

void Tema2::RandomPrint() {
    srand((unsigned int)time(NULL));
	int random = rand() % 100;
    if (random < 25) {
		cout << "BOOM! Headshot!" << endl;
	}
    else if (random < 50 && random >= 25) {
		cout << "Keep going!" << endl;
	}
    else if (random < 75 && random >= 50) {
		cout << "Nice Shot!" << endl;
	}
    else if (random < 100 && random >=75) {
		cout << "R3kt!" << endl;
	}
    else {
		cout << "That's impressive!" << endl;
	}

}

void Tema2::TankMovement(float deltaTimeSeconds, Tank& tank) {
    const float moveSpeed = 2.0f;
    const float rotateSpeed = 2.0f;

    glm::vec3 originalPosition = tank.position;

    switch (tank.facingDirection) {
    case 0:
        tank.position.x += deltaTimeSeconds * moveSpeed * sin(tank.rotation);
        tank.position.z += deltaTimeSeconds * moveSpeed * cos(tank.rotation);
        break;

    case 1:
        tank.position.x -= deltaTimeSeconds * moveSpeed * sin(tank.rotation);
        tank.position.z -= deltaTimeSeconds * moveSpeed * cos(tank.rotation);
        break;

    case 2:
        tank.rotation -= deltaTimeSeconds * rotateSpeed;
        break;

    case 3:
        tank.rotation += deltaTimeSeconds * rotateSpeed;
        break;

    default:
        break;
    }

    if (CheckTankCollision(translateX, translateZ, tank)) {
        tank.position = originalPosition;
    }

    float changeStateCooldown = rand() % 5 + 2;
    tank.timer += deltaTimeSeconds;
    if (tank.timer >= changeStateCooldown) {
        tank.facingDirection = GetNextMovementState(tank.facingDirection);
        tank.timer = 0.0f;
    }
}



int Tema2::GetNextMovementState(const int currentState)
{
    int randomChange = rand() % 2;
    int nextState = currentState;

    switch (currentState)
    {
    case 0:
    case 1:
        nextState = (randomChange == 1)
            ? 2
            : 3;
        break;

    case 2:
    case 3:
        nextState = (randomChange == 1)
            ? 0
            : 1;
        break;

    default:
        break;
    }

    return nextState;
}

void Tema2::SpawnTanks() {
    	srand((unsigned int)time(NULL));
        int id = 0;
        for (int i = 0; i < (rand() % 50 + 15); i++) {
		float x = (float)(rand() % 200 + -105.0f);
		float z = (float)(rand() % 200 + -105.0f);
		glm::vec3 position = glm::vec3(x, 0.02f, z);
		float rotation = (float)(rand() % 360);
        float turretRotation = 0;
		Tank tank = Tank(position, rotation, turretRotation, id);
        id++;
        while (CheckTankCollision(translateX, translateZ, tank) && CheckBuildingCollision(tank, buildings)) {
            tank.position.x = (float)(rand() % 200 + -105.0f);
            tank.position.z = (float)(rand() % 200 + -105.0f);
        }
		tanks.push_back(tank);
	}
            
}

bool Tema2::CheckBuildingCollision(Tank& tank, std::vector<Building> buildings) {
    bool collision = false;
    for (auto& building : buildings) {
        if (tank.position.x + 1.45f > building.position.x - building.scale.x / 2 &&
            tank.position.x - 1.45f < building.position.x + building.scale.x / 2 &&
            tank.position.z + 1.45f > building.position.z - building.scale.z / 2 &&
            tank.position.z - 1.45f < building.position.z + building.scale.z / 2) {
            collision = true;
            break;
        }
    }

    return collision;
}

bool Tema2::CheckTankCollision(float translateX, float translateZ, Tank& tank)
{
    glm::vec3 playerPosition = glm::vec3(translateX, 0.02f, translateZ);
    float distanceBetweenTanks = glm::length(tank.position - playerPosition);
    float sumOfRadii = 4.0f - (4.0f - max(health, tank.health)) / 4.0f;

    if (distanceBetweenTanks < sumOfRadii) {
        // Tanks have collided
        float overlapDistance = sumOfRadii - distanceBetweenTanks;
        glm::vec3 collisionDirection = glm::normalize(playerPosition - tank.position);
        glm::vec3 displacement = overlapDistance * collisionDirection;

        // Move tanks in opposite directions to resolve collision
        tank.position -= displacement * 0.5f;
    }

    return distanceBetweenTanks < sumOfRadii;
}

void Tema2::TankShoot(Tank& tank, float deltaTimeSeconds) {
    glm::vec3 playerPosition = glm::vec3(translateX, 0.02f, translateZ);
    float distance = glm::distance(tank.position, playerPosition);

    // Check if the player is in range
    if (distance < areaSize) {
        glm::vec3 relativeToPlayer = glm::normalize(playerPosition - tank.position);

        // Compute the angle between the tank's forward vector and the direction to the player
        float relativeAngle = atan2(relativeToPlayer.x, relativeToPlayer.z) - tank.rotation;

        // Make sure the angle is in the [0, 2 * PI] range
        relativeAngle = fmod(relativeAngle, 2 * M_PI);

        if (relativeAngle < 0.0f)
            relativeAngle += 2 * M_PI;
        else if (relativeAngle > 2 * M_PI)
            relativeAngle -= 2 * M_PI;

        // Rotate the tank towards the player
        if (tank.turretRotation != relativeAngle) {
            tank.turretRotation = glm::mix(tank.turretRotation, relativeAngle, deltaTimeSeconds * rotateSpeed * 4);
        }

        // Scale the distance to the [0, 1] range
        float scaledDistance = (distance < 0.0f) ? 0.0f : ((distance > areaSize) ? 1.0f : distance / areaSize);

        // Compute the barrel rotation
        float adjustedBarrelRotation = -0.1f + scaledDistance * (0.115f - (-0.1f));
        tank.barrelRotation = glm::mix(tank.barrelRotation, adjustedBarrelRotation, deltaTimeSeconds * 2);

        // Check if the tank can shoot
        if (tank.timer >= 5.0f) {
            tank.timer = 0.0f;

            Projectile projectile;
            projectile.active = true;
            projectile.rotation = tank.rotation + tank.turretRotation;
            projectile.barrelRotation = tank.barrelRotation;
            projectile.position = glm::vec3(tank.position.x + 0.9f * sin(projectile.rotation),
                1.085f + (projectile.barrelRotation * 1.75f),
                tank.position.z + 0.9f * cos(projectile.rotation));
            projectile.speed.y *= 1.75f * sin(projectile.barrelRotation);
            projectile.playerProjectile = false;

            projectiles.push_back(projectile);
        }
    }
}

void Tema2::SpawnBuildings() {

    	srand((unsigned int)time(NULL));
        for (int i = 0; i < (rand() % 100 + 100); i++) {
            float x = RandomXCoordinate();
            float z = RandomZCoordinate();
            glm::vec3 position = glm::vec3(x, 0.02f, z);
            float length = (float)(rand() % 5 + 3.0f);
            float width = (float)(rand() % 5 + 3.0f);
            float height = (float)(rand() % 15 + 10.0f);
            glm::vec3 scale = glm::vec3(length, height, width);
            Building building = Building(position, scale);
            if (building.position.x * length > translateX - 15.0f && building.position.x * length < translateX + 15.0f &&
                building.position.z * width > translateZ - 15.0f && building.position.z * width < translateZ + 15.0f) {
                continue;
            }
            buildings.push_back(building);
        }
}

float Tema2::RandomXCoordinate()
{
    return (float)(rand() % 200 + -105.0f);
}

float Tema2::RandomZCoordinate()
{
    return (float)(rand() % 200 + -105.0f);
}

void Tema2::FrameEnd()
{
}

void Tema2::RenderMesh(Mesh* mesh, Shader* shader, const glm::mat4& modelMatrix)
{
    if (!mesh || !shader || !shader->program)
        return;

    // Render an object using the specified shader and the specified position
    shader->Use();
    glUniformMatrix4fv(shader->loc_view_matrix, 1, GL_FALSE, glm::value_ptr(camera->GetViewMatrix()));
    glUniformMatrix4fv(shader->loc_projection_matrix, 1, GL_FALSE, glm::value_ptr(projectionMatrix));
    glUniformMatrix4fv(shader->loc_model_matrix, 1, GL_FALSE, glm::value_ptr(modelMatrix));

    mesh->Render();
}

void Tema2::RenderSimpleMesh(Mesh* mesh, Shader* shader, const glm::mat4& modelMatrix, const glm::vec3& color, int health)
{
    if (!mesh || !shader || !shader->GetProgramID())
        return;

    // Render an object using the specified shader and the specified position
    glUseProgram(shader->program);

    // Set eye position (camera position) uniform
    glm::vec3 eyePosition = GetSceneCamera()->m_transform->GetWorldPosition();
    int eye_position = glGetUniformLocation(shader->program, "eye_position");
    glUniform3f(eye_position, eyePosition.x, eyePosition.y, eyePosition.z);

    // Set material property uniforms (shininess, kd, ks, object color) 
    
    int object_color = glGetUniformLocation(shader->program, "object_color");
    glUniform3f(object_color, color.r, color.g, color.b);

    int health_uniform = glGetUniformLocation(shader->program, "health");
    glUniform1i(health_uniform, health);

    // Bind model matrix
    GLint loc_model_matrix = glGetUniformLocation(shader->program, "Model");
    glUniformMatrix4fv(loc_model_matrix, 1, GL_FALSE, glm::value_ptr(modelMatrix));

    // Bind view matrix
    glm::mat4 viewMatrix = camera->GetViewMatrix();
    int loc_view_matrix = glGetUniformLocation(shader->program, "View");
    glUniformMatrix4fv(loc_view_matrix, 1, GL_FALSE, glm::value_ptr(viewMatrix));

    // Bind projection matrix
    glm::mat4 projectionMatrix = GetSceneCamera()->GetProjectionMatrix();
    int loc_projection_matrix = glGetUniformLocation(shader->program, "Projection");
    glUniformMatrix4fv(loc_projection_matrix, 1, GL_FALSE, glm::value_ptr(projectionMatrix));

    // Draw the object
    glBindVertexArray(mesh->GetBuffers()->m_VAO);
    glDrawElements(mesh->GetDrawMode(), static_cast<int>(mesh->indices.size()), GL_UNSIGNED_INT, 0);
}


/*
 *  These are callback functions. To find more about callbacks and
 *  how they behave, see `input_controller.h`.
 */


void Tema2::OnInputUpdate(float deltaTime, int mods)
{
    float speed = 2;
    float cameraSpeed = 2.0f;

    if (window->KeyHold(GLFW_KEY_W) && game) {
        lastKeyPressed = 0;
        translateZ += deltaTime * moveSpeed * cos(rotation);
        translateX += deltaTime * moveSpeed * sin(rotation);
        camera->MoveForward(deltaTime * moveSpeed * cos(newCamera));
        camera->TranslateRight(deltaTime * moveSpeed * sin(newCamera));
    }
    if (window->KeyHold(GLFW_KEY_A) && game) {
        rotation += deltaTime * rotateSpeed;
        camera->RotateThirdPerson_OY(deltaTime * rotateSpeed);
    }
    if (window->KeyHold(GLFW_KEY_S) && game) {
        lastKeyPressed = 1;
        translateZ -= deltaTime * moveSpeed * cos(rotation);;
        translateX -= deltaTime * moveSpeed * sin(rotation);;
        camera->MoveForward(-deltaTime * moveSpeed * cos(newCamera));
        camera->TranslateRight(-deltaTime * moveSpeed * sin(newCamera));
    }
    if (window->KeyHold(GLFW_KEY_D) && game) {
        rotation -= deltaTime * rotateSpeed;
        camera->RotateThirdPerson_OY(-deltaTime * rotateSpeed);
    }
    if (window->KeyHold(GLFW_KEY_F) && !game) {
        game = true;
        cout<<"Game over"<<endl;
        cout<<"Score: "<<score<<endl;
        exit(0);
    }
}


void Tema2::OnKeyPress(int key, int mods)
{
    // Add key press event
}


void Tema2::OnKeyRelease(int key, int mods)
{
    // Add key release event
}


void Tema2::OnMouseMove(int mouseX, int mouseY, int deltaX, int deltaY)
{
    // Add mouse move event
    if (window->MouseHold(GLFW_MOUSE_BUTTON_RIGHT))
    {
        float sensivityOX = 0.001f;
        float sensivityOY = 0.001f;

        if (window->GetSpecialKeyState() == 0) {
            renderCameraTarget = true;
            camera->RotateThirdPerson_OX(-sensivityOX * deltaY);
            camera->RotateThirdPerson_OY(-sensivityOY * deltaX);
            newCamera -= sensivityOX * deltaX;
            turretRotation -= sensivityOX * deltaX;
        }
    }
    else {
        if (!renderCameraTarget) {
			turretRotation -= deltaX * 0.0025f;
            barrelRotation -= deltaY * 0.00075f;
		}
        else {
            renderCameraTarget = false;
		}
    }
}


void Tema2::OnMouseBtnPress(int mouseX, int mouseY, int button, int mods)
{
    // Add mouse button press event
    if (IS_BIT_SET(button, GLFW_MOUSE_BUTTON_LEFT) && game) {
        Projectile projectile = Projectile();
		projectile.active = true;
		projectile.rotation = rotation + turretRotation;
        projectile.barrelRotation = barrelRotation;
        projectile.position = glm::vec3(translateX + 0.9f * sin(projectile.rotation), 1.085f + (projectile.barrelRotation * 1.75f), translateZ + 0.9f * cos(projectile.rotation));
		projectile.time = 0.0f;
        projectile.speed.y *= 1.75f * sin(projectile.barrelRotation);
        projectile.playerProjectile = true;
        if (shootTimer >= 1.0f) {
            projectiles.push_back(projectile);
			shootTimer = 0.0f;
        }
	}
}


void Tema2::OnMouseBtnRelease(int mouseX, int mouseY, int button, int mods)
{
    // Add mouse button release event
}


void Tema2::OnMouseScroll(int mouseX, int mouseY, int offsetX, int offsetY)
{
}


void Tema2::OnWindowResize(int width, int height)
{
}