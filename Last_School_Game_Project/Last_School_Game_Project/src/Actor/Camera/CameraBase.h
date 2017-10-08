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
	/// �J�����̎p���s����擾
	/// </summary>
	/// <returns>�J�����̎p���s��</returns>
	virtual Matrix4 GetMatrix() override;
	/// <summary>
	/// ���ڂ���A�N�^�[��ݒ�
	/// </summary>
	/// <param name="target">���ڂ���A�N�^�[</param>
	virtual void SetTarget(const Actor& target) override;
	/// <summary>
	/// �w�肵�����W���J�����ɉf���Ă��邩�ǂ����擾����
	/// </summary>
	/// <param name="position">�f���Ă��邩�m�肽�����W</param>
	/// <returns>
	/// �f���Ă���ꍇ�͐^
	/// </returns>
	virtual bool IsInsideCameraView(const Vector3& position) const override;

	/// <summary>
	/// �J�����ɉf���Ă���A�N�^�[�����������X�g���擾����
	/// </summary>
	/// <param name="group">�擾�������A�N�^�[</param>
	/// <returns>
	/// �J�����ɉf���Ă���A�N�^�[�����������X�g
	/// </returns>
	virtual std::list<ActorPtr> IsInsideCameraViewActors(ActorGroup group) const override;




	/// <summary>
	/// �X�V
	/// </summary>
	/// <param name="deltaTime">deltaTime</param>
	void Update(float deltaTime);
	/// <summary>
	/// �`��
	/// </summary>
	/// <param name="renderer">renderer</param>
	void Draw(Renderer& renderer);


	/// <summary>
	/// �C�x���g���b�Z�[�W���󂯎��
	/// </summary>
	/// <param name="message">�C�x���g���b�Z�[�W</param>
	/// <param name="param">���b�Z�[�W�ƈꏏ�Ɏ󂯎��l</param>
	void HandleMessage(EventMessage message, void* param = nullptr);

protected:
	virtual void OnUpdate(float deltaTime);
	virtual void OnDraw(Renderer& renderer);
	virtual void OnMessage(EventMessage message, void* param);

protected:
	//���[���h
	IWorld* world;
	//�J�����̍s��
	Matrix4 matrix;
	//���ڂ���A�N�^�[
	const Actor* target;
	//�J�����̍��W
	Vector3 position;
	//!��]�����̍s��
	Matrix4 pivot;
};