#include <stdio.h>
#include <SDL.h>
#include <SDL_ttf.h>

#define TRUE 1
#define FALSE 0
#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600
#define FPS 60
#define FRAME_TARGET_TIME (1000/FPS)

// Global variables
int game_is_running = FALSE;
SDL_Window* window = NULL;
SDL_Renderer* renderer = NULL;
int last_frame_time = 0;
int score_player_bottom = 0; // Score for player at bottom
int score_player_top = 0;    // Score for player at top

// Game object struct
struct game_object {
    float x;
    float y;
    float width;
    float height;
    float vel_x;
    float vel_y;
} ball, paddle_bottom, paddle_top;

// Font and text rendering variables
TTF_Font* font = NULL;
SDL_Texture* score_text = NULL;
SDL_Color text_color = { 255, 255, 255, 255 }; // White text color

// Function to initialize the SDL window
int initialize_window(void) {
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        fprintf(stderr, "Error initializing SDL.\n");
        return FALSE;
    }
    window = SDL_CreateWindow(
        NULL,
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        WINDOW_WIDTH,
        WINDOW_HEIGHT,
        SDL_WINDOW_BORDERLESS
    );
    if (!window) {
        fprintf(stderr, "Error creating SDL Window.\n");
        return FALSE;
    }
    renderer = SDL_CreateRenderer(window, -1, 0);
    if (!renderer) {
        fprintf(stderr, "Error creating SDL Renderer.\n");
        return FALSE;
    }

    // Initialize SDL_ttf
    if (TTF_Init() == -1) {
        fprintf(stderr, "Error initializing SDL_ttf: %s\n", TTF_GetError());
        return FALSE;
    }

    // Load font
    font = TTF_OpenFont("Pixelmania.ttf", 16); // Change the font path if needed
    if (!font) {
        fprintf(stderr, "Error loading font: %s\n", TTF_GetError());
        return FALSE;
    }

    return TRUE;
}

// Function to process input events
void process_input(void) {
    SDL_Event event;
    SDL_PollEvent(&event);
    switch (event.type) {
    case SDL_QUIT:
        game_is_running = FALSE;
        break;
    case SDL_KEYDOWN:
        if (event.key.keysym.sym == SDLK_ESCAPE)
            game_is_running = FALSE;
        if (event.key.keysym.sym == SDLK_LEFT)
            paddle_bottom.vel_x = -400;
        if (event.key.keysym.sym == SDLK_RIGHT)
            paddle_bottom.vel_x = +400;
        if (event.key.keysym.sym == SDLK_a)
            paddle_top.vel_x = -400;
        if (event.key.keysym.sym == SDLK_d)
            paddle_top.vel_x = +400;
        break;
    case SDL_KEYUP:
        if (event.key.keysym.sym == SDLK_LEFT)
            paddle_bottom.vel_x = 0;
        if (event.key.keysym.sym == SDLK_RIGHT)
            paddle_bottom.vel_x = 0;
        if (event.key.keysym.sym == SDLK_a)
            paddle_top.vel_x = 0;
        if (event.key.keysym.sym == SDLK_d)
            paddle_top.vel_x = 0;
        break;
    }
}

// Function to set up the game
void setup(void) {
    // Initialize values for the ball object
    ball.width = 15;
    ball.height = 15;
    ball.x = 20;
    ball.y = 20;
    ball.vel_x = 300;
    ball.vel_y = 300;

    // Initialize values for the bottom paddle object
    paddle_bottom.width = 100;
    paddle_bottom.height = 20;
    paddle_bottom.x = (WINDOW_WIDTH / 2) - (paddle_bottom.width / 2);
    paddle_bottom.y = WINDOW_HEIGHT - 40;
    paddle_bottom.vel_x = 0;
    paddle_bottom.vel_y = 0;

    // Initialize values for the top paddle object
    paddle_top.width = 100;
    paddle_top.height = 20;
    paddle_top.x = (WINDOW_WIDTH / 2) - (paddle_top.width / 2);
    paddle_top.y = 20;
    paddle_top.vel_x = 0;
    paddle_top.vel_y = 0;
}

