#include "entity.hpp"
#include "../deserialize-utils.hpp"

#include <glm/gtx/euler_angles.hpp>

namespace our {

    // This function computes and returns a matrix that represents this transform
    // Remember that the order of transformations is: Scaling, Rotation then Translation
    // HINT: to convert euler angles to a rotation matrix, you can use glm::yawPitchRoll
    glm::mat4 Transform::toMat4() const {
        glm::mat4 TransformationMatrix = glm::mat4(1.0f);
        TransformationMatrix = TransformationMatrix *  glm::translate(glm::mat4(1.0f), position);
        TransformationMatrix = TransformationMatrix * glm::yawPitchRoll(rotation.y, rotation.x, rotation.z)  ;
        TransformationMatrix = TransformationMatrix* glm::scale(glm::mat4(1.0f), scale);
        return TransformationMatrix;
    }

     // Deserializes the entity data and components from a json object
    void Transform::deserialize(const nlohmann::json& data){
        position = data.value("position", position);
        rotation = glm::radians(data.value("rotation", glm::degrees(rotation)));
        scale    = data.value("scale", scale);
    }

    void Transform::set(glm::vec3 &position, glm::vec3 &rotation, glm::vec3 &scale)
    {
        this->position = position;
        this->rotation = glm::radians(rotation);
        this->scale = scale;
    }

}