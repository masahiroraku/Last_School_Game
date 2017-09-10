#pragma once
#include "Actor/State/IState.h"
#include"Actor/Base/Actor.h"
class ICamera;
class Move : public IState
{
public:
	Move(Actor& player, ICamera& camera);
	~Move();
private:
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

	void LookAtFront(const Vector3& velocity);

private:
	bool isEnd;
	ICamera& camera;
	Actor& player;
	int state;
	const float WalkSpeed;
	const float RunSpeed;
	float speed;
	Vector3 position;
};

