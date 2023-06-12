/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** model
*/

#include "encapsulation/Raylibcpp.hpp"

void Raylibcpp::RayModel::drawModel(Model mod, Vector3 pos, float scale, Color color)
{
    DrawModel(mod, pos, scale, color);
}

ModelAnimation *Raylibcpp::RayModel::loadModelAnimations(const char *fileName, unsigned int *animCount)
{
    return LoadModelAnimations(fileName, animCount);
}

Model Raylibcpp::RayModel::loadModel(const char *fileName)
{
    return LoadModel(fileName);
}

void Raylibcpp::RayModel::unloadModel(Model model)
{
    UnloadModel(model);
}

Texture2D Raylibcpp::RayModel::loadTexture(const char *fileName)
{
    return LoadTexture(fileName);
}

void Raylibcpp::RayModel::unloadTexture(Texture2D texture)
{
    UnloadTexture(texture);
}

void Raylibcpp::RayModel::setMaterialTexture(Material *material, int mapType, Texture2D texture)
{
    SetMaterialTexture(material, mapType, texture);
}

void Raylibcpp::RayModel::updateModelAnimation(Model model, ModelAnimation anim, int frame)
{
    UpdateModelAnimation(model, anim, frame);
}

void Raylibcpp::RayModel::drawTexture(Texture2D texture, int posX, int posY, Color color)
{
    DrawTexture(texture, posX, posY, color);
}

void Raylibcpp::RayModel::drawRectangle(int posX, int posY, int width, int height, Color color)
{
    DrawRectangle(posX, posY, width, height, color);
}

Matrix Raylibcpp::RayModel::matrixRotateXYZ(Vector3 angle)
{
    return MatrixRotateXYZ(angle);
}
