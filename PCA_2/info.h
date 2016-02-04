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

	int n; //Ç—á”
	int p; //²”
	int d; //²”
	int n_num;
	//int num_p; //Œ©‚½‚¢å¬•ªƒXƒRƒA‚Ì²”Ô†

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