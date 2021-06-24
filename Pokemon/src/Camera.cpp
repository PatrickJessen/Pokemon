#include "Camera.h"

Camera::Camera(Window* window, Trainer* trainer, int zoom, int tileSize)
{
    this->window = window;
    this->tileSize = tileSize;
    this->trainer = trainer;
    cam = { trainer->GetTileX(tileSize), trainer->GetTileY(tileSize), tileSize * zoom, tileSize * zoom };
}

Camera::~Camera()
{
}

void Camera::Update()
{
    cam.x = ((trainer->GetXPos() + trainer->GetWidth() / 2) - window->GetWidth() / 2);
    cam.y = ((trainer->GetYPos() + trainer->GetHeight() / 2) - window->GetHeight() / 2);

    if (cam.x < 0)
    {
        cam.x = 0;
    }
    if (cam.y < 0)
    {
        cam.y = 0;
    }
    if (cam.x > window->GetWidth() / 2 - cam.w * 10)
    {
        cam.x = window->GetWidth() / 2 - cam.w * 10;
    }
    if (cam.y > window->GetHeight() + cam.w * 2)
    {
        cam.y = window->GetHeight() + cam.w * 2;
    }

    //std::cout << trainer->GetTileX(tileSize) + cam.x / tileSize << ", " << trainer->GetTileY(tileSize) + cam.y / tileSize << "\n";

}

SDL_Rect* Camera::SetCamera()
{
    return &cam;
}

//void Camera::SetLevel(Level* level)
//{
//    this->level = level;
//}

void Camera::SetTarget(Trainer* target)
{
    this->trainer = target;
}
