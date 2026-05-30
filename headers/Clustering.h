double getPhaseSpaceDistance(CelestialObject a, CelestialObject b) {
	double distDif = abs(a.dist - b.dist);
	double lDif = abs(a.coords.l - b.coords.l);
	double bDif = abs(a.coords.b - a.coords.b);
	double absDif = sqrt(distDif*distDif + lDif*lDif + bDif*bDif);
	return absDif;
}

//A similarity function that ranges from 0-1
double getSimilarity(CelestialObject a, CelestialObject b) {
	double similarity = exp(-1 * pow(getPhaseSpaceDistance(a,b),2));
	return similarity;
}

//Creates the similarity matrix
vector<vector<double>> similarityMatrix(vector<CelestialObject> dataMatrix) {
	vector<vector<double>> similarityMatrix;
	for(size_t i = 0; i < dataMatrix.size(); i++) {
		for(size_t j = 0; j < dataMatrix.size(); j++) {
			similarityMatrix[i][j] = getSimilarity(dataMatrix[i],dataMatrix[j]);
		}
	}
	return similarityMatrix;
}

//Normalize a matrix
vector<vector<double>> normalizeMatrix(vector<vector<double>> input) {
	vector<vector<double>> output;
	for(size_t i = 0; i < input.size(); i++) {
		double rowSum = 0;
		for(size_t j = 0; j < input[i].size(); j++) {
			rowSum+=input[i][j];
		}
		for(size_t j = 0; j < input[i].size(); j++) {
			output[i][j] =  input[i][j]/rowSum;
		}
	}
	return output;
}

vector<vector<double>> degreeMatrix(vector<vector<double>> similarityMatrix) {
	vector<vector<double>> degreeMatrix;
	for(size_t i = 0; i < similarityMatrix.size(); i++) {
		double rowSum = 0;
		for(size_t j = 0; j < similarityMatrix.size(); j++) {
			rowSum+=similarityMatrix[i][j];
		}
		degreeMatrix[i][i]=rowSum;
	}
	return degreeMatrix;
}

vector<vector<double>> laplacianMatrix(vector<vector<double>> degreeMatrix, vector<vector<double>> similarityMatrix) {
	vector<vector<double>> laplacianMatrix;
	for(size_t i = 0; i < similarityMatrix.size(); i++) {
		for(size_t j = 0; j < similarityMatrix[i].size(); j++) {
			laplacianMatrix[i][j] = similarityMatrix[i][j] + degreeMatrix[i][j];
			if(i==j) {
				laplacianMatrix[i][j]++;
			}
		}
	}
	return laplacianMatrix;
}
