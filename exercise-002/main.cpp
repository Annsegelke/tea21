#include <fmt/chrono.h>
#include <fmt/format.h>

#include "CLI/CLI.hpp"
#include "config.h"

auto main(int argc, char **argv) -> int
{
    int count = 20;
    /**
     * CLI11 is a command line parser to add command line options
     * More info at https://github.com/CLIUtils/CLI11#usage
     */
  

    CLI::App app{PROJECT_NAME};
    try
    {
        app.set_version_flag("-V,--version", fmt::format("{} {}", PROJECT_VER, PROJECT_BUILD_DATE));
        app.add_option("-c, --count", count, fmt::format("Create a vector with the given size default: {}", count));
        app.parse(argc, argv);
    }
    catch (const CLI::ParseError &e)
    {
        return app.exit(e);
    }
    std::vector<int> data(count);
    fmt::print("Create a vector with {} elements\n", count);
    /**
     * The {fmt} lib is a cross platform library for printing and formatting text
     * it is much more convenient than std::cout and printf
     * More info at https://fmt.dev/latest/api.html
     */
    fmt::print("Hello, {}!\n", app.get_name());

    /* INSERT YOUR CODE HERE */
    

    srand((unsigned int)time(NULL));  // Initialisiere den Zufallszahlengenerator mit der aktuellen Zeit

    for (int i = 0; i < count; ++i)   // befüllen des Vektors mit den Zufallszahlen von 0 bis 100
    {
        data[i] = rand() % 100;
    } 

    fmt::print("Zufällige Zahlen im Array: ");   // Ausgeben der Zufallszahlen
    for (int i = 0; i < count; ++i) {
        fmt::print("{} ",data[i]);
    }
    fmt::print("\n");

    // sortiere die Zahlen im Vektor:


//Aufgabenteil "Strava für Vektoren":
     auto start = std::chrono::system_clock::now();

    std::sort(data.begin(), data.end()); //hier sortieren
    
    // Aufgabenteil "Strava für Vektoren":
    auto end = std::chrono::system_clock::now();

   fmt::print("Geordnete zufällige Zahlen im Array: ");   // Ausgeben der geordneten Zufallszahlen
    for (int i = 0; i < count; ++i) {  //oder anstatt count data.size() verwenden
        fmt::print("{} ",data[i]);
    }
    fmt::print("\n");    

    
    auto elapsed = end - start;

    // this constructs a duration object using milliseconds
    //auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

    // Ausgabe der Zeiten

    fmt::print("Time for sort {}", elapsed);

    return 0; /* exit gracefully*/
}
