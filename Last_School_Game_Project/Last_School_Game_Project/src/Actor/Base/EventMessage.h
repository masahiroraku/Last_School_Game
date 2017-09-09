#pragma once

/************************************************************
* File Name	: EventMessage.h
* Description	: �A�N�^�[�ɑ΂��čs���C�x���g�̒�`
*																Date		:	Unknown.
*															  Author	:	���]
*************************************************************/
enum class EventMessage {
	//�v���C���[�̍U��
	PlayerAttack,
	//���j�_���[�W��^����
	Explosion,
	//�d�Ȃ�Ȃ��悤�ɉ����o��
	Push,
	//�K�E�Z�Q�[�W�̐��l���グ��
	AttackPoint_Add,
	//�z�������s��
	Drain,
	//�{�X������
	Boss_Dead,
	//�v���C���[������
	Player_Dead,
	//�v���C���[�܂��̓{�X�̎��S�A�j���[�V�����̍Đ��I��
	DeadAnimation_End,
	//��
	Heal,
	//�G�̍U��
	EnemyAttack,
	//�{�X�̃L�b�N
	BossKick,
	//�|�[�Y��ʏI��
	PauseEnd,
	//�{�X�̃`���[�W�J�n
	Boss_Charge,
	//�����n�_�Ɉړ�
	Boss_MoveToSpawnPoint,
	//�������I���
	Boss_EndSpawn,
	Ball_Collide,
	DisableActive,
	BossChangeMode
};