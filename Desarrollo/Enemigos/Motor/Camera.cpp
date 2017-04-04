#include <SFML/Graphics/View.hpp>
#include "Camera.hpp"

Camera::Camera() {
   p_camera = new sf::View();
   p_camera->setSize(1250, 750);

}

Camera::Camera(const Camera& orig) {
}

Camera::~Camera() {
    delete p_camera;
}

sf::View Camera::getCamera() {
    return * p_camera;
}

void Camera::setCenter(float x, float y) {
    p_camera->setCenter(x, y);
}


