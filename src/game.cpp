#include "game.hpp"

Game::Game(std::string title, int majorVersion, int minorVersion) : window(800, 600, false, majorVersion, minorVersion) {
	this->running = true;
}

Game::Game() : Game("Divamia", 3, 3) {
}

Game::~Game() {
  glfwTerminate();
}

void Game::run() {
  while(this->running && !this->window.shouldClose()) {
	double oldTime = this->time;
	this->time = glfwGetTime();
    update(this->time - oldTime);
    this->window.swapBuffers();
    glfwPollEvents();
  }
}
