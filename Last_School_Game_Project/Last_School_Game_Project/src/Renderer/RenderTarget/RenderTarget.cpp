#include "RenderTarget.h"

RenderTarget::RenderTarget(int width, int height, bool hdr, bool z_buffer, int bit_depth, int channel)
	: width(width)
	, height(height)
	, texture(-1)
	, vertices()
	, preview_draw_screen(-1)
{

	if (hdr) {
		//���������_�e�N�X�`��
		SetDrawValidFloatTypeGraphCreateFlag(TRUE);
		SetCreateDrawValidGraphChannelNum(channel);
		SetCreateGraphChannelBitDepth(bit_depth);
	}
	else {
		//RGBA�̕��ʂ̃t�H�[�}�b�g�i255,255,255,255�j
		SetDrawValidFloatTypeGraphCreateFlag(FALSE);
		SetCreateGraphColorBitDepth(bit_depth);
	}

	//Z�o�b�t�@�쐬�t���O
	SetDrawValidGraphCreateZBufferFlag(z_buffer ? TRUE : FALSE);
	//�����_�[�^�[�Q�b�g�p�̃e�N�X�`���쐬
	texture = MakeScreen(width, height, TRUE);
	//�ݒ���f�t�H���g�ɖ߂�
	SetDrawValidGraphCreateZBufferFlag(TRUE);
	SetDrawValidFloatTypeGraphCreateFlag(FALSE);
	SetCreateDrawValidGraphChannelNum(0);
	SetCreateGraphChannelBitDepth(0);
	SetCreateGraphColorBitDepth(4);
	//�����_�[�^�[�Q�b�g�p�̃|���S���f�[�^�쐬
	const float w = static_cast<float>(width);
	const float h = static_cast<float>(height);
	//����			position,rhw, DiffuseColor,SpecularColor, UV
	vertices[0] = { { 0,0,0 },1,{ 255,255,255,255 },{ 0,0,0,0 },0,0,0,0 };
	//�E��
	vertices[1] = { { w,0,0 },1,{ 255,255,255,255 },{ 0,0,0,0 },1,0,1,0 };
	//����
	vertices[2] = { { 0,h,0 },1,{ 255,255,255,255 },{ 0,0,0,0 },0,1,0,1 };
	//�E��
	vertices[3] = { { w,h,0 },1,{ 255,255,255,255 },{ 0,0,0,0 },1,1,1,1 };


}

RenderTarget::~RenderTarget()
{
	DeleteGraph(texture);
}

void RenderTarget::Begin()
{
	preview_draw_screen = GetDrawScreen();
	SetDrawScreen(texture);
}

void RenderTarget::End()
{
	SetDrawScreen(preview_draw_screen);
}

void RenderTarget::Draw() const
{
	DrawPrimitive2DToShader(vertices, 4, DX_PRIMTYPE_TRIANGLESTRIP);
}

int RenderTarget::Width() const
{
	return width;
}

int RenderTarget::Height() const
{
	return height;
}

int RenderTarget::Texture() const
{
	return texture;
}
