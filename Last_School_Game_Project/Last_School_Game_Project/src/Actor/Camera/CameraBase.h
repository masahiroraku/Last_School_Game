#pragma once

#include"ICamera.h"
#include"Math/Matrix4/Matrix4.h"
class IWorld;
class Renderer;
enum class EventMessage;

class CameraBase : public ICamera {
public:
	explicit CameraBase(IWorld& world);
	virtual ~CameraBase();

	/// <summary>
	/// カメラの姿勢行列を取得
	/// </summary>
	/// <returns>カメラの姿勢行列</returns>
	virtual Matrix4 GetMatrix() override;
	/// <summary>
	/// 注目するアクターを設定
	/// </summary>
	/// <param name="target">注目するアクター</param>
	virtual void SetTarget(const Actor& target) override;
	/// <summary>
	/// 指定した座標がカメラに映っているかどうか取得する
	/// </summary>
	/// <param name="position">映っているか知りたい座標</param>
	/// <returns>
	/// 映っている場合は真
	/// </returns>
	virtual bool IsInsideCameraView(const Vector3& position) const override;

	/// <summary>
	/// カメラに映っているアクターが入ったリストを取得する
	/// </summary>
	/// <param name="group">取得したいアクター</param>
	/// <returns>
	/// カメラに映っているアクターが入ったリスト
	/// </returns>
	virtual std::list<ActorPtr> IsInsideCameraViewActors(ActorGroup group) const override;




	/// <summary>
	/// 更新
	/// </summary>
	/// <param name="deltaTime">deltaTime</param>
	void Update(float deltaTime);
	/// <summary>
	/// 描画
	/// </summary>
	/// <param name="renderer">renderer</param>
	void Draw(Renderer& renderer);


	/// <summary>
	/// イベントメッセージを受け取る
	/// </summary>
	/// <param name="message">イベントメッセージ</param>
	/// <param name="param">メッセージと一緒に受け取る値</param>
	void HandleMessage(EventMessage message, void* param = nullptr);

protected:
	virtual void OnUpdate(float deltaTime);
	virtual void OnDraw(Renderer& renderer);
	virtual void OnMessage(EventMessage message, void* param);

protected:
	//ワールド
	IWorld* world;
	//カメラの行列
	Matrix4 matrix;
	//注目するアクター
	const Actor* target;
	//カメラの座標
	Vector3 position;
	//!回転する基準の行列
	Matrix4 pivot;
};