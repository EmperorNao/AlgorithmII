class Solution {
public:
    
    vector<vector<int>> res;

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
    
        vector<int> current = {0};
        next(graph, current, graph.size() - 1);
        return res;
        
    }
    
    void next(vector<vector<int>>& graph, vector<int>& current, int last) {

        for (auto& el: current) {
            
            std::cout << el << " ";
            
        }
        //std::cout << std::endl;
        int cur = current[current.size() - 1];
        if (cur == last) {

            res.push_back(current);
            return;

        }


        for (int i = 0; i < graph[cur].size(); ++i) {

                current.push_back(graph[cur][i]);
                next(graph, current, last);
                current.pop_back();                

        }


    }
    
};