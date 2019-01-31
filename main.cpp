/////////////////////////////////////////////////////
// �����R�[�h�ł��B
// ���K�\���̎���w�K���׋��R�[�h
// @HiguchiRyuya
/////////////////////////////////////////////////////
#include <iostream>
#include <stdio.h>
#include <string>
#include <regex>

#define REGEX_MATCH_NUMBER "1234"

using namespace std;


// ���͊֐�
string Input()
{
	string str;
	cin >> str;
	return str;
}

// �o�͊֐�
void Output(string display,string result)
{
	cout << display << result << endl;
}

// ����
void IsOutputResult(bool bol,string str)
{
	if (bol)
	{
		Output(str, "TRUE");
	}
	else
	{
		Output(str, "FALSE");
	}
}

// �S�̈�v
void RegexAllMatch(string str)
{
	// �S�̈�v�̏���
	regex reg(REGEX_MATCH_NUMBER);
	// ��v����
	IsOutputResult(regex_match(str, reg), "�S�̈�v�̔���->");
}

// �S�̐��l�����o
void RegexAllIntSearch(string str)
{
	regex reg(R"(\d+)");
	IsOutputResult(regex_match(str, reg),"�S�̐��l�̔���->");
}

// �S�̕��������o
void RegexAllCharSearch(string str)
{
	regex reg(R"(\D+)");
	IsOutputResult(regex_match(str, reg), "�S�̕����̔���->");
}

// ���l�������擾
vector<string> RegexGetInt(string str)
{
	auto ite = str.cbegin();
	regex reg(R"((\d+))");
	smatch sm;

	vector<string> result;

	while (regex_search(ite, str.cend(), sm, reg))
	{
		for (int i = 1; i < sm.size() ; ++i)
		{
			result.push_back(sm.str(i).c_str());
		}
		// �}�b�`�������C�e���[�^�[�����炷����
		ite += sm.position(0) + sm.length(0);
	}
	// ���ʂ�Ԃ�
	return result;
}

// �����������擾
vector<string> RegexGetChar(string str)
{
	auto ite = str.cbegin();
	regex reg(R"((\D+))");
	smatch sm;

	vector<string> result;

	while (regex_search(ite, str.cend(), sm, reg))
	{
		for (int i = 1; i < sm.size(); ++i)
		{
			result.push_back(sm.str(i).c_str());
		}
		// �}�b�`�������C�e���[�^�[�����炷����
		ite += sm.position(0) + sm.length(0);
	}
	// ���ʂ�Ԃ�
	return result;
}

// ���K�\��
int main() 
{
	while (true)
	{
		string s = Input();

		// �S�̈�v
		RegexAllMatch(s);

		// �S�̐��l�����o
		RegexAllIntSearch(s);
		
		// �S�̕��������o
		RegexAllCharSearch(s);

		// ���l�������擾
		vector<string> getInt = RegexGetInt(s);

		// �����������擾
		vector<string> getChar = RegexGetChar(s);

		// �A�Ȃ������񂲂Ƃɕ\��
		for (auto it = getInt.begin(); it != getInt.end(); ++it)
		{
			string sint = *it;
			Output("���l�����o���āA���l������\��->", sint);
		}

		// �A�Ȃ����������Ƃɕ\��
		for (auto it = getChar.begin(); it != getChar.end(); ++it)
		{
			string sChar = *it;
			Output("���������o���āA����������\��->", sChar);
		}
	}

	return 0;
}