// Function to update game state
void update(void) {
    // Calculate time to wait until the target frame time
    int time_to_wait = FRAME_TARGET_TIME - (SDL_GetTicks() - last_frame_time);

    // Only delay if we are too fast to update this frame
    if (time_to_wait > 0 && time_to_wait <= FRAME_TARGET_TIME)
        SDL_Delay(time_to_wait);

    // Calculate delta time factor for updating objects
    float delta_time = (SDL_GetTicks() - last_frame_time) / 1000.0F;

    // Store milliseconds of the current frame
    last_frame_time = SDL_GetTicks();

    // Update ball and paddle positions
    ball.x += ball.vel_x * delta_time;
    ball.y += ball.vel_y * delta_time;
    paddle_bottom.x += paddle_bottom.vel_x * delta_time;
    paddle_bottom.y += paddle_bottom.vel_y * delta_time;
    paddle_top.x += paddle_top.vel_x * delta_time;
    paddle_top.y += paddle_top.vel_y * delta_time;

    // Check for ball collision with walls
    if (ball.x <= 0 || ball.x + ball.width >= WINDOW_WIDTH)
        ball.vel_x = -ball.vel_x;
    if (ball.y < 0)
        ball.vel_y = -ball.vel_y;

    // Check if ball passed top or bottom of the screen
    if (ball.y + ball.height > WINDOW_HEIGHT) {
        ball.x = WINDOW_WIDTH / 2;
        ball.y = WINDOW_HEIGHT / 2;
        ball.vel_y = -ball.vel_y;
        score_player_top++;
    }
    if (ball.y < 0) {
        ball.x = WINDOW_WIDTH / 2;
        ball.y = WINDOW_HEIGHT / 2;
        ball.vel_y = -ball.vel_y;
        score_player_bottom++;
    }

    // Check for ball collision with paddles
    if (ball.y + ball.height >= paddle_bottom.y && ball.x + ball.width >= paddle_bottom.x && ball.x <= paddle_bottom.x + paddle_bottom.width) {
        ball.vel_y = -ball.vel_y;
    }
    if (ball.y <= paddle_top.y + paddle_top.height && ball.x + ball.width >= paddle_top.x && ball.x <= paddle_top.x + paddle_top.width) {
        ball.vel_y = -ball.vel_y;
    }

    // Prevent paddles from moving outside window boundaries
    if (paddle_bottom.x <= 0)
        paddle_bottom.x = 0;
    if (paddle_bottom.x >= WINDOW_WIDTH - paddle_bottom.width)
        paddle_bottom.x = WINDOW_WIDTH - paddle_bottom.width;
    if (paddle_top.x <= 0)
        paddle_top.x = 0;
    if (paddle_top.x >= WINDOW_WIDTH - paddle_top.width)
        paddle_top.x = WINDOW_WIDTH - paddle_top.width;
}

// Function to render game objects
void render(void) {
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    // Draw ball
    SDL_Rect ball_rect = { (int)ball.x, (int)ball.y, (int)ball.width, (int)ball.height };
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderFillRect(renderer, &ball_rect);

    // Draw bottom paddle
    SDL_Rect paddle_bottom_rect = { (int)paddle_bottom.x, (int)paddle_bottom.y, (int)paddle_bottom.width, (int)paddle_bottom.height };
    SDL_RenderFillRect(renderer, &paddle_bottom_rect);

    // Draw top paddle
    SDL_Rect paddle_top_rect = { (int)paddle_top.x, (int)paddle_top.y, (int)paddle_top.width, (int)paddle_top.height };
    SDL_RenderFillRect(renderer, &paddle_top_rect);

    // Render score text for player at bottom
    char score_str_bottom[20];
    snprintf(score_str_bottom, sizeof(score_str_bottom), "Player Bottom: %d", score_player_bottom);
    SDL_Surface* text_surface_bottom = TTF_RenderText_Solid(font, score_str_bottom, text_color);
    if (text_surface_bottom) {
        SDL_Texture* text_texture_bottom = SDL_CreateTextureFromSurface(renderer, text_surface_bottom);
        SDL_FreeSurface(text_surface_bottom);
        if (text_texture_bottom) {
            SDL_Rect text_rect_bottom = { 10, WINDOW_HEIGHT - 30, 200, 30 };
            SDL_QueryTexture(text_texture_bottom, NULL, NULL, &text_rect_bottom.w, &text_rect_bottom.h);
            SDL_RenderCopy(renderer, text_texture_bottom, NULL, &text_rect_bottom);
            SDL_DestroyTexture(text_texture_bottom);
        }
    }

    // Render score text for player at top
    char score_str_top[20];
    snprintf(score_str_top, sizeof(score_str_top), "Player Top: %d", score_player_top);
    SDL_Surface* text_surface_top = TTF_RenderText_Solid(font, score_str_top, text_color);
    if (text_surface_top) {
        SDL_Texture* text_texture_top = SDL_CreateTextureFromSurface(renderer, text_surface_top);
        SDL_FreeSurface(text_surface_top);
        if (text_texture_top) {
            SDL_Rect text_rect_top = { 10, 10, 200, 30 };
            SDL_QueryTexture(text_texture_top, NULL, NULL, &text_rect_top.w, &text_rect_top.h);
            SDL_RenderCopy(renderer, text_texture_top, NULL, &text_rect_top);
            SDL_DestroyTexture(text_texture_top);
        }
    }

    SDL_RenderPresent(renderer);
}

// Function to destroy SDL window and renderer
void destroy_window(void) {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

// Main function
int main(int argc, char* argv[]) {
    game_is_running = initialize_window();

    setup();

    while (game_is_running) {
        process_input();
        update();
        render();
    }

    destroy_window();

    return 0;
}
