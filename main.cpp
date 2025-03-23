#include"Network.h"
int main() {
    try {
        Network network;

        auto user1 = network.createUser("Alice", "alice@example.com", "Loves coding.");
        auto user2 = network.createUser("Bob", "bob@example.com", "Enjoys hiking.");

        user1->createPost("Hello, this is my first post!");
        user2->createPost("Good morning everyone!");

        user1->createPost("Having a great day!");
        user2->createPost("What a beautiful hike!");

        user1->posts[0]->addComment("Bob", "Nice post, Alice!");
        user2->posts[1]->addComment("Alice", "Sounds like fun, Bob!");

        
        network.sendFriendRequest(user1->getId(), user2->getId());

        
        network.displayAllUsers();

        
        user1->posts[0]->display();
        user2->posts[1]->display();
    } catch (const std::exception& ex) {
        std::cerr << "Error: " << ex.what() << std::endl;
    }

    return 0;
}