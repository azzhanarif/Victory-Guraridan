#pragma once

enum class GameState {  //Pair ye nai bkchodi ai hai market me aik baar enum  k baray mai prhli
    BuildPhase,             // gemini ko dede why used this wgera smjha dega game k pov se
    DefensePhase,
    GameOver,
    Victory
};

class GameFlow {
public:
    GameState currentState;

    int currentWave;
    const int maxWaves = 5;

    float phaseTimer;
    const float buildPhaseDuration = 20.0f;
    const float defensePhaseDuration = 40.0f;

    // Constructor
    GameFlow();

    // Main logic update function
    void update(float deltaTime, float plantHealth, float& plantGrowth);
};