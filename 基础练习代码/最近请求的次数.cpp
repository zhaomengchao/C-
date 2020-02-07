// ‰»Î£∫inputs = ["RecentCounter","ping","ping","ping","ping"],
// inputs = [[],[1],[100],[3001],[3002]]
// ‰≥ˆ£∫[null,1,2,3,3]

class RecentCounter {
public:
    RecentCounter() 
    {
        
    }
	int ping(int t) {
		q.push(t);
		while (q.front() < t - 3000) q.pop();
		return q.size();
	}
private:
	queue<int>q;

};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */