#include "DirectionalLight.h"



DirectionalLight::DirectionalLight(const Vector3 & direction)
	: direction(direction.GetNormal())
{
}

DirectionalLight::~DirectionalLight()
{
}

Vector3 DirectionalLight::GetPosition() const
{
	return Vector3::Zero;
}

Vector3 DirectionalLight::GetDirection() const
{
	return direction;
}

void DirectionalLight::SetPosition(const Vector3 & position)
{
	
}

void DirectionalLight::SetDirection(const Vector3 & direction)
{
	this->direction = direction.GetNormal();
}
