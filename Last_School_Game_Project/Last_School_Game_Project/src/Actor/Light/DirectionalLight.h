#pragma once
#include "Actor/Light/ILight.h"

/**
 * @file DirectionalLight.h
 * @brief ���s������`�t�@�C��
 * @author ���]
 * @date 2017/9/9
 */

#include"Math/Vector3/Vector3.h"

 /*! @class DirectionalLight
 *   @brief ���s����
 */
class DirectionalLight : public ILight
{
public:
	DirectionalLight(const Vector3& direction);
	~DirectionalLight();

private:
	virtual Vector3 GetPosition() const override;
	virtual Vector3 GetDirection() const override;
	virtual void SetPosition(const Vector3& position) override;
	virtual void SetDirection(const Vector3& direction) override;
private:
	Vector3 position;
	Vector3 direction;
};

