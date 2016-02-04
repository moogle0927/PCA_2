#include<iostream>
#include"model.h"
#include<fstream>
#include<vector>
#include "raw_io.h"
#include "info.h"




int main(int argn, const char *argc[]) {
	info input_info;
	input_info.input(argc[1]);

	

	saito::model<double> pca;
	pca.load_with_N(input_info.dir_def,input_info.d); //•ÏŒ`ê‚Ì‚â‚Â
	//pca.load(input_info.dir_def);
	std::vector<double> result;
	read_vector(result, input_info.dir_result);
	Eigen::MatrixXd result_read = Eigen::Map<Eigen::MatrixXd>(&result[0], input_info.d, 1);
	
	Eigen::Matrix< double, Eigen::Dynamic, Eigen::Dynamic > Y;

	pca.pre_image(Y,result_read);
	
	
	std::string o_file = static_cast<std::string>(input_info.dir_out) + "/mat";
	write_matrix_raw_and_txt(Y, o_file);
	std::ofstream mat(o_file + ".csv");
	for (int i = 0; i < Y.rows(); i++) {
		for (int j = 0; j < Y.cols(); j++) {
			mat << Y(i, j) << ",";
		}
		mat << std::endl;
	}

	return EXIT_SUCCESS;
	system("pause");

}
