#pragma once

/**
 * @file Sound.h
 * @brief ���y�Ǘ��N���X��`�t�@�C��
 * @author ��|
 * @date Unknown
 */

#include"Utility/Assets.h"
#include <unordered_map>


/*! @class Sound
*   @brief ���y�Ǘ��N���X
*/
class Sound
{
private:	
	/// <summary>
	/// �R���X�g���N�^<see cref="Sound"/>
	/// </summary>
	Sound();	
	/// <summary>
	/// �f�X�g���N�^
	/// </summary>
	~Sound();
public:
	 /// <summary>
	 /// ���y�Ǘ��N���X���擾
	 /// </summary>
	 /// <returns>���y�Ǘ��N���X</returns>
	static Sound& GetInstance();
	/// <summary>
	 /// ���y���\�[�X��ǂݍ���
	 /// </summary>
	 /// <param name="id">�o�^�������O</param>
	 /// <param name="fileName">�ǂݍ��މ��y�t�@�C���� wav mp3</param>
	void LoadSound(Assets::Sound id, const std::string& fileName);
	/// <summary>
	/// SE���Đ�
	/// </summary>
	/// <param name="id">�o�^�������O</param>
	/// <param name="volume">����</param>
	void PlaySE(Assets::Sound id, float volume = 1.0f);	
	/// <summary>
	/// BGM���Đ�
	/// </summary>
	/// <param name="id">�o�^�������O</param>
	/// <param name="volume">����</param>
	void PlayBGM(Assets::Sound id, float volume = 1.0f);
	/// <summary>
	/// ���y�̐ݒ�����Đ�
	/// </summary>
	/// <param name="id">�o�^�������O</param>
	/// <param name="mPlayType">Dxlib����`�����萔�@DX_PLAYTYPE_LOOP=���[�v�Đ��@DX_PLAYTYPE_BACKBIT=1��Đ�</param>
	/// <param name="volume">����</param>
	void PlaySounds(Assets::Sound id, int mPlayType, float volume = 1.0f);
	 /// <summary>
	 /// BGM���~�߂�
	 /// </summary>
	 /// <param name="id">��`�������O</param>
	void StopBGM(Assets::Sound id);
	 /// <summary>
	 /// ���̃n���h�����擾
	 /// </summary>
	 /// <param name="id">�o�^�������O</param>
	 /// <returns>���̃n���h��</returns>
	int GetSoundHandle(Assets::Sound id);
	 /// <summary>
	 /// �o�^���������\�[�X���폜
	 /// </summary>
	void SoundClear();


private:
	//!��`�������y�ƃT�E���h�n���h������ꂽ�R���e�i
	std::unordered_map<Assets::Sound, int> mSoundHandle;
};

