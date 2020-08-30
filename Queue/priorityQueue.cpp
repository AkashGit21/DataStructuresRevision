
class minDAryHeap{
	vector<int> A;
	int D, sz=0, key=0; //Max. no. of childs for every node
	map<int,int> keyToIndex;
public:
	void insert(int kI,int ele);
	void peek();
	void pop();
	bool contains(int ky);
};

void swim(int index){
	for(int par=(i-1)/D;index>0 && A[indexToKey[index]]<A[indexToKey[par]];){
		swap(keyToIndex[indexToKey[index]],keyToIndex[indexToKey[par]]);
		index = par;
		par = (index-1)/D;
	}
}

void minDAryHeap::insert(int kI, int value){
	// kI-keyIndex, value-element to be inserted 
	A[kI] = value;
	keyToIndex[kI] = index;
	indexToKey[sz] = kI;

	swim(sz);
	sz++;
}

void minDAryHeap::remove(int kI){
	
}

bool minDAryHeap::contains(int ky){

}

class priorityQueue{

};