/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** Raylibcpp
*/

#ifndef RAYLIBCPP_HPP_
    #define RAYLIBCPP_HPP_

    #include <iostream>
    #include <raylib.h>
    #include "raymath.h"

namespace Raylibcpp {
    class Error : public std::exception {
        public:
            Error(std::string const &message) : _message(message) {};
            ~Error() = default;
            const char *what() const noexcept override { return _message.c_str(); }
        private:
            std::string _message;
    };
    class RayWindow {
        public:
            RayWindow() = default;
            ~RayWindow() = default;
            void initWindow(int width, int height, const char *title);
            void setTargetFPS(int fps);
            bool isKeyPressed(int key);
            bool isKeyReleased(int key);
            bool isKeyDown(int key);
            void updateCamera(Camera *camera, int mode);
            void setWindowSize(int width, int height);
            void beginDrawing();
            void endDrawing();
            void clearBackground(Color color);
            void beginMode3D(Camera3D camera);
            void endMode3D();
            bool windowShouldClose();
    };
    class RayModel {
        public:
            RayModel() = default;
            ~RayModel() = default;
            Image loadImage(const char *fileName);
            void unloadImage(Image image);
            Model loadModel(const char *fileName);
            void unloadModel(Model model);
            Texture2D loadTexture(const char *fileName);
            void unloadTexture(Texture2D texture);
            void setMaterialTexture(Material *material, int mapType, Texture2D texture);
            ModelAnimation *loadModelAnimations(const char *fileName, unsigned int *animCount);
            void unloadModelAnimations(ModelAnimation *anim, unsigned int animCount);
            void updateModelAnimation(Model model, ModelAnimation anim, int frame);
            void drawModel(Model mod, Vector3 pos, float scale, Color color);
            void drawRectangle(int posX, int posY, int width, int height, Color color);
            void drawTexture(Texture2D texture, int posX, int posY, Color color);
            void drawTextureEx(Texture2D texture, Vector2 position, float rotation, float scale, Color tint);
            Matrix matrixRotateXYZ(Vector3 angle);
    };
    class RayCube {
        public:
            RayCube() = default;
            ~RayCube() = default;
            void drawCube(Vector3 position, float width, float height, float length, Color color);
            void drawCubeWires(Vector3 position, float width, float height, float length, Color color);
    };
    class RayText {
        public:
            RayText() = default;
            RayText(std::string string, int posX, int posY, int fontSize, Color color);
            ~RayText() = default;
            void drawText(std::string string, int posX, int posY, int fontSize, Color color);
            std::string getString() const;
            void setString(const std::string &string);
            std::string _string;
            int _posX;
            int _posY;
            int _fontSize;
            Color _color;
    };
    class RayMouse {
        public:
            RayMouse() = default;
            ~RayMouse() = default;
            Vector2 getMousePosition();
            int getMouseX();
            int getMouseY();
            bool checkCollisionRecs(Rectangle rec1, Rectangle rec2);
            bool isMouseButtonPressed(int button);
            bool isMouseButtonDown(int button);
            bool isMouseButtonReleased(int button);
    };
    class RayMusic {
        public:
            RayMusic() = default;
            ~RayMusic() = default;
            void initAudioDevice() const;
            Music loadMusicStream(const std::string &fileName);
            void unloadMusicStream(Music music);
            void playMusicStream(Music music);
            void updateMusicStream(Music music);
            void stopMusicStream(Music music);
            void resumeMusicStream(Music music);
            void pauseMusicStream(Music music);
            void setMusicVolume(Music music, float volume);
            void setMusicPitch(Music music, float pitch);
            float getMusicTimeLength(Music music);
            float getMusicTimePlayed(Music music);
            void closeAudioDevice() const;
    };
    class RaySound {
        public:
            RaySound() = default;
            ~RaySound() = default;
            void initAudioDevice() const;
            Sound loadSound(const std::string &fileName);
            void unloadSound(Sound sound);
            void playSound(Sound sound);
            void stopSound(Sound sound);
            void setSoundVolume(Sound sound, float volume);
    };
    class RayClock {
        public:
            RayClock() = default;
            ~RayClock() = default;
            double getTime();
    };
}

#endif /* !RAYLIBCPP_HPP_ */
