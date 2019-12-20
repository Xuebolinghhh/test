namespace cie 
{
	namespace pipenetwork
	{
		class Node
		{
		public:
			Node();
			Node(double x, double y, double flow, int id);
			double x() const;
			double y() const;
			double flow() const;
			int id() const;
			~Node();

		private:
			double x_, y_, flow_;
			int id_;
		};
	}
}