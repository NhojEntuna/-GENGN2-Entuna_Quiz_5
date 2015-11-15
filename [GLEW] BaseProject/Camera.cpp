#include <glm/glm.hpp>
#define GLM_FORCE_RADIANS
#include <glm/gtx/transform.hpp>
#include "Camera.h"

Camera::Camera(const glm::vec3& pos,float fov, float aspect, float znear, float zfar){
    m_prespective = glm::perspective(fov,aspect,znear,zfar);
    m_position = pos;
    m_forward = glm::vec3(0,0,-1);
    m_up = glm::vec3(0,1,0);
}

glm::mat4 Camera::GetViewProjection() const{
    return m_prespective * glm::lookAt(m_position,m_position+m_forward,m_up);
}