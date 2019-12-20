#include "Tube.hpp"
#include "Node.hpp"
#include <cmath>

using namespace cie;
using namespace pipenetwork;

Tube::Tube():
	node1_(), node2_(), diameter_(0.0)
{ }

Tube::Tube(Node* node1, Node* node2, double diameter):
	node1_(node1), node2_(node2), diameter_(diameter)
{ }

double Tube::length() const
{
	double a, b;
	a = std::pow(node1_->x() - node2_->x(), 2);
	b = std::pow(node1_->y() - node2_->y(), 2);
	return std::sqrt(a + b);
}

double Tube::permeability() const
{
	double pi = 3.14159265358979323846;
	double g = 9.81;
	double v = 1e-6;
	double B = pi * g * std::pow(diameter_, 4) / (128 * v * length());
}

const Node* Tube::node1() const
{
	return node1_;
}

const Node* Tube::node2() const
{
	return node1_;
}

Tube::~Tube()
{ }
		
