#include "LoadData.h"
#include"Utility/FilePass/FilePass.h"
#include <algorithm>
#include <filesystem>
#include<iterator>


LoadData::LoadData()
	: datas()
	, registLoadDatas()
{
	//登録
	RegistLoadFile();
	Regist();
}

LoadData::~LoadData()
{
	//削除
	registLoadDatas.clear();
	datas.clear();
}

void LoadData::Regist()
{
	datas.emplace(LoadDataKey::Player, CSVData(0));
	datas.emplace(LoadDataKey::Enemy, CSVData(0));
	datas.emplace(LoadDataKey::Weapon, CSVData(0));
}

void LoadData::RegistLoadFile()
{
	registLoadDatas.emplace("player.csv", LoadDataKey::Player);
	registLoadDatas.emplace("enemy.csv", LoadDataKey::Enemy);
	registLoadDatas.emplace("weapon.csv", LoadDataKey::Weapon);
}

void LoadData::Load()
{
	namespace sys = std::tr2::sys;
	sys::path p(FilePass::DataFile); // 列挙の起点となるファイルディレクトリ

	std::for_each(sys::directory_iterator(p), sys::directory_iterator(),
		[&](const sys::path& p) {
		if (sys::is_regular_file(p)) { // ファイルなら...
			CSVLoader loader(FilePass::DataFile + p.filename().string());
			
			auto& allData = loader.GetAllData();

			//読み込んだデータの配列をコピー
			//TODO:修正
			std::copy(allData.begin(), allData.end(), std::back_inserter(datas.at(registLoadDatas.at(p.filename().string()))));

		}
	});

}


LoadData & LoadData::GetInstance()
{
	static LoadData instance;
	return instance;
}
