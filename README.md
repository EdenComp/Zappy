# Documentation Zappy

Cette documentation est destinée à vous aider à installer et lancer le projet Zappy.

# Table des matières

- [Graphical](#Graphical)
    - [Installation](#Installation)
    - [Lancement](#Lancement)

# Graphical

La partie graphique de Zappy est réalisée avec la bibliothèque graphique [raylib](https://www.raylib.com/).

Elle est compilée grace à un cmake que vous pouvez trouver dans le fichier [CMakeLists.txt](CMakeLists.txt).

## Installation

Pour installer la bibliothèque graphique, il faut executer les commandes suivantes:

```bash
sudo dnf install -y cmake make gcc g++ libX11-devel libXrandr-devel libXcursor-devel libXi-devel mesa-libGL-devel mesa-libGLU-devel
git clone https://github.com/raysan5/raylib.git
cd raylib
cmake .
make
sudo make install
```

## Lancement

Pour lancer le jeu, il faut executer la commande suivante:

```bash
make
./cmake-build-debug/zappy_gui
```
