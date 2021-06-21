#include "Camera.h"

Camera::Camera(Window* window, Level* level, int zoomX, int zoomY)
{
    this->window = window;
    this->level = level;
    cam = { 0, 0, window->GetWidth(), window->GetHeight() };
}

Camera::~Camera()
{
}

void Camera::Update()
{
    cam.x = target->x;
    cam.y = target->y;
    if (cam.x < 0)
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
    }
}

void Camera::SetLevel(Level* level)
{
    this->level = level;
}

void Camera::SetTarget(SDL_Rect* target)
{
    this->target = target;
}
