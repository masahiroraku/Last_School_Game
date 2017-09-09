#pragma once

/**
 * @file LoadDataValue.h
 * @brief �Q�[���Ŏg���ϐ��̏����l�̗v�f��`
 * @author ���]
 * @date 2017/4/1
 */

 /// <summary>
 /// �Q�[���Ŏg���ϐ��̏����l�̗v�f
 /// </summary>
namespace LoadDataValue {
	/**
	 * @enum PlayerData
	 * �v���C���[�̕ϐ��̏����l��`
	 */
	enum class PlayerData {
		//!0�Ԗڒ����p
		None,
		//!����̃{�[���ԍ�
		LeftHand,
		//!�E��̃{�[���ԍ�
		RightHand,
		//!�E���̃{�[���ԍ�
		RightFoot,
		//!�m�b�N�o�b�N���x
		KnockBackSpeed,
		//!�m�b�N�o�b�N���鋗��
		KnockBackDistance,
		//!�����蔻��̃J�v�Z���̎n�_���W
		CollideCapsule_DownPosition,
		//!�����蔻��̃J�v�Z���̏I�_���W
		CollideCapsule_UpPosition,
		//!�����蔻��̃J�v�Z���̔��a
		CollideCapsule_Radius,
		//!�q�b�g�|�C���g
		HP,
		//!��������
		WalkSpeed,
		//!�_���[�W���󂯂鎞��
		DamageTimer,
		//!�p���`�U��0�Ԗڂ̂����蔻��J�n����
		Punch00_BeginTime,
		//!�p���`�U��0�Ԗڂ̂����蔻��I������
		Punch00_EndTime,
		//!�p���`�U��1�Ԗڂ̂����蔻��J�n����
		Punch01_BeginTime,
		//!�p���`�U��1�Ԗڂ̂����蔻��I������
		Punch01_EndTime,
		//!�p���`�U��2�Ԗڂ̂����蔻��J�n����
		Punch02_BeginTime,
		//!�p���`�U��2�Ԗڂ̂����蔻��I������
		Punch02_EndTime,
		//!�p���`�U��3�Ԗڂ̂����蔻��J�n����
		Punch03_BeginTime,
		//!�p���`�U��3�Ԗڂ̂����蔻��I������
		Punch03_EndTime,
		//!�p���`�U��4�Ԗڂ̂����蔻��J�n����
		Punch04_BeginTime,
		//!�p���`�U��4�Ԗڂ̂����蔻��I������
		Punch04_EndTime,
		//!�L�b�N�U��0�Ԗڂ̂����蔻��J�n����
		Kick_BeginTime,
		//!�L�b�N�U��0�Ԗڂ̂����蔻��I������
		Kick_EndTime,
	};
	/**
	 * @enum EnemyData
	 * �G�̕ϐ��̏����l��`
	 */
	enum class EnemyData {
		None
	};
	/**
	 * @enum WeaponData
	 * ����̕ϐ��̏����l��`
	 */
	enum class WeaponData {
		None,
	};
}