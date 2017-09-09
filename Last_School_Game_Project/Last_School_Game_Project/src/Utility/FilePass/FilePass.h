#pragma once

/**
 * @file FilePass.h
 * @brief �A�Z�b�g�t�H���_��`�t�@�C��
 * @author ���]
 * @date Unknown
 */

#include<string>

 //! FilePass�̖��O���
namespace FilePass {
	//!�A�Z�b�g�t�H���_�̊K�w
	static const std::string RootPass = "Assets/";
	//!�A�Z�b�g�t�H���_�@+�@���f���t�H���_�̊K�w
	static const std::string ModelFile = RootPass + "Models/";
	//!�A�Z�b�g�t�H���_�@+�@�Q�[���f�[�^�t�H���_�̊K�w
	static const std::string DataFile = RootPass + "Datas/";
	//!�A�Z�b�g�t�H���_�@+�@�e�N�X�`���t�H���_�̊K�w
	static const std::string TextureFile = RootPass + "Textures/";
	//!�A�Z�b�g�t�H���_�@+�@�t�H���g�t�H���_�̊K�w
	static const std::string FontFile = RootPass + "Fonts/";
	//!�A�Z�b�g�t�H���_�@+�@�T�E���h�t�H���_�̊K�w
	static const std::string SoundFile = RootPass + "Sounds/";
	//!�A�Z�b�g�t�H���_�@+�@�G�t�F�N�g�t�H���_�̊K�w
	static const std::string EffectFile = RootPass + "Effects/";
}