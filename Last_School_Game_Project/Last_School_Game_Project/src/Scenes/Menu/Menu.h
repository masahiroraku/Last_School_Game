#pragma once

/**
* @file Menu.h
* @brief ���j���[�V�[����`�t�@�C��
* @author ���]
* @date 2017/10/27
*/


#include"Scenes/Base/IScene.h"
#include"World/IWorld.h"
#include"World/WorldPtr.h"

class Renderer;
enum class EventMessage;

/*! @class Menu
*   @brief ���j���[�V�[����`�N���X
*/
class Menu : public IScene {
public:
	/**
	* @brief �R���X�g���N�^
	* @param world ���[���h�|�C���^
	*/
	explicit Menu(WorldPtr& world);
	/**
	* @brief �f�X�g���N�^
	*/
	virtual ~Menu();
	/**
	* @brief �A�Z�b�g��ǂݍ���
	*/
	virtual void LoadAssets() override;
	/**
	* @brief ������
	*/
	virtual void Initialize() override;
	/**
	* @brief �X�V
	* @param deltaTime �P�b
	*/
	virtual void Update(float deltaTime)override;
	/**
	* @brief �`��
	*/
	virtual void Draw() const override;
	/**
	* @brief �V�[�����I��������
	* @return [true �I��] : [false �܂��I�����Ă��Ȃ�]
	*/
	virtual bool IsEnd() const override;
	/**
	* @brief ���Ɉړ�����V�[�����擾
	* @return ���Ɉړ�����V�[��
	*/
	virtual Scene Next()const override;
	/**
	* @brief �I��
	*/
	virtual void Finalize() override;
	/**
	* @brief �t�F�[�h����
	* @param alpha �A���t�@�l
	*/
	virtual void DrawFade(float alpha) const override;

private:
	/**
	* @brief �C�x���g���b�Z�[�W���󂯎��
	* @param message �o�^�����C�x���g���b�Z�[�W
	* @param param �C�x���g�ƈꏏ�ɑ���ϐ�
	*/
	void HandleMessage(EventMessage message, void* param);

private:
	//!���[���h�|�C���^
	WorldPtr world;
	//!�`��N���X
	Renderer* renderer;
	//!�V�[�����I������������p
	bool isEnd_;
};
