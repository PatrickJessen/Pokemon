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
    cam.x = (trainer->GetXPos()) - window->GetWidth() / 2;
    cam.y = (trainer->GetYPos()) - window->GetHeight() / 2;

    /*if (cam.x < 0)
    {
        cam.x = 0;
    }
    if (cam.y < 0)
    {
        cam.y = 0;
    }
    if (cam.x > window->GetWidth() - cam.w)
    {
        cam.x = window->GetWidth() - cam.w;
    }
    if (cam.y > window->GetHeight() - cam.h)
    {
        cam.y = window->GetHeight() - cam.h;
    }*/

    //std::cout << trainer->GetTileX(tileSize) - cam.x / tileSize << ", " << trainer->GetTileY(tileSize) - cam.y / tileSize << "\n";

}

//void Camera::SetLevel(Level* level)
//{
//    this->level = level;
//}

void Camera::SetTarget(SDL_Rect* target)
{
    this->target = target;
}
