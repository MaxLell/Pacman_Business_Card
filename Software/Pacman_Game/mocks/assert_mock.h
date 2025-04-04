#pragma once

#include <string>
#include <functional>

void mock_verifyAssertWasTriggered(const std::string &condition, const std::function<void()> &callback);