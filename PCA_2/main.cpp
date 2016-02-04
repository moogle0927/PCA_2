#include<iostream>
#include"model.h"
#include<fstream>
#include<vector>
#include "raw_io.h"
#include "info.h"




int main(int argn, const char *argc[]) {
	info input_info;
	input_info.input(argc[1]);

	std::vector<int> s;
	std::vector<int> d;
	std::ifstream s_path(input_info.dir_s);
	std::ifstream d_path(input_info.dir_d);
	std::string buf_s;
	std::string buf_d;
	while (s_path&& getline(s_path, buf_s))
	{
		s.push_back(std::stoi(buf_s));
	}
	while (d_path&& getline(d_path, buf_d))
	{
		d.push_back(std::stoi(buf_d));
	}

	for (int j = 0; j < s.size(); j++) {
		for (int k = 0; k < d.size(); k++) {

			saito::model<double> pca;
			pca.load_with_N(input_info.dir_def, d[k]); //•ÏŒ`ê‚Ì‚â‚Â
			//pca.load(input_info.dir_def);
			std::vector<double> result;
			std::stringstream dir_Result;
			dir_Result << input_info.dir_result << "D" << d[k] << "S" << s[j] << "/" << "test.raw";
			read_vector(result, dir_Result.str());
			Eigen::MatrixXd result_read = Eigen::Map<Eigen::MatrixXd>(&result[0], d[k], 1);

			Eigen::Matrix< double, Eigen::Dynamic, Eigen::Dynamic > Y;

			pca.pre_image(Y, result_read);

			std::stringstream O_file;
			O_file << input_info.dir_out << "/D" << d[k] << "S" << s[j] << "/mat";
			nari::system::make_directry(O_file.str());
			write_matrix_raw_and_txt(Y, O_file.str());
			std::ofstream mat(O_file.str() + ".csv");
			for (int i = 0; i < Y.rows(); i++) {
				for (int j = 0; j < Y.cols(); j++) {
					mat << Y(i, j) << ",";
				}
				mat << std::endl;
			}
		}
	}
	return EXIT_SUCCESS;
	system("pause");

}
