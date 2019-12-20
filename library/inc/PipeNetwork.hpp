#include <iostream>
#include <vector>

namespace cie
{
	namespace pipenetwork
	{
		class PipeNetwork
		{
		public:
			PipeNetwork(const std::string& filename);
			std::vector<double> computeFluxes() const;
			~PipeNetwork();

		private:
			std::vector<Node> nodes_;
			std::vector<Tube> tubes_;
		};
	}
}
