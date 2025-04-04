#include"Network.h"
#include<algorithm>
using namespace std;
std::shared_ptr<User> Network::createUser(const string& username, const string& email, const string& profileDescription){
    auto user=make_shared<User>(username,email,profileDescription);
  users.push_back(user);
  cout<<"User add succesfully"<<endl;
  return user;
}
void Network::deleteUser(int userId) {
    friendRequests.erase(std::remove_if(friendRequests.begin(), friendRequests.end(),
        [userId](const std::pair<int, int>& req) {
            return req.first == userId || req.second == userId;
        }),
        friendRequests.end()
    );

    auto it = std::remove_if(users.begin(), users.end(),
        [userId](const std::shared_ptr<User>& user) {
            return user->getId() == userId;
        });

    if (it != users.end()) {
        users.erase(it, users.end());
        std::cout << "User deleted successfully." << std::endl;
    } else {
        std::cout << "There is no such user." << std::endl;
    }
}
shared_ptr<User> Network::getUserById(int userId) const{
    for(int i{};i<users.size();i++){
        if(users[i]->getId()==userId){
             return users[i];
        }
    }
    cout<<"there is no such user"<<endl;
    return nullptr;
}
shared_ptr<User> Network::getUserByUsername(const std::string& username) const{
    for(int i=0;i<users.size();i++){
        if(users[i]->getUsername()==username){
            return users[i];
        }
    }
    cout<<"there is no such user"<<endl;
    return nullptr;

}
void Network::sendFriendRequest(int fromUserId, int toUserId){
   shared_ptr<User>fromuser=getUserById(fromUserId);
   if(!fromuser){
     throw invalid_argument("there is no such user");
   }
   shared_ptr<User>touser=getUserById(toUserId);
   if(!touser){
    throw invalid_argument("there is no such user");
   }
   if(fromUserId==toUserId){
    throw invalid_argument("there is no such user");
   }
   friendRequests.push_back({fromUserId,toUserId});
  cout << "Friend request sent from " << fromuser->getUsername() << " to " << touser->getUsername() << ".\n";
}

void Network::acceptFriendRequest(int fromUserId, int toUserId){
   shared_ptr<User>fromuser=getUserById(fromUserId);
    if(!fromuser){
      throw invalid_argument("there is no such user");
    }
    shared_ptr<User>touser=getUserById(toUserId);
    if(!touser){
     throw invalid_argument("there is no such user");
    }
    if(fromUserId==toUserId){
     throw invalid_argument("there is no such user");
    }
     for(int i=0;i<friendRequests.size();i++){
        if(friendRequests[i].first==fromUserId){
            if(friendRequests[i].second==toUserId){
                friendRequests.erase(friendRequests.begin()+i);
                   fromuser->addFriend(toUserId);
                   touser->addFriend(fromUserId);
                   cout<<"they are accepted";
                   return ;
            } 
        }
     }
     throw invalid_argument("there is no such request"); 
}
void Network::displayAllUsers() const{
    for(int i=0;i<users.size();i++){
        users[i]->displayProfile();
        cout<<endl;
    }
}
