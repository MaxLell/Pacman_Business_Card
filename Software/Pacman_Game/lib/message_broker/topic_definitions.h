#pragma once

// This is where eventually the respective topics are created
// For these enums only use the default enumeration! Otherwise 
// the message broker can occupy a ton of space!

// enum class GeneralTopic
// {
//     General = 0,
//     Error,
//     Debug,
//     LAST_TOPIC
// };

// enum class CommunicationTopic
// {
//     Request = 0,
//     Response,
//     Notification,
//     LAST_TOPIC
// };

enum class PacmanLogicTopics {
    Walls = 0,
    LAST_TOPIC
};