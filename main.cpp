#include "raylib.h"
#include <cstdlib>

int main() {
    // iniciar la pantalla
    InitWindow(800, 600, "Ram Model");
    
    // camara 3D
    Camera3D camera = { 0 };
    camera.position = (Vector3){ 10.0f, 10.0f, 13.0f }; // direccion de la camara
    camera.target = (Vector3){ 0.0f, 2.0f, 0.0f };      // a donde mira la cámara
    camera.up = (Vector3){ 0.0f, 1.0f, 0.0f };          // direccion de "arriba"
    camera.fovy = 45.0f;                                // campo de visión
    camera.projection = CAMERA_PERSPECTIVE;

    float rotacion = 0.0f;
    SetTargetFPS(60); // fps de la simulacion

    while (!WindowShouldClose()) {
        // rotar al carnero
        rotacion += 1.5f;

        // dibujando la geometria del carnero
        BeginDrawing();
            ClearBackground(RAYWHITE);
            BeginMode3D(camera);

                // el cuerpo del carnero es un rectangulo blanco xd
                DrawCubeV((Vector3){ 0, 2, 0 }, (Vector3){ 4, 2, 2 }, WHITE);
                DrawCubeWiresV((Vector3){ 0, 2, 0 }, (Vector3){ 4, 2, 2 }, LIGHTGRAY);

                // la cabeza
                DrawCube((Vector3){ 2.5f, 3.0f, 0 }, 1.2f, 1.2f, 1.2f, WHITE);

                // los cuernos (dos cilindros oscuros)
                DrawSphere((Vector3){ 2.8f, 3.5f, 0.6f }, 0.4f, DARKBROWN);
                DrawSphere((Vector3){ 2.8f, 3.5f, -0.6f }, 0.4f, DARKBROWN);

                // patas ñam patas (cilindros o cubos finos)
                DrawCube((Vector3){ -1.5f, 0.5f, 0.7f }, 0.4f, 1.5f, 0.4f, GRAY);
                DrawCube((Vector3){ 1.5f, 0.5f, 0.7f }, 0.4f, 1.5f, 0.4f, GRAY);
                DrawCube((Vector3){ -1.5f, 0.5f, -0.7f }, 0.4f, 1.5f, 0.4f, GRAY);
                DrawCube((Vector3){ 1.5f, 0.5f, -0.7f }, 0.4f, 1.5f, 0.4f, GRAY);

                DrawGrid(10, 1.0f); // dibujar un suelo para que el carnero se vea bien fino

            EndMode3D();
            
            DrawText("Ram Model", 10, 10, 20, DARKGRAY);
        EndDrawing();
    }

    CloseWindow();
    return EXIT_SUCCESS; // Retorna éxito de manera más clara que el "0"
}