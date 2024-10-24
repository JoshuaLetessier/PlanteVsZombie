#pragma once
#include <SFML/Graphics.hpp>

#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <chrono>

#include "Context.hpp"
#include "Behaviour.hpp"
#include "Playground.h"
#include "Action.hpp"
#include "Entity.h"

#define GET_CURRENT_TIME std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()

#ifdef _DEBUG
#include <crtdbg.h>
#define DEBUG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#define new DEBUG_NEW
#endif
