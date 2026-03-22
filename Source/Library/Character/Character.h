#pragma once

#include "Common.h"

#include "Model/Model.h"

enum CharacterDirection {
    UP,
    LEFT,
    DOWN,
    RIGHT
};

class Character : public Model
{
public:
    Character() = default;
    Character(_In_ const std::filesystem::path& filePath);
    ~Character() = default;

    virtual void HandleInput(_In_ const InputDirections& directions, _In_ FLOAT deltaTime);
    virtual void Update(_In_ FLOAT deltaTime) override;

private:
    static constexpr const XMVECTORF32 DEFAULT_FORWARD = { 0.0f, 0.0f, 1.0f, 0.0f };
    static constexpr const XMVECTORF32 DEFAULT_RIGHT = { 1.0f, 0.0f, 0.0f, 0.0f };

    XMVECTOR m_targetPosition;
    XMVECTOR m_currentPosition;

    FLOAT m_moveLeftRight;
    FLOAT m_moveBackForward;

    CharacterDirection m_currentRotation;
    
    float m_movementSpeed;

};