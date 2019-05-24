#include <boost/program_options.hpp>

class CommandParser
{
public:
    static CommandParser* getInstance(boost::program_options::variables_map varMap, char* subCmd);
private:
    CommandParser(boost::program_options::variables_map varMap, char* subCmd);

    static CommandParser* instance;
};
