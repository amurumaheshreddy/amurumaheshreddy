class MKAverage {
public:
  MKAverage(int m, int k): 
    sum(0), m(m), k(k), n(m - 2*k) {}
 
  void addElement(int num) {
    if (q.size() == m) {      
      remove(q.front());
      q.pop();
    }
    q.push(num);
    add(num);
  }
 
  int calculateMKAverage() {    
    return (q.size() < m) ? -1 : sum / n;
  }
private:
  void add(int x) {
    left.insert(x);
    
    if (left.size() > k) {
      auto it = prev(end(left));
      sum += *it;
      mid.insert(*it);      
      left.erase(it);
    }
    
    if (mid.size() > n) {
      auto it = prev(end(mid));
      sum -= *it; 
      right.insert(*it);
      mid.erase(it);
    }
  }
  
  void remove(int x) {
    if (x <= *rbegin(left)) {
      left.erase(left.find(x));
    } else if (x <= *rbegin(mid)) {
      sum -= x;
      mid.erase(mid.find(x));
    } else {
      right.erase(right.find(x));
    }
    
    if (left.size() < k) {
      auto it = begin(mid);
      sum -= *it;
      left.insert(*it);
      mid.erase(it);
    }
    
    if (mid.size() < n) {
      auto it = begin(right);
      sum += *it;
      mid.insert(*it);
      right.erase(it);
    }
  }
  
  queue<int> q;
  multiset<int> left, mid, right;  
  long sum;
  const int m;
  const int k;
  const int n;
};