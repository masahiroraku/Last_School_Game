#pragma once

/**
* @file Pause.h
* @brief �|�[�Y�̏������܂Ƃ߂��N���X��`�t�@�C��
* @author ���]
* @date 2017/3/23
*/


class Renderer;
enum class EventMessage;
enum class Scene;
class IWorld;
#include"Utility/Assets.h"
#include"Math/Vector2/Vector2.h"
#include"Utility/Color/Color.h"
#include<array>

/*! @class Pause
*   @brief  �|�[�Y
*/
class Pause {
public:
	/*! @struct PauseItem
	 * @brief  �|�[�Y�ŕ\����������܂Ƃ߂��\����
	 */
	struct PauseItem {
		//!��`�����e�N�X�`��
		Assets::Texture texture;
		//!���W
		Vector2 position;
		//!���S���W
		Vector2 center;
		//!��ԂŎg���傫����
		float t_scale;
		//!�F
		Color color;

		/**
		 * @brief �f�t�H���g�R���X�g���N�^
		 */
		PauseItem(){}
		/**
		* @brief �R���X�g���N�^
		* @param texture ��`�����e�N�X�`��
		* @param position ���W
		* @param center ���S���W
		* @param t_scale ��ԂŎg���傫����
		* @param color �F
		*/
		PauseItem(Assets::Texture texture, const Vector2& position = Vector2::Zero, const Vector2& center = Vector2(128,27), float t_scale = 0.0f, const Color& color = Color::White)
			: texture(texture)
			, position(position)
			, center(center)
			, t_scale(t_scale)
			, color(color){

		}

	};

public:	
	/**
	 * @brief �R���X�g���N�^
	 * @param world ���[���h�|�C���^
	 */
	explicit Pause(IWorld& world);
	/**
	* @brief �f�X�g���N�^
	*/
	~Pause();

	/**
	* @brief ������
	*/
	void Initialize();
	/**
	* @brief �X�V
	* @param deltaTime �P�b
	*/
	void Update(float deltaTime);
	/**
	* @brief �`��
	* @param renderer �`��N���X
	*/
	void Draw(Renderer& renderer)const;
	/**
	* @brief �I��
	*/
	void Finalize();
	/**
	* @brief �C�x���g���b�Z�[�W���󂯎��
	* @param message �o�^�����C�x���g���b�Z�[�W
	* @param param �C�x���g�ƈꏏ�ɑ���ϐ�
	*/
	void HandleMessage(EventMessage message, void* param);

	/**
	* @brief �I�񂾃V�[�����擾
	* @return �I�񂾃V�[��
	*/
	Scene GetSelectScene() const;
	/**
	* @brief �V�[�����I������������
	* @return [true �I������] : [false �܂��I�����Ă��Ȃ�]
	*/
	bool IsEnd() const;

private:
	/**
	* @enum SelectContent
	* �|�[�Y�̍��ڒ�`
	*/
	enum SelectContent {
		//!�|�[�Y����߂�
		BackToGame_ = 0,
		//!������@
		Manual_,
		//!�Q�[����������x��蒼��
		Continue_,
		//!�^�C�g���ֈڍs
		Title_,
		//�ő吔
		Max_Num
	};


private:

	//!���[���h�|�C���^
	IWorld& world;
	//!�I�񂾃V�[��
	Scene selectScene;
	//!�V�[�����I������������p
	bool isEnd;
	//!�I��ł��鍀�ځi�V�[���j
	int selectContaint;
	//!1�t���[���O�̃R���g���[���[�̃X�e�B�b�N����
	float prevInput;
	//!���݂̃R���g���[���[�̃X�e�B�b�N����
	float curInput;
	//!�|�[�Y�ŕ\����������܂Ƃ߂��z��
	std::array<PauseItem, SelectContent::Max_Num> pauseItems;
};