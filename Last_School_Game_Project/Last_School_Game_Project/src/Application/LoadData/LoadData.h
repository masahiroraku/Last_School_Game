#pragma once

#include"Utility/CSVLoader/CSVLoader.h"
#include"LoadDataKey.h"
#include"LoadDataValue.h"
#include<unordered_map>
#include<sstream>
#include<string>

/**
 * @file LoadData.h
 * @brief ゲームで使う変数の初期値ファイルを読み込むクラス定義ファイル
 * @author 阿曽
 * @date 2017/4/1
 */

 /*! @class LoadData
 *   @brief  ゲームで使う変数の初期値ファイルを読み込むクラス
 */
class LoadData {
private:	
	/// <summary>
	/// コンストラクタ
	/// </summary>
	LoadData();	
	/// <summary>
	/// デストラクタ
	/// </summary>
	~LoadData();

private:	
	/// <summary>
	/// 取得するキャラデータを登録
	/// </summary>
	void Regist();	
	/// <summary>
	/// 読み込むファイルを登録
	/// </summary>
	void RegistLoadFile();

public:	
	/// <summary>
	/// クラスの参照を取得
	/// </summary>
	/// <returns>このクラスの参照</returns>
	static LoadData& GetInstance();
	/// <summary>
	/// ファイルを読み込む
	/// </summary>
	void Load();

private:
	//!読み込んだファイルを入れる配列
	std::unordered_map<LoadDataKey, CSVData> datas;
	//!読み込んだファイルをどこのキャラに入れるかを入れる配列　TODO:これいらないかも
	std::unordered_map<std::string, LoadDataKey> registLoadDatas;
	//!1行目は説明欄なので２行目から読み込む
	const int LoadableRaw = 2;

public:

	/// <summary>
	/// CSVデータから各データの初期値を取得する
	/// </summary>
	/// <param name="key">LoadDataKey　取得したいデータのファイル</param>
	/// <param name="value">LoadDataValue　取得したいデータの初期値</param>
	/// <returns>取得したいデータの初期値</returns>
	template<class T, class Value>
	T GetData(LoadDataKey key, Value value) {
		T dst;
		//読み込んだファイルから文字列を取得
		std::string src = datas.at(key).at(static_cast<int>(value)).at(LoadableRaw);
		std::istringstream(src) >> dst;
		return dst;
	}

	/// <summary>
	/// プレイヤーの初期化データを取得
	/// </summary>
	/// <param name="value">取得したい初期値</param>
	/// <returns>初期値</returns>
	template<class T, class Value>
	T GetData_Player(Value value) {
		return GetData(LoadDataKey::Player, value);
	}
	/// <summary>
	/// 敵の初期化データを取得
	/// </summary>
	/// <param name="value">取得したい初期値</param>
	/// <returns>初期値</returns>
	template<class T, class Value>
	T GetData_Enemy(Value value) {
		return GetData(LoadDataKey::Enemy, value);
	}
	/// <summary>
	/// 武器の初期化データを取得
	/// </summary>
	/// <param name="value">取得したい初期値</param>
	/// <returns>初期値</returns>
	template<class T, class Value>
	T GetData_Weapon(Value value) {
		return GetData(LoadDataKey::Weapon, value);
	}

};

