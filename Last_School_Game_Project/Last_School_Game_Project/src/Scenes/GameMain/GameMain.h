#pragma once

/**
 * @file GameMainScene.h
 * @brief �Q�[�����C���V�[����`�t�@�C��
 * @author ���]
 * @date 2017/3/23
*/


#include "Scenes/Base/IScene.h"
#include"World/IWorld.h"
#include"World/WorldPtr.h"
#include"Pause/Pause.h"
#include"Utility/Timer/Timer.h"

class Renderer;
enum class EventMessage;

/*! @class GameMainScene
 *   @brief  �Q�[�����C���V�[��
 */
class GameMain : public IScene {
public:
	/**
	* @brief �R���X�g���N�^
	* @param world ���[���h�|�C���^
	*/
	explicit GameMain(WorldPtr& world);
	/**
	* @brief �f�X�g���N�^
	*/
	virtual ~GameMain();
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

private:
	//!���[���h�|�C���^
	WorldPtr world;
	//!�`��N���X
	Renderer* renderer;
	//!�V�[�����I������������p
	bool isEnd_;
	//!�|�[�Y��������p
	bool pause;
	//!�|�[�Y�V�[��
	Pause pauseScene;
};
