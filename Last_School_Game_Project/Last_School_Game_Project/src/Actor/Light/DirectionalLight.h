#pragma once
#include "Actor/Light/ILight.h"

/**
 * @file DirectionalLight.h
 * @brief 平行光源定義ファイル
 * @author 阿曽
 * @date 2017/9/9
 */

#include"Math/Vector3/Vector3.h"

 /*! @class DirectionalLight
 *   @brief 平行光源
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

