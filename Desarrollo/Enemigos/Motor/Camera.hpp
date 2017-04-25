#ifndef CAMERA_HPP
#define CAMERA_HPP

class Camera {
public:
    Camera();
    Camera(const Camera& orig);
    virtual ~Camera();
    sf::View getCamera();
    void setCenter(float x, float y);
private:
    sf::View * p_camera;
    
};

#endif /* CAMERA_HPP */

