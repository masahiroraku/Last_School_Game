#include "LoadData.h"
#include"Utility/FilePass/FilePass.h"
#include <algorithm>
#include <filesystem>
#include<iterator>


LoadData::LoadData()
	: datas()
	, registLoadDatas()
{
	//�o�^
	RegistLoadFile();
	Regist();
}

LoadData::~LoadData()
{
	//�폜
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
	sys::path p(FilePass::DataFile); // �񋓂̋N�_�ƂȂ�t�@�C���f�B���N�g��

	std::for_each(sys::directory_iterator(p), sys::directory_iterator(),
		[&](const sys::path& p) {
		if (sys::is_regular_file(p)) { // �t�@�C���Ȃ�...
			CSVLoader loader(FilePass::DataFile + p.filename().string());
			
			auto& allData = loader.GetAllData();

			//�ǂݍ��񂾃f�[�^�̔z����R�s�[
			//TODO:�C��
			std::copy(allData.begin(), allData.end(), std::back_inserter(datas.at(registLoadDatas.at(p.filename().string()))));

		}
	});

}


LoadData & LoadData::GetInstance()
{
	static LoadData instance;
	return instance;
}
