#include <bits/stdc++.h>

using namespace std;

class FordFulkerson{
public:
	class Edge{
	public:
		int from, to;
		long flow, capacity;
		Edge *residual;

		Edge(int from, int to, int cap){
			this->from = from;
			this->to = to;
			this->capacity = cap;
		}
		bool isResidual(){
			return capacity == 0;
		}
		long remainingCapacity(){
			return capacity-flow;
		}
		void augment(long bottleNeck){
			flow += bottleNeck;
			residual->flow -= bottleNeck;
		}

		void toString(int s, int t){
			string u = (from==s)? "s":( (from==t)?"t":to_string(from) );
			string v = (to==s)? "s":( (to==t)?"t":to_string(to) );
			
			printf("Edge %s -> %s | flow = %3d | capacity = %3d | isResidual: %s",
				u,v,flow,capacity,isResidual());
		}
	};

};

int main(){
	FordFulkerson ff;

}