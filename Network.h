#ifndef NETWORK
#define NETWORK
#include "User.h"
class Network{
    private:
    std::vector<std::shared_ptr<User>> users;
    std::vector<std::pair<int, int>> friendRequests;
    int nextUserId;
public:
    Network()=default;
    std::shared_ptr<User> createUser(const string& username, const string& email, const string& profileDescription);
    void deleteUser(int userId);
    std::shared_ptr<User> getUserById(int userId) const;
    std::shared_ptr<User> getUserByUsername(const std::string& username) const;
    void sendFriendRequest(int fromUserId, int toUserId);
    void acceptFriendRequest(int fromUserId, int toUserId);
    void displayAllUsers() const;
};
#endif







