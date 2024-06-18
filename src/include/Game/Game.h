#pragma once

#include "Components/AStar.h"

#include "Cursor.h"
#include "Camera.h"

#include "../UI/UI.h"

#include "Map/Map.h"
#include "Faction.h"

#include "../WindowStates/WindowState.h"

namespace Struct {
    struct Game;
}

class Game : public WindowState {
public:
    static Cursor cursor;
    static Camera camera;

    static UI* ui;

    static Faction playerFaction;

    Game();
    ~Game();

    void init() override;
    void update() override;
    void render() override;
    void clean() override;

    static void AddStartingEntities(const int pawnCount, const int warriorCount, const int archerCount);
    
    static int CountSelectedEntities();
    static void ReleaseSelectedEntities();
    static void SelectEntities();
    static void SelectEntityAt(const Vector2D* pos);

    static Struct::Game GetStructure();

    static std::vector<Vector2D> FindPath(const Vector2D& start, const Vector2D& end);

private:
    static AStar::Generator generator;
    
    static Map* map;
    static std::vector<Entity*> selectedEntities;
};
