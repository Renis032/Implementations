#include <unordered_map>
#include <unordered_set>
#include <cstring>

namespace rsm
{

class graph
{
public:
    void printGraph();

    void addVertex(std::string vertex);
    void addEdge(std::string vertex1, std::string vertex2);

    void removeVertex(std::string vertex);
    void removeEdge(std::string vertex1, std::string vertex2);
private:
    std::unordered_map<std::string, std::unordered_set<std::string>> m_adjList;
};

} // end of namespace rsm
