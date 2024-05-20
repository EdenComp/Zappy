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
    ModelAnimation * anim = LoadModelAnimations(fileName, (int *)animCount);

    if (anim == NULL)
        throw Error("Error: Cannot load model animations");
    return anim;
}

void Raylibcpp::RayModel::unloadModelAnimations(ModelAnimation *anim, unsigned int animCount)
{
    if (anim == NULL)
        throw Error("Error: Cannot unload model animations");
    UnloadModelAnimations(anim, animCount);
}

Model Raylibcpp::RayModel::loadModel(const char *fileName)
{
    Model model = LoadModel(fileName);
    
    if (model.bones == 0)
        throw Error("Error: Cannot load model");
    return model;
}

void Raylibcpp::RayModel::unloadModel(Model model)
{
    UnloadModel(model);
}

Texture2D Raylibcpp::RayModel::loadTexture(const char *fileName)
{
    Texture2D texture = LoadTexture(fileName);

    if (texture.id == 0)
        throw Error("Error: Cannot load texture");
    return texture;
}

void Raylibcpp::RayModel::unloadTexture(Texture2D texture)
{
    if (texture.id == 0)
        throw Error("Error: Cannot unload texture");
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

Image Raylibcpp::RayModel::loadImage(const char *fileName)
{
    Image image = LoadImage(fileName);

    if (image.data == NULL)
        throw Error("Error: Cannot load image");
    return image;
}

void Raylibcpp::RayModel::unloadImage(Image image)
{
    UnloadImage(image);
}

void Raylibcpp::RayModel::drawTextureEx(Texture2D texture, Vector2 position, float rotation, float scale, Color tint)
{
    DrawTextureEx(texture, position, rotation, scale, tint);
}
