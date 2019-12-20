#include <iostream>
#include <fstream>
#include "PipeNetwork.hpp"
#include "Tube.hpp"
#include "Node.hpp"
#include "linalg.hpp"

using namespace cie;
using namespace pipenetwork;

PipeNetwork::PipeNetwork(const std::string& filename) 
{
	std::ifstream infile(filename);

	int numberOfNodes, numberOfTubes;
	infile >> numberOfNodes >> numberOfTubes;

	nodes_.reserve(numberOfNodes);
	tubes_.reserve(numberOfTubes);

	for (int i = 0; i < numberOfNodes; i++)
	{
		double value1, value2, value3;
		int value4;
		infile >> value1 >> value2 >> value3;
		value4 = i;
		Node n(value1, value2, value3, value4);
		nodes_[i] = n;
	}

	for (int i = 0; i < numberOfTubes; i++)
	{
		int id1, id2;
		double d;
		infile >> id1 >> id2 >> d;
		Tube t(&nodes_[id1], &nodes_[id2], d);
		tubes_[i] = t;
	}
}

std::vector<double> PipeNetwork::computeFluxes() const
{
	linalg::Matrix B(8, 8);

}

PipeNetwork::~PipeNetwork()
{ }