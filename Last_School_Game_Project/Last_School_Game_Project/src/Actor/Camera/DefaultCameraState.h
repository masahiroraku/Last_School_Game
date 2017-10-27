#pragma once

#include"Actor/State/IState.h"
#include"FreeLookAtCamera.h"

class DefaultCameraState : public IState {
public:
	DefaultCameraState(Matrix4& matrix, Vector3& lookat, const Actor& target);
	~DefaultCameraState();

	/// <summary>
	/// ������
	/// </summary>
	virtual void Initialize() override;
	/// <summary>
	/// ��Ԃ̍X�V
	/// </summary>
	/// <param name="deltaTime">�P�t���[��</param>
	virtual void Update(float deltaTime) override;
	/// <summary>
	/// ��Ԃ̏I��
	/// </summary>
	virtual void Finalize() override;

	/// <summary>
	/// �A�N�^�[�̃��b�Z�[�W���󂯎��
	/// </summary>
	/// <param name="message">���b�Z�[�W�̎��</param>
	/// <param name="param">���b�Z�[�W�ƈꏏ�ɑ�������</param>
	virtual void HandleMessage(EventMessage message, void* param) override;
	/// <summary>
	/// ���̏�ԂɑJ�ڂ��邩�ǂ���
	/// </summary>
	/// <returns>
	/// [true:�J�ڂ��� false:�J�ڂ��Ȃ�]
	/// </returns>
	virtual bool IsEnd() const override;
	/// <summary>
	/// ���ɑJ�ڂ����Ԃ��擾����
	/// </summary>
	/// <returns>���̏��</returns>
	virtual int GetNextState() const override;
	/// <summary>
	/// ���ɍĐ�����A�j���[�V�����ԍ����擾����
	/// </summary>
	/// <returns>���ɍĐ�����A�j���[�V�����ԍ�</returns>
	virtual int GetNextAnime() const override;
private:
	void RotationMovement(float deltaTime);
private:
	Matrix4& matrix;
	Vector3& lookat;
	const Actor& target;

	Vector3 localPosition;
	Vector3 position;

	const float moveSpeed;
	const float turnSpeed;
	const float tiltMax;
	const float tiltMin;
	float yawTotal;
	float pitchTotal;
	FreeLookAtCamera::State nextState;
	bool isEnd;
};