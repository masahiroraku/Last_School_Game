#include "DirectionalLight.h"



DirectionalLight::DirectionalLight(const Vector3 & position, const Vector3 & direction)
	: position(position)
	, direction(direction.GetNormal())
{
}

DirectionalLight::~DirectionalLight()
{
}

Vector3 DirectionalLight::GetPosition() const
{
	return position;
}

Vector3 DirectionalLight::GetDirection() const
{
	return direction;
}

void DirectionalLight::SetPosition(const Vector3 & position)
{
	this->position = position;
}

void DirectionalLight::SetDirection(const Vector3 & direction)
{
	this->direction = direction.GetNormal();
}
