#pragma once

#include"CameraBase.h"
#include"Mesh/SimpleMesh/SimpleMesh.h"
/************************************************************
* File Name	: TitleCamera.h
* Description	: タイトル用のカメラクラス
*																Date		:	2017/03/23
*															  Author	:	阿曽
*************************************************************/
class TitleCamera : public CameraBase {
public:
	/// <summary>
	/// コンストラクタ
	/// </summary>
	/// <param name="world">world</param>
	explicit TitleCamera(IWorld& world);
	~TitleCamera();

	virtual void OnUpdate(float deltaTime) override;
	virtual void OnDraw(Renderer& renderer)override;
	virtual void OnMessage(EventMessage message, void* param)override;

private:
	float angle;

};
