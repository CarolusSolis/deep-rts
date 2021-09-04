

#include "Config.h"
#include "Game.h"


int main() {

    //auto webServer = Webserver("0.0.0.0", 4300, true);
    //webServer.start();

    Config config = Config::defaults();
    config.setConsoleCaptionEnabled(true);
    config.setGUI(false);

    auto g = Game("scenario-find-gold.json", config);

    Player &player0 = g.addPlayer();
    Player &player1 = g.addPlayer();

    g.setMaxFPS(60);
    g.setMaxUPS(60);
    g.start();

    int EPISODES = 100000;

    g.getUnitByNameID("Test1");


    for(auto episode=0; episode < EPISODES; episode++)
    {

        while(!g.isTerminal())
        {
            g.update();
            g.render();
            g.caption();

            //player0.do_action(Random::randInt(Constants::ACTION_MIN, Constants::ACTION_MAX));
            //player1.do_action(Random::randInt(Constants::ACTION_MIN, Constants::ACTION_MAX));

        }

        g.reset();


    }
}





