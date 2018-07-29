#include <iostream>
#include "tools.h"

using Eigen::VectorXd;
using Eigen::MatrixXd;
using std::vector;

Tools::Tools() {}

Tools::~Tools() {}

VectorXd Tools::CalculateRMSE(const vector<VectorXd> &estimations,
                              const vector<VectorXd> &ground_truth) {
 
  //initialize the RMSE vector
  VectorXd rmse = VectorXd(4);
  rmse.fill(0.0);
  
  //(1) check if two vectors have the same size, and 
  //(2) check if the vector 'estimations' is empty  
  if (estimations.size() != ground_truth.size() || estimations.size() == 0) {
     cout << "Invalid estimation or ground truth data size!" << endl;
	 return rmse;
  }
  
  for(unsigned int i = 0; i < estimations.size(); i++) {
     VectorXd res = estimations[i] - ground_truth[i];
	 res = res.array() * res.array();
	 rmse += res;
  }
  
  rmse /= estimations.size();
  rmse = rmse.array().sqrt();
  
  return rmse;
}