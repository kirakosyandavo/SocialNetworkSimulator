#include"Network.h"
std::shared_ptr<User> Network::createUser(const string& username, const string& email, const string& profileDescription){
    auto user=make_shared<User>(username,email,profileDescription);
  users.push_back(user);
  cout<<"User add succesfully"<<endl;
  return user;
}
void Network::deleteUser(int userId){
    for(int i=0;i<users.size();i++){
        if(users[i]->getId()==userId){
            users.erase(users.begin()+i);
            cout<<"User is deleted"<<endl;
            return;
        }
    }
    cout<<"there is no such user"<<endl;

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
                   fromuser->addFriend(fromUserId);
                   touser->addFriend(toUserId);
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
