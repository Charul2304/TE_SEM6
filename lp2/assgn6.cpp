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

// Define the expert system class
class ExpertSystem {
private:
    vector<Rule> rules;
    unordered_map<string, string> responses;

public:
    // Constructor
    ExpertSystem(const vector<Rule>& _rules, const unordered_map<string, string>& _responses) : rules(_rules), responses(_responses) {}

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
        {regex("\\b(?:help|support)\\b"), "help"},
        {regex("\\b(?:screen|cracked)\\b"), "screen_cracked"},
        {regex("\\b(?:battery|charge)\\b"), "battery_problem"},
        {regex("\\b(?:software|update|reset)\\b"), "software_issue"},
        {regex("\\b(?:water|damage)\\b"), "water_damage"}
    };

    // Define responses
    unordered_map<string, string> responses = {
        {"greeting", "Hello! Welcome to our mobile repairing shop. How can I assist you today?"},
        {"farewell", "Thank you for choosing our mobile repairing services. Have a great day!"},
        {"help", "Sure, I'm here to help. What issues are you facing with your mobile?"},
        {"screen_cracked", "A cracked screen is a common issue. We can replace the screen for you. Please bring your mobile to our shop, and our technicians will take care of it."},
        {"battery_problem", "If you're experiencing battery issues, we can replace your mobile's battery. Bring it to our shop, and we'll ensure it gets fixed."},
        {"software_issue", "Software issues can often be resolved by resetting your mobile or updating its software. We can assist you with that. Please bring your phone to our shop, and our technicians will help you out."},
        {"water_damage", "Water damage can be critical for mobiles. We suggest immediately turning off your device and bringing it to our shop for professional repair. Do not attempt to power it on."},
        {"default", "I apologize, but I couldn't understand your request."}
    };

    // Create an instance of ExpertSystem
    ExpertSystem chatbot(rules, responses);

    // Main loop to simulate customer interaction
    cout << "Welcome to the Customer Interaction Chatbot!" << endl;
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

    cout << "Thank you for using the Customer Interaction Chatbot. Goodbye!" << endl;

    return 0;
}
