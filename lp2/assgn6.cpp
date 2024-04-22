#include <iostream>
#include <vector>
#include <regex>
#include <unordered_map>

using namespace std;

// Define a structure to represent a rule
struct Rule {
    regex pattern;
    string response_key;
};

// Define the restaurant reservation system class
class RestaurantReservationSystem {
private:
    vector<Rule> rules;
    unordered_map<string, string> responses;

public:
    // Constructor
    RestaurantReservationSystem(const vector<Rule>& _rules, const unordered_map<string, string>& _responses) : rules(_rules), responses(_responses) {}

    // Method to respond to user inquiries
    string respond_to_inquiry(const string& inquiry) {
        for (const auto& rule : rules) {
            if (regex_search(inquiry, rule.pattern)) {
                return responses[rule.response_key];
            }
        }
        return responses["default"];
    }
};

int main() {
    // Define rules
    vector<Rule> rules = {
        {regex("\\b(?:hello|hi)\\b"), "greeting"},
        {regex("\\b(?:goodbye|bye)\\b"), "farewell"},
        {regex("\\b(?:reserve|booking)\\b"), "reservation"},
        {regex("\\b(?:table|seat|availability)\\b"), "availability"},
        {regex("\\b(?:menu|food|drink)\\b"), "menu"},
        {regex("\\b(?:location|address)\\b"), "location"},
        {regex("\\b(?:contact|phone|email)\\b"), "contact_info"}
    };

    // Define responses
    unordered_map<string, string> responses = {
        {"reservation", "Certainly! Would you like to make a reservation?"},
        {"availability", "Sure, let me check the availability for you."},
        {"menu", "Here's the link to our menu: [Menu Link]."},
        {"location", "We are located at [Address]."},
        {"contact_info", "You can contact us at [Phone Number] or email us at [Email Address]."},
        {"default", "I'm sorry, I didn't catch that. Could you please repeat?"},
        {"greeting", "Hello! Welcome to our restaurant. How can I assist you today?"},
        {"farewell", "Thank you for choosing our services. Have a great day!"}
    };

    // Create an instance of RestaurantReservationSystem
    RestaurantReservationSystem chatbot(rules, responses);

    // Main loop to simulate customer interaction
    cout << "Welcome to the Restaurant Reservation Chatbot!" << endl;
    cout << "Type 'exit' to end the conversation." << endl;

    while (true) {
        string user_input;
        cout << "Customer: ";
        getline(cin, user_input);

        if (user_input == "exit") {
            break;
        }

        string bot_response = chatbot.respond_to_inquiry(user_input);
        cout << "Chatbot: " << bot_response << endl;
    }

    cout << "Thank you for using the Restaurant Reservation Chatbot. Goodbye!" << endl;

    return 0;
}
