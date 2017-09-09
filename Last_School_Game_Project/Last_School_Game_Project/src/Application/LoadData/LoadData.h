#pragma once

#include"Utility/CSVLoader/CSVLoader.h"
#include"LoadDataKey.h"
#include"LoadDataValue.h"
#include<unordered_map>
#include<sstream>
#include<string>

/**
 * @file LoadData.h
 * @brief �Q�[���Ŏg���ϐ��̏����l�t�@�C����ǂݍ��ރN���X��`�t�@�C��
 * @author ���]
 * @date 2017/4/1
 */

 /*! @class LoadData
 *   @brief  �Q�[���Ŏg���ϐ��̏����l�t�@�C����ǂݍ��ރN���X
 */
class LoadData {
private:	
	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	LoadData();	
	/// <summary>
	/// �f�X�g���N�^
	/// </summary>
	~LoadData();

private:	
	/// <summary>
	/// �擾����L�����f�[�^��o�^
	/// </summary>
	void Regist();	
	/// <summary>
	/// �ǂݍ��ރt�@�C����o�^
	/// </summary>
	void RegistLoadFile();

public:	
	/// <summary>
	/// �N���X�̎Q�Ƃ��擾
	/// </summary>
	/// <returns>���̃N���X�̎Q��</returns>
	static LoadData& GetInstance();
	/// <summary>
	/// �t�@�C����ǂݍ���
	/// </summary>
	void Load();

private:
	//!�ǂݍ��񂾃t�@�C��������z��
	std::unordered_map<LoadDataKey, CSVData> datas;
	//!�ǂݍ��񂾃t�@�C�����ǂ��̃L�����ɓ���邩������z��@TODO:���ꂢ��Ȃ�����
	std::unordered_map<std::string, LoadDataKey> registLoadDatas;
	//!1�s�ڂ͐������Ȃ̂łQ�s�ڂ���ǂݍ���
	const int LoadableRaw = 2;

public:

	/// <summary>
	/// CSV�f�[�^����e�f�[�^�̏����l���擾����
	/// </summary>
	/// <param name="key">LoadDataKey�@�擾�������f�[�^�̃t�@�C��</param>
	/// <param name="value">LoadDataValue�@�擾�������f�[�^�̏����l</param>
	/// <returns>�擾�������f�[�^�̏����l</returns>
	template<class T, class Value>
	T GetData(LoadDataKey key, Value value) {
		T dst;
		//�ǂݍ��񂾃t�@�C�����當������擾
		std::string src = datas.at(key).at(static_cast<int>(value)).at(LoadableRaw);
		std::istringstream(src) >> dst;
		return dst;
	}

	/// <summary>
	/// �v���C���[�̏������f�[�^���擾
	/// </summary>
	/// <param name="value">�擾�����������l</param>
	/// <returns>�����l</returns>
	template<class T, class Value>
	T GetData_Player(Value value) {
		return GetData(LoadDataKey::Player, value);
	}
	/// <summary>
	/// �G�̏������f�[�^���擾
	/// </summary>
	/// <param name="value">�擾�����������l</param>
	/// <returns>�����l</returns>
	template<class T, class Value>
	T GetData_Enemy(Value value) {
		return GetData(LoadDataKey::Enemy, value);
	}
	/// <summary>
	/// ����̏������f�[�^���擾
	/// </summary>
	/// <param name="value">�擾�����������l</param>
	/// <returns>�����l</returns>
	template<class T, class Value>
	T GetData_Weapon(Value value) {
		return GetData(LoadDataKey::Weapon, value);
	}

};

