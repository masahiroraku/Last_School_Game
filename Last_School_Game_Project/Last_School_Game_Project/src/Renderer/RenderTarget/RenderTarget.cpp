#include "RenderTarget.h"

RenderTarget::RenderTarget(int width, int height, bool hdr, bool z_buffer, int bit_depth, int channel)
	: width(width)
	, height(height)
	, texture(-1)
	, vertices()
	, preview_draw_screen(-1)
{

	if (hdr) {
		//浮動小数点テクスチャ
		SetDrawValidFloatTypeGraphCreateFlag(TRUE);
		SetCreateDrawValidGraphChannelNum(channel);
		SetCreateGraphChannelBitDepth(bit_depth);
	}
	else {
		//RGBAの普通のフォーマット（255,255,255,255）
		SetDrawValidFloatTypeGraphCreateFlag(FALSE);
		SetCreateGraphColorBitDepth(bit_depth);
	}

	//Zバッファ作成フラグ
	SetDrawValidGraphCreateZBufferFlag(z_buffer ? TRUE : FALSE);
	//レンダーターゲット用のテクスチャ作成
	texture = MakeScreen(width, height, TRUE);
	//設定をデフォルトに戻す
	SetDrawValidGraphCreateZBufferFlag(TRUE);
	SetDrawValidFloatTypeGraphCreateFlag(FALSE);
	SetCreateDrawValidGraphChannelNum(0);
	SetCreateGraphChannelBitDepth(0);
	SetCreateGraphColorBitDepth(4);
	//レンダーターゲット用のポリゴンデータ作成
	const float w = static_cast<float>(width);
	const float h = static_cast<float>(height);
	//左上			position,rhw, DiffuseColor,SpecularColor, UV
	vertices[0] = { { 0,0,0 },1,{ 255,255,255,255 },{ 0,0,0,0 },0,0,0,0 };
	//右上
	vertices[1] = { { w,0,0 },1,{ 255,255,255,255 },{ 0,0,0,0 },1,0,1,0 };
	//左下
	vertices[2] = { { 0,h,0 },1,{ 255,255,255,255 },{ 0,0,0,0 },0,1,0,1 };
	//右下
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
