#pragma once

/**
 * @file Renderer.h
 * @brief �`��֌W���܂Ƃ߂��N���X
 * @author ���]
 * @date 2015/12/7
 */

#include<string>
#include"Math/Matrix4/Matrix4.h"
#include<unordered_map>
#include"Math/Vector2/Vector2.h"
#include"Utility/Rect/Rect.h"
#include"Utility/Color/Color.h"
#include"ModelInfo.h"
#include"Utility/Assets.h"

/*! @class Renderer
 *  @brief  �`��N���X
 */
class Renderer {
private:
	/**
	 * @brief �R���X�g���N�^
	 */
	Renderer();
	/**
	* @brief �f�X�g���N�^
	*/
	~Renderer();
public:	
	/**
	 * @brief Renderer�̃|�C���^���擾
	 * @return Renderer�̃|�C���^
	 */
	static Renderer* GetInstance();
	/**
	 * @brief �e�N�X�`����ǂݍ���
	 * @param id �o�^���閼�O
	 * @param fileName �ǂݍ��ރt�@�C����
	 */
	void LoadTexture(Assets::Texture id, const std::string& fileName);	
	/**
	 * @brief �t�H���g��ǂݍ���
	 * @param id �o�^���閼�O
	 * @param fileName �ǂݍ��ރt�@�C����
	 * @param edgeSize �����̉��̑���
	 */
	void LoadFont(Assets::Font id, const std::string& fileName, int edgeSize = 0);
	/**
	 * @brief 3D���f����ǂݍ���
	 * @param id �o�^���閼�O
	 * @param fileName �ǂݍ��ރt�@�C����
	 */
	void Load3DModel(Assets::Model id, const std::string& fileName);
	/**
	 * @brief �A�j���[�V������ǂݍ���
	 * @param id �o�^���閼�O
	 * @param fileName �ǂݍ��ރt�@�C����
	 */
	void LoadAnimation(Assets::Animation id, const std::string& fileName);
	/**
	 * @brief �G�t�F�N�g��ǂݍ���
	 * @param id �o�^���閼�O
	 * @param fileName �ǂݍ��ރt�@�C����
	 */
	void LoadEffect(Assets::Effect id, const std::string& fileName);
	/**
	 * @brief �e�N�X�`������ʂɕ`��
	 * @param id �o�^�������O
	 * @param position �`�悷����W
	 * @param center �e�N�X�`���̒��S�_
	 * @param scale �e�N�X�`���̑傫��
	 * @param angle �e�N�X�`���̉�]�p�x�i�x���@�j
	 * @param color �e�N�X�`���̐F
	 */
	void DrawTexture(Assets::Texture id, const Vector2& position = Vector2(0, 0), const Vector2& center = Vector2(0, 0), const Vector2& scale = Vector2(1, 1), float angle = 0.0f, const Color& color = Color::White);
	/**
	* @brief ��`����ʂɕ`��
	* @param id �o�^�������O
	* @param position �`�悷����W
	* @param rect �؂���͈�
	* @param alpha �A���t�@�l
	*/
	void DrawRectangle(Assets::Texture id, const Vector2& position = Vector2(0, 0), const Rect& rect = Rect(0, 0, 1, 1), float alpha = 1.0f);
	/**
	* @brief �t�H���g����ʂɕ`��
	* @param id �o�^�������O
	* @param text �\�����镶����
	* @param position �`�悷����W
	* @param color �e�N�X�`���̐F
	*/
	void DrawFont(Assets::Font id, const std::string& text, const Vector2& position, const Color& color = Color::White);
	/**
	* @brief �摜���g���Đ�������ʂɕ`�悷��
	* @param id �o�^�������O
	* @param position ���W
	* @param number ���l
	* @param width �����P������̉���
	* @param height �����P������̏c��
	* @param digit ����
	* @param fill �]�����������Ŗ��߂邩
	*/
	void DrawNumber(Assets::Texture id, const Vector2& position, int number, int width, int height, int digit = 0, char fill = '0');
	/**
	* @brief �r���{�[�h��`��
	* @param id �o�^�������O
	* @param position ���W
	* @param center ���S���W
	* @param scale �傫��
	* @param angle ��]�p�x�i�x���@�j
	* @param color �F
	*/
	void DrawBillboard(Assets::Texture id, const Vector3& position, const Vector2& center = Vector2::Zero, float scale = 1.0f, float angle = 0.0f, const Color& color = Color::White);	
	/**
	* @brief �r���{�[�h���g���Đ�������ʂɕ`�悷��
	* @param id �o�^�������O
	* @param position ���W
	* @param number ���S���W
	* @param width �����P������̉���
	* @param height �����P������̉���
	* @param alpha �A���t�@�l
	*/
	void DrawNumberBillboard(Assets::Texture id, const Vector3& position, int number, int width, int height, float alpha = 1.0f);	
	/**
	* @brief �RD�G�t�F�N�g��\��
	* @param id �o�^�������O
	* @return �Đ����̃G�t�F�N�g�̃n���h��
	*/
	int DrawEffect3D(Assets::Effect id);
	/**
	* @brief �RD�G�t�F�N�g�̍��W��ݒ�
	* @param playEffectHandle �Đ����̃G�t�F�N�g�n���h��
	* @param position ���W
	*/
	void SetEffect3DPosition(int playEffectHandle, const Vector3& position);
	/**
	* @brief �RD�G�t�F�N�g�̑傫����ݒ�
	* @param playEffectHandle �Đ����̃G�t�F�N�g�n���h��
	* @param scale �傫��
	*/
	void SetEffect3DScele(int playEffectHandle, const Vector3& scale);
	/**
	* @brief �RD�G�t�F�N�g�̉�]�p�x��ݒ�
	* @param playEffectHandle �Đ����̃G�t�F�N�g�n���h��
	* @param x X���p�x(�x���@)
	* @param y Y���p�x(�x���@)
	* @param z Z���p�x(�x���@)
	*/
	void SetEffect3DRotate(int playEffectHandle, float x, float y, float z);
	/**
	* @brief �RD�G�t�F�N�g�̎p���s���ݒ�
	* @param playEffectHandle �Đ����̃G�t�F�N�g�n���h��
	* @param matrix �p���s��
	*/
	void SetEffect3DMatrix(int playEffectHandle, const Matrix4& matrix);
	/**
	* @brief �RD���f���̎p���s���ݒ�
	* @param modelHandle �RD���f���̃n���h��
	* @param matrix �p���s��
	*/
	void SetMatrix3DModel(int modelHandle, const Matrix4& matrix);
	/**
	* @brief �RD���f����`��
	* @param modelHandle �RD���f���̃n���h��
	*/
	void Draw3DModel(int modelHandle);
	/**
	* @brief �RD���f����`��
	* @param modelHandle �RD���f���̃n���h��
	* @param matrix �p���s��
	*/
	void Draw3DModel(int modelHandle, const Matrix4& matrix);	
	/**
	* @brief �RD���f���ɃA�j���[�V�������o�C���h����
	* @param info ���f�����
	* @param animeIndex �Đ�����A�j���[�V�����̔ԍ�
	* @param animeTime �Đ�����
	*/
	void BindAnimation(ModelInfo& info, int animeIndex, float animeTime);
	/**
	* @brief �RD���f���ɃA�j���[�V�����u�����h��K�p������i�؂�ւ������炩�ɂȂ�j
	* @param info ���f�����
	* @param animeIndex �Đ�����A�j���[�V�����̔ԍ�
	* @param animeTime �Đ�����
	*/
	void BindAnimationBlend(ModelInfo& info, int animeIndex, float animeTime);
	/**
	* @brief �w�肵���{�[������㉺�ʁX�̃A�j���[�V������K��������
	* @param info ���f�����
	* @param animeIndex �Đ�����A�j���[�V�����̔ԍ�
	* @param animeTime00 �Е��̍Đ�����
	* @param animeTime01 �����Е��̍Đ�����
	* @param boneIndex ��������{�[��
	*/
	void BindAnimationBlendToBone(ModelInfo& info, int animeIndex, float animeTime00, float animeTime01, int boneIndex);	
	/**
	* @brief �A�j���[�V�����̍Đ����Ԃ��擾����
	* @param animationHandle �A�j���[�V�����̃n���h��
	* @param animeIndex �A�j���[�V�����̔ԍ�
	* @return �A�j���[�V�����̍Đ�����
	*/
	float GetAnimationTime(int animationHandle, int animeIndex);
	/**
	* @brief �A�j���[�V�����̃n���h�����擾
	* @param id �o�^�������O
	* @return �A�j���[�V�����̃n���h��
	*/
	int GetAnimationHandle(Assets::Animation id);
	/**
	* @brief �RD���f���̃n���h�����擾
	* @param id �o�^�������O
	* @return �RD���f���̃n���h��
	*/
	int GetModelHandle(Assets::Model id);
	/**
	* @brief �����������f���̃n���h�����擾
	* @param id �o�^�������O
	* @return �����������f���̃n���h��
	*/
	int GetDeplicateModelHandle(Assets::Model id);
	/**
	* @brief �G�t�F�N�g�̃n���h�����擾
	* @param id �o�^�������O
	* @return �G�t�F�N�g�̃n���h��
	*/
	int GetEffectHandle(Assets::Effect id);
	/**
	* @brief ���f�����폜
	* @param modelHandle ���f���̃n���h��
	*/
	void DeleteModel(int modelHandle);
	/**
	* @brief �{�[���̃��[���h���W���擾
	* @param modelHandle ���f���̃n���h��
	* @param boneIndex �{�[���ԍ�
	* @return �{�[���̃��[���h���W
	*/
	Vector3 GetBonePosition(int modelHandle, int boneIndex);
	/**
	* @brief �{�[���̃��[�J���s����擾
	* @param modelHandle ���f���̃n���h��
	* @param boneIndex �{�[���ԍ�
	* @return �{�[���̃��[�J���s��
	*/
	Matrix4 GetBoneLocalMatrix(int modelHandle, int boneIndex);
	/**
	* @brief �{�[���̃��[���h�s����擾
	* @param modelHandle ���f���̃n���h��
	* @param boneIndex �{�[���ԍ�
	* @return �{�[���̃��[���h�s��
	*/
	Matrix4 GetBoneLocalWorldMatrix(int modelHandle, int boneIndex);
	/**
	* @brief �f�B�t���[�Y�}�b�v�Ƃ��Ďg�p����Ă���e�N�X�`���ԍ����擾����
	* @param modelHandle ���f����ID�E�n���h��
	* @param index �}�e���A���̔ԍ�
	* @return �f�B�t���[�Y�}�b�v�Ƃ��Ďg�p����Ă���e�N�X�`���ԍ�
	*/
	int GetModelTextureIndex(int modelHandle, int index);
	/**
	* @brief ���f���̃e�N�X�`����ύX����
	* @param modelHandle ���f����ID�E�n���h��
	* @param id �ύX����e�N�X�`���̖��O
	* @param textureIndex �f�B�t���[�Y�}�b�v�Ƃ��Ďg�p����Ă���e�N�X�`���ԍ�
	*/
	void ChangeModelTexture(int modelHandle, Assets::Texture id, int textureIndex);	
	/**
	 * @brief �S���\�[�X�̍폜
	 */
	void Clear();
	/**
	* @brief �G�t�F�N�g���Đ������ǂ����擾����
	* @param �G�t�F�N�g�̃n���h��
	* @return �Đ������ǂ���[true �Đ���: false �Đ����Ă��Ȃ�]
	*/
	bool IsPlayEffect3D(int effectHandle);

private:
	//!���f�������Ǘ�����R���e�i
	std::unordered_map<Assets::Model, int> models;
	//!�A�j���[�V�������Ǘ�����R���e�i
	std::unordered_map<Assets::Animation, int> animations;
	//!�e�N�X�`�����Ǘ�����R���e�i
	std::unordered_map<Assets::Texture, int> textures;
	//!�t�H���g���Ǘ�����R���e�i
	std::unordered_map<Assets::Font, int> fonts;
	//!�G�t�F�N�g���Ǘ�����R���e�i
	std::unordered_map<Assets::Effect, int> effects;
private:
	//!��Ԃ��鎞��
	static const float LerpTime;
};