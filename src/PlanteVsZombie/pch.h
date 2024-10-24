#pragma once
#include <SFML/Graphics.hpp>

#include <iostream>
#include <vector>
#include <map>
#include <string>

#include "Context.hpp"
#include "Behaviour.hpp"
#include "Playground.h"
#include "Action.hpp"
#include "Entity.h"

#ifdef _DEBUG
#include <crtdbg.h>
#define DEBUG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#define new DEBUG_NEW
#endif
