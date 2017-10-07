#pragma once

/**
 * @file ShapeType.h
 * @brief あたり判定用の基本形状定義ファイル
 * @author 阿曽
 * @date Unknown
 */

 /**
  * @enum ShapeType
  * あたり判定用の基本形状
  */
enum class ShapeType {
	//!球
	BoundingSphere,
	//!カプセル
	Capsule,
	//!線分
	Line,
	//!境界ボックス(AABB)
	BoundingBox,
	//!指向性境界ボックス(OBB)
	OrientedBoundingBox,
	//!形状の数
	Max_Num
};