#include"SLNeuron.h"
#include"SLNeuron.cpp"


int main()
{
	int NofInput=4;
	int Threshold=0;
	int Constant=1;
	int Bias=-1;
	int Limit=100;
	int Range_of_Initial_Weight=10;//weight의 초기화 범위

	std::cout << "Insert # of Input(without bias) :";
	std::cin >> NofInput;

	std::cout << "Insert Value of Threshold : ";
	std::cin >> Threshold;

	std::cout << "Insert Value of Constant(except 0) : ";
	std::cin >> Constant;

	std::cout << "Insert Value of Bias(except 0) : ";
	std::cin >> Bias;

	if (Constant*Bias == 0.0)
	{
		std::cout << "Both Constant and Bias mustn't be 0" << std::endl;
		exit(1);
	}
	std::cout << "Insert Value of limit of Learning : ";
	std::cin >> Limit;
	
	std::cout << "Insert Value of Range for Initializing Weights : ";
	std::cin >> Range_of_Initial_Weight;
	
	std::vector<double> Initial_Weight;

	SLNeuron<double>::IntializeVectorWithRangedRandomValue(Initial_Weight,NofInput+1,Range_of_Initial_Weight);

	SLNeuron<double> *Neuron = new SLNeuron<double>(NofInput,Initial_Weight, Threshold, Constant,Bias,Limit);

	while (!(Neuron->isLearningOver()))
	{
		Neuron->Learn();
	}

	delete Neuron;
	return 0;
}