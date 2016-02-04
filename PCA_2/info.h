#pragma once
#pragma once
#ifndef __HIST_INFO__
#define __HIST_INFO__
#include<iostream>
#include <string>
#include <algorithm>
#include <vector>

#include <kawamhd.h>

#include <naricommon.h>
#include <nariinfocontroller.h>
#include <narifile.h>

struct info
{
	std::string dir_def;
	std::string dir_out;
	std::string dir_result;

	int n; //症例数
	int p; //軸数
	int d; //軸数
	int n_num;
	//int num_p; //見たい主成分スコアの軸番号

	inline void input(const std::string &path)
	{
		nari::infocontroller info;
		info.load(path);
		
		dir_def = nari::file::add_delim(info.get_as_str("dir_def"));
		dir_out = info.get_as_str("dir_out");
		dir_result = info.get_as_str("dir_result");

		p = info.get_as_int("P");
		d = info.get_as_int("D");

	}

};
#endif