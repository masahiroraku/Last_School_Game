#pragma once


class Renderer;
class Vector2;

/**
* @file HitPoint.h
* @brief �L�����N�^�[�̃q�b�g�|�C���g��`�t�@�C��
* @author ���]
* @date Unknown
*/

/*! @class HitPoint
*   @brief �L�����N�^�[�̃q�b�g�|�C���g
*/
class HitPoint {
public:	
	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	/// <param name="maxHitPoint">�ő�HP</param>
	explicit HitPoint(int maxHitPoint);	
	/// <summary>
	/// �f�X�g���N�^
	/// </summary>
	~HitPoint();	
	/// <summary>
	/// ������
	/// </summary>
	void Initialize();	
	/// <summary>
	/// HP�𑝂₷
	/// </summary>
	/// <param name="value">�l</param>
	void AddValue(int value);	
	/// <summary>
	/// �ő�HP��ݒ肷��
	/// </summary>
	/// <param name="maxValue">�ő�HP</param>
	void SetMaxHP(int maxValue);	
	/// <summary>
	/// ���݂�HP���擾����
	/// </summary>
	/// <returns>���݂�HP</returns>
	int GetHP()const;	
	/// <summary>
	/// ���݂̍ő�HP���擾����
	/// </summary>
	/// <returns>���݂̍ő�HP</returns>
	int GetMaxHP()const;	
	/// <summary>
	/// ���S�������ǂ����@HP��0�ɂȂ�����
	/// </summary>
	/// <returns>
	/// [true ���S���� : false �܂������Ă���]
	/// </returns>
	bool IsDead()const;

private:
	//!���݂̍ő�HP
	int maxHitPoint;
	//!���݂�HP
	int hitPoint;
};