class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> m;
        return clone(node, m);
    }
    UndirectedGraphNode* clone(UndirectedGraphNode* node, unordered_map<UndirectedGraphNode*, UndirectedGraphNode*>& m) {
        if (!node) return node;
        if (m.count(node)) return m[node];
        UndirectedGraphNode *newNode = new UndirectedGraphNode(node->label);
        m[node] = newNode;
        for (int i = 0; i < node->neighbors.size(); ++i) {
            (newNode->neighbors).push_back(clone(node->neighbors[i], m));
        }
        return newNode;
    }
};