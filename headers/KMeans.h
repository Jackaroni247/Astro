#include <Eigen/Dense>
#include <vector>
#include <cmath>

using namespace Eigen;
using namespace std;

MatrixXd kMeans(const MatrixXd& dataPoints, int k) {
	MatrixXd means = MatrixXd::Random(k,dataPoints.rows());
	cout << means << '\n';
	return dataPoints;
}
