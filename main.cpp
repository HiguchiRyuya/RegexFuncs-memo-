/////////////////////////////////////////////////////
// ｋｓコードです。
// 正規表現の自主学習お勉強コード
// @HiguchiRyuya
/////////////////////////////////////////////////////
#include <iostream>
#include <stdio.h>
#include <string>
#include <regex>

#define REGEX_MATCH_NUMBER "1234"

using namespace std;


// 入力関数
string Input()
{
	string str;
	cin >> str;
	return str;
}

// 出力関数
void Output(string display,string result)
{
	cout << display << result << endl;
}

// 判定
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

// 全体一致
void RegexAllMatch(string str)
{
	// 全体一致の条件
	regex reg(REGEX_MATCH_NUMBER);
	// 一致判定
	IsOutputResult(regex_match(str, reg), "全体一致の判定->");
}

// 全体数値を検出
void RegexAllIntSearch(string str)
{
	regex reg(R"(\d+)");
	IsOutputResult(regex_match(str, reg),"全体数値の判定->");
}

// 全体文字を検出
void RegexAllCharSearch(string str)
{
	regex reg(R"(\D+)");
	IsOutputResult(regex_match(str, reg), "全体文字の判定->");
}

// 数値だけを取得
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
		// マッチした分イテレーターをずらす処理
		ite += sm.position(0) + sm.length(0);
	}
	// 結果を返す
	return result;
}

// 文字だけを取得
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
		// マッチした分イテレーターをずらす処理
		ite += sm.position(0) + sm.length(0);
	}
	// 結果を返す
	return result;
}

// 正規表現
int main() 
{
	while (true)
	{
		string s = Input();

		// 全体一致
		RegexAllMatch(s);

		// 全体数値を検出
		RegexAllIntSearch(s);
		
		// 全体文字を検出
		RegexAllCharSearch(s);

		// 数値だけを取得
		vector<string> getInt = RegexGetInt(s);

		// 文字だけを取得
		vector<string> getChar = RegexGetChar(s);

		// 連なった数列ごとに表示
		for (auto it = getInt.begin(); it != getInt.end(); ++it)
		{
			string sint = *it;
			Output("数値を検出して、数値だけを表示->", sint);
		}

		// 連なった文字ごとに表示
		for (auto it = getChar.begin(); it != getChar.end(); ++it)
		{
			string sChar = *it;
			Output("文字を検出して、文字だけを表示->", sChar);
		}
	}

	return 0;
}

