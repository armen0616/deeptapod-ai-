
#include <iostream>
#include <string>
#include <vector>

class NameCounter {
private:
    std::vector<std::string> names;
    std::string text;
    std::vector<int> nameCounts;

public:
    NameCounter(const std::vector<std::string>& names, const std::string& text)
        : names(names), text(text), nameCounts(names.size(), 0) {}

    void countNames() {
        for (size_t i = 0; i < names.size(); ++i) {
            size_t pos = text.find(names[i]);
            while (pos != std::string::npos) {
                
                text.replace(pos, names[i].length(), "X");
                nameCounts[i]++;
                pos = text.find(names[i], pos + 1); 
            }
        }
    }

    void displayCounts() const {
        std::cout << "Name Counts:" << std::endl;
        for (size_t i = 0; i < names.size(); ++i) {
            std::cout << names[i] << ": " << nameCounts[i] << std::endl;
        }
    }

    void displayModifiedText() const {
        std::cout << "Modified Text:" << std::endl;
        std::cout << text << std::endl;
    }
};

int main() {
  
    std::vector<std::string> names = {
        "Amanda", "Michael", "Jackson", "Nil", "Thomas", "Arevik", "Priya", "Vaghinak", "Anahit", "Sarah",
        "Davit", "David", "Kevin", "Armen", "Emily", "Robert", "Thomas", "Sarah", "Lyuba", "Nikolay", "Jennifer",
        "Marine", "Kevin", "Mariam", "Maria", "Rajesh", "Michelle", "Mika", "Qerob", "Matthew", "Alexander",
        "Luiza", "Emma", "Karine", "Ashot", "Vera", "Jack"
    };

    
    std::string text = "In the bustling coffee shop, Sarah greeted her friend Emily with a warm hug. They were joined by Michael, who had just finished his morning jog. After, Sarah and Emily chatted excitedly about their upcoming trip, while Michael listened intently, sipping on his latte. Soon, Jennifer arrived, followed by David and Amanda. The group laughed and exchanged stories, enjoying each other's company. Later that day, Sarah met up with Matthew for lunch at their favorite sandwich spot. They were surprised to see Emma and Kevin already there, enjoying a meal together. After lunch, Sarah ran into Maria at the grocery store, and they exchanged quick hellos before going their separate ways. As the evening approached, Sarah attended a party hosted by Thomas. Priya and Rajesh were there, along with a crowd of familiar faces. Sarah caught up with Jennifer and Michael, who introduced her to their friend, Amanda. The night was filled with laughter and good conversation, as the group shared stories and made memories together.";

   
    NameCounter nameCounter(names, text);

    
    nameCounter.countNames();

   
    nameCounter.displayCounts();

   
    nameCounter.displayModifiedText();

    return 0;
}
