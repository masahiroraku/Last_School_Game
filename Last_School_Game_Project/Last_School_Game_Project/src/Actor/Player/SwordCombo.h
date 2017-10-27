#pragma once

#include"Actor/State/IState.h"
#include"Actor/Player/Player.h"

class SwordCombo : public IState
{
public:
	struct ComboData {
		int nextIndex;
		Player::Anime nextAnime;
		float beginCollideTime;
		float endCollideTime;
		ComboData(int nextIndex, Player::Anime nextAnime, float beginCollideTime, float endCollideTime) 
			: nextIndex(nextIndex)
			, nextAnime(nextAnime)
			, beginCollideTime(beginCollideTime)
			, endCollideTime(endCollideTime)
		{

		}
	};
public:
	SwordCombo(const ComboData& comboData, Actor& swordPtr, SkinningMesh& meshPtr);
	~SwordCombo();
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
	bool GetCollisionTime() const;

private:
	bool isEnd;
	ComboData comboData;
	Actor& swordPtr;
	SkinningMesh& meshPtr;
	bool isNext;
};

