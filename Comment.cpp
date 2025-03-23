#include"Comment.h"
Comment::Comment(const string& username,const string& content){
 m_username=username;
 m_content=content;
 timestamp=time(nullptr);
}
void Comment::display()const{
    cout<<m_username<<"do a comment"<<endl;
    cout<<m_content<<endl;
    cout<<ctime(&timestamp)<<endl;
}