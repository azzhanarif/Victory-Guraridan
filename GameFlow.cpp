#include "GameFlow.h"

GameFlow::GameFlow() {
    currentState = GameState::BuildPhase;
    currentWave = 1;
    phaseTimer = buildPhaseDuration;
}

void GameFlow::update(float deltaTime, float plantHealth, float& plantGrowth) {
    if (currentState == GameState::GameOver || currentState == GameState::Victory) {
        return;
    }

    if (plantHealth <= 0.0f) {
        currentState = GameState::GameOver;
        return;
    }

    phaseTimer -= deltaTime;

    if (currentState == GameState::BuildPhase) {
        if (phaseTimer <= 0.0f) {
            currentState = GameState::DefensePhase;
            phaseTimer = defensePhaseDuration;
        }
    }
    else if (currentState == GameState::DefensePhase) {
        if (phaseTimer <= 0.0f) {
            plantGrowth += 20.0f;

            if (plantGrowth >= 100.0f || currentWave >= maxWaves) {
                plantGrowth = 100.0f;
                currentState = GameState::Victory;
            }
            else {
                currentWave++;
                currentState = GameState::BuildPhase;
                phaseTimer = buildPhaseDuration;
            }
        }
    }
}