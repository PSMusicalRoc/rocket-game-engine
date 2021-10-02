#include "Rendering/RenderingSystem.hpp"

void update_squares(SquareComponent* sqr, SharedPtrEntity entity)
{
    sqr->rectangle.x = entity->x_pos;
    sqr->rectangle.y = entity->y_pos;
    sqr->rectangle.w = sqr->rectangle.h = sqr->side_length;
}

void update_text_renderer(TextRenderer* txt, SharedPtrEntity entity)
{
    txt->size_and_pos.x = entity->x_pos;
    txt->size_and_pos.y = entity->y_pos;

    txt->text_rendered = TTF_RenderText_Solid(txt->font, txt->text.c_str(), {255, 255, 255});
}

void render_ui(SDL_Renderer* renderer)
{
    EntPtrVector entities = search_for_entities_with_component<TextRenderer>();

    for (SharedPtrEntity ent : entities)
    {
        int id = find_component_in_entity<TextRenderer>(ent);
        TextRenderer* txt = std::any_cast<TextRenderer>(&ent->component_list.at(id));

        update_text_renderer(txt, ent);

        SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, txt->text_rendered);
        SDL_RenderCopy(renderer, texture, NULL, &txt->size_and_pos);

        SDL_FreeSurface(txt->text_rendered);
        SDL_DestroyTexture(texture);
    }
}

void render(SDL_Renderer* renderer)
{
    EntPtrVector entities = search_for_entities_with_component<SquareComponent>();

    for (SharedPtrEntity ent : entities)
    {
        int component = find_component_in_entity<SquareComponent>(ent);
        SquareComponent* sqr = std::any_cast<SquareComponent>(&ent->component_list.at(component));

        update_squares(sqr, ent);

        SDL_SetRenderDrawColor(renderer, sqr->color.r, sqr->color.g, sqr->color.b, 255);
        SDL_RenderFillRect(renderer, &sqr->rectangle); 
    }

    entities = search_for_entities_with_component<SpriteRenderer>();

    for (SharedPtrEntity ent : entities)
    {
        int component = find_component_in_entity<SpriteRenderer>(ent);
        SpriteRenderer* sprt = std::any_cast<SpriteRenderer>(&ent->component_list.at(component));

        SpriteRenderer::render(renderer, sprt);
    }
}