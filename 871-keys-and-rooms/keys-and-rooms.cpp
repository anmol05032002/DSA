class Solution {
public:

    void dfs(int currentRoom, vector<vector<int>>& rooms, vector<bool>& visited) {
        // Mark the current room as visited
        visited[currentRoom] = true;

        // Grab all keys available in the current room
        for (int key : rooms[currentRoom]) {
            // If we haven't visited the room that this key unlocks, go visit it
            if (!visited[key]) {
                dfs(key, rooms, visited);
            }
        }
    }
 
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool> visited(n, false);

        // Start our depth-first exploration from Room 0
        dfs(0, rooms, visited);

        // If any room remains unvisited, return false
        for (bool isVisited : visited) {
            if (!isVisited) {
                return false;
            }
        }

        return true;
    }
};