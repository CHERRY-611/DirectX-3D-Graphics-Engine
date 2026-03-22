#include "Character/Character.h"

Character::Character(_In_ const std::filesystem::path& filePath)
	:Model(filePath)
	, m_targetPosition()
	, m_currentPosition()
	, m_movementSpeed(10.0f)
	, m_moveLeftRight()
	, m_moveBackForward()
    , m_currentRotation(DOWN)
{
}

void Character::HandleInput(_In_ const InputDirections& directions, _In_ FLOAT deltaTime)
{
    if (directions.bFront)
    {
        m_moveBackForward += m_movementSpeed * deltaTime;
    }

    if (directions.bLeft)
    {
        m_moveLeftRight -= m_movementSpeed * deltaTime;
    }

    if (directions.bBack)
    {
        m_moveBackForward -= m_movementSpeed * deltaTime;
    }

    if (directions.bRight)
    {
        m_moveLeftRight += m_movementSpeed * deltaTime;
    }
}

void Character::Update(_In_ FLOAT deltaTime)
{
    if (m_moveLeftRight > 0)
    {
        switch (m_currentRotation) {
        case DOWN: RotateYInObjecteCoordinate(XMConvertToRadians(-90.0f), m_currentPosition); break;
        case UP: RotateYInObjecteCoordinate(XMConvertToRadians(90.0f), m_currentPosition); break;
        case LEFT: RotateYInObjecteCoordinate(XMConvertToRadians(180.0f), m_currentPosition); break;
        default: break;
        }
        m_currentRotation = RIGHT;
    }
    else if (m_moveLeftRight < 0)
    {
        switch (m_currentRotation) {
        case DOWN: RotateYInObjecteCoordinate(XMConvertToRadians(90.0f), m_currentPosition); break;
        case UP: RotateYInObjecteCoordinate(XMConvertToRadians(-90.0f), m_currentPosition); break;
        case RIGHT: RotateYInObjecteCoordinate(XMConvertToRadians(180.0f), m_currentPosition); break;
        default: break;
        }
        m_currentRotation = LEFT;
    }
    else if (m_moveBackForward > 0)
    {
        switch (m_currentRotation) {
        case DOWN: RotateYInObjecteCoordinate(XMConvertToRadians(180.0f), m_currentPosition); break;
        case LEFT: RotateYInObjecteCoordinate(XMConvertToRadians(90.0f), m_currentPosition); break;
        case RIGHT: RotateYInObjecteCoordinate(XMConvertToRadians(-90.0f), m_currentPosition); break;
        default: break;
        }
        m_currentRotation = UP;
    }
    else if (m_moveBackForward < 0)
    {
        switch (m_currentRotation) {
        case UP: RotateYInObjecteCoordinate(XMConvertToRadians(180.0f), m_currentPosition); break;
        case LEFT: RotateYInObjecteCoordinate(XMConvertToRadians(-90.0f), m_currentPosition); break;
        case RIGHT: RotateYInObjecteCoordinate(XMConvertToRadians(90.0f), m_currentPosition); break;
        default: break;
        }
        m_currentRotation = DOWN;
    }

    m_targetPosition += m_moveLeftRight * DEFAULT_RIGHT;
    m_targetPosition += m_moveBackForward * DEFAULT_FORWARD;

    m_moveLeftRight = 0.0f;
    m_moveBackForward = 0.0f;

    Translate(m_targetPosition-m_currentPosition);
    m_currentPosition = m_targetPosition;

}