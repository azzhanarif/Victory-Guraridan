#pragma once
#pragma once

enum class GameState {   //@pair ye nayi bkchodi ai hai market me isko gemini krle
    BuildPhase,            //ke why i use enum
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

    GameFlow();
    void update(float deltaTime, float plantHealth, float& plantGrowth);
};
