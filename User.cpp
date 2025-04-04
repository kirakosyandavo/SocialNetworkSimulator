#include"User.h"
using namespace std; 
int User::m_id=0;
void User::addFriend(int friendId){
  friends.push_back(friendId);
}
User::User(const string& username, const string& email, const string& profileDescription){
 id=++m_id;
 m_username=username;
 m_email=email;
 m_profile_description=profileDescription;
}
 void User::removeFriend(int friendId){
   for(int i=0;i<friends.size();i++){
    if(friends[i]==friendId){
        friends.erase(friends.begin()+i);
        cout<<"your friedn is removed"<<endl;
        return;
    }
}
cout<<"there is no such friend"<<endl;    
}
 void User::createPost(const std::string& content){
    posts.push_back(make_shared<Post>(content));
    cout<<"Post is added"<<endl;         
 }
 void User::displayProfile() const{
   cout<<"user id is"<<id<<endl;
   cout<<"username is"<<m_username<<endl;
   cout<<"mail is"<<m_email<<endl;
   cout<<"profile description is"<<m_profile_description<<endl;
 }
 int User::getId() const{
    return id;
 }
 const string& User::getUsername() const{
    return m_username;
 }