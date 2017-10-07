#pragma once

#include "Actor/State/IState.h"
#include "Mesh/SkinningMesh/SkinningMesh.h"
#include"BoarDragon.h"

class BoarDragon_Attack : public IState {
public:
	BoarDragon_Attack(IWorld& world, Actor& bossPtr, SkinningMesh& meshPtr);
	~BoarDragon_Attack();
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
	enum class AttackType {
		Bite,
		Rush,
		Bomb
	};
private:
	IWorld& world;
	Actor& bossPtr;
	SkinningMesh& meshPtr;
	bool isEnd;
	BoarDragon::State state;
	BoarDragon::Anime anime;
	AttackType attackType;
};

