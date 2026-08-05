#include "GameFlow.h"
GameFlow::GameFlow() {
    currentState = GameState::BuildPhase;
    currentWave = 1;
    phaseTimer = buildPhaseDuration;
}

void GameFlow::update(float deltaTime, float plantHealth, float& plantGrowth) {
    // 1. Stop updating timers if game is already over
    if (currentState == GameState::GameOver || currentState == GameState::Victory) {
        return;
    }

    // 2. Check Loss Condition
    if (plantHealth <= 0.0f) {
        currentState = GameState::GameOver;
        return;
    }

    // 3. Countdown current phase timer
    phaseTimer -= deltaTime;

    // 4. Phase State Machine
    if (currentState == GameState::BuildPhase) {
        if (phaseTimer <= 0.0f) {
            // Switch to Defense Phase
            currentState = GameState::DefensePhase;
            phaseTimer = defensePhaseDuration;
        }
    }
    else if (currentState == GameState::DefensePhase) {
        if (phaseTimer <= 0.0f) {
            // Wave survived! Add 20% plant growth
            plantGrowth += 20.0f;

            // Check Win Condition
            if (plantGrowth >= 100.0f || currentWave >= maxWaves) {
                plantGrowth = 100.0f;
                currentState = GameState::Victory;
            }
            else {
                // Advance to next wave build phase
                currentWave++;
                currentState = GameState::BuildPhase;
                phaseTimer = buildPhaseDuration;
            }
        }
    }
}