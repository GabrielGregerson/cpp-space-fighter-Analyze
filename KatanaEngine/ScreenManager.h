﻿
/*
     ██╗  ██╗  █████╗  ████████╗  █████╗  ███╗   ██╗  █████╗ 
	 ██║ ██╔╝ ██╔══██╗ ╚══██╔══╝ ██╔══██╗ ████╗  ██║ ██╔══██╗
	 █████╔╝  ███████║    ██║    ███████║ ██╔██╗ ██║ ███████║
	 ██╔═██╗  ██╔══██║    ██║    ██╔══██║ ██║╚██╗██║ ██╔══██║
	 ██║  ██╗ ██║  ██║    ██║    ██║  ██║ ██║ ╚████║ ██║  ██║
	 ╚═╝  ╚═╝ ╚═╝  ╚═╝/\  ╚═╝    ╚═╝  ╚═╝ ╚═╝  ╚═══╝ ╚═╝  ╚═╝
   /vvvvvvvvvvvvvvvvvvv \=========================================,
   `^^^^^^^^^^^^^^^^^^^ /---------------------------------------"
        Katana Engine \/ © 2012 - Shuriken Studios LLC
			    http://www.shurikenstudios.com
*/

#pragma once

namespace KatanaEngine
{
	class Game;

	/** @brief Updates, renders, and manages transitions between instances of the Screen class. */
	class ScreenManager
	{
		friend class Game;

	public:

		/** @brief Instantiate a screen manager object.
			@param pGame A pointer to the game instance. */
		ScreenManager(Game *pGame) : m_pGame(pGame) { }
		virtual ~ScreenManager() { }

		/** @brief Gets a pointer to the Game.
			@return A pointer to the game instance. */
		Game *GetGame() const { return m_pGame; }

		/** @brief Gets a pointer to the ResourceManager, for loading and managing resources.
			@return A pointer to the game's ResourceManager instance. */
		ResourceManager *GetResourceManager() const;

		/** @brief Add a screen to be managed.
			@param pScreen A pointer to the screen to be managed. */
		virtual void AddScreen(Screen *pScreen);

		/** @brief Called when the game has determined that screen logic needs to be processed.
			@param gameTime A reference to the game time object. */
		virtual void Update(const GameTime& gameTime);

		/** @brief Called when the game determines it is time to draw a frame.
			@param spriteBatch A reference to the game's sprite batch, used for rendering. */
		virtual void Draw(SpriteBatch& spriteBatch);


	private:

		Game *m_pGame;

		std::vector<Screen *> m_screens;
		std::vector<Screen *> m_screensToAdd;
		std::vector<Screen *> m_screensToRemove;
		std::vector<Screen *> m_screensToDraw;
		std::vector<Screen *>::reverse_iterator m_rit;

		virtual void HandleInput(const InputState& input);
	};
}