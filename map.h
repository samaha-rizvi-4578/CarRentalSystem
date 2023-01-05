#ifndef MAP_H
#define MAP_H
class mapping{
	private:
		string destination_name;
		string source_name;
	public:
		int bill;
		void parent_path(int i, int parent[]);
		void display(int source, int destination, int distance[], int parent[]);
		void dijkstra(int map[size][size], int source, int destination);
		int sourceinput();
		int destinationinput();
		void stop_names();
		int time_hour(int distance[], int destination);
		int time_taken(int distance[],int destintaion);
		float billing(int distance[], int destination);
		void take_route();
		int citysource();
		int citydestination();
		void city_names();
		void take_city();
		string getdestination();
		string getsource();
		
};
#endif
