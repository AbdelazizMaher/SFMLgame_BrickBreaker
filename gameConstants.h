#pragma once

struct constants
{
	static constexpr int window_width{ 520 };
	static constexpr int window_height{ 450 };

	static constexpr int window_FramerateLimit{ 60 };

	static constexpr float ball_speed{ 5.0f };

	static constexpr float paddle_height{ 20.0f };
	static constexpr float paddle_speed{ 8.0f };

	static constexpr float brick_width{ 43.0f };
	static constexpr float brick_height{ 20.0f };
	static constexpr float brick_offset{ brick_width / 2.0f };
	static constexpr int brick_columns{ 10 };
	static constexpr int brick_rows{ 4 };
	static constexpr int brick_strength{ 3 };

	static constexpr int player_Lives{ 3 };
};
