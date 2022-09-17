class BrowserHistory {
    stack <string> history, cache;
public:
    BrowserHistory(string homepage) {
        while (!history.empty()) history.pop();
        while (!cache.empty()) history.pop();
        history.push(homepage);
    }
    
    void visit(string url) {
        history.push(url);
        while (!cache.empty()) cache.pop();
    }
    
    string back(int steps) {
        while (history.size() > 1 && steps > 0) {
            steps--;
            cache.push(history.top());
            history.pop();
        }
        return history.top();
    }
    
    string forward(int steps) {
        while (!cache.empty() && steps > 0) {
            steps--;
            history.push(cache.top());
            cache.pop();
        }
        return history.top();
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */