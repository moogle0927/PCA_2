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
	std::string dir_s;
	std::string dir_d;

	int n; //�Ǘᐔ
	int p; //����

	int n_num;
	//int num_p; //�������听���X�R�A�̎��ԍ�

	inline void input(const std::string &path)
	{
		nari::infocontroller info;
		info.load(path);
		
		dir_def = nari::file::add_delim(info.get_as_str("dir_def"));
		dir_out = info.get_as_str("dir_out");
		dir_result = info.get_as_str("dir_result");
		dir_s = info.get_as_str("S"); //�����ϐ��̐�
		dir_d = info.get_as_str("D"); //�ړI�ϐ��̐�


		p = info.get_as_int("P");

	}

};
#endif