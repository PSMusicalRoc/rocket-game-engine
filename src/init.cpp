#include "init.hpp"

void init()
{
    auto fps_ent = create_entity(0, 0);
    fps_ent->labels.emplace_back("ui");
    fps_ent->labels.emplace_back("fps");
    add_component_to_entity<TextRenderer>(TextRenderer(std::string("300"), Fonts::ARIAL), fps_ent);
    Logger::log(LogLevel::INFO, "Added component to FPS Entity!");
    TextRenderer* txt = std::any_cast<TextRenderer>(&fps_ent->component_list.at(0));
    txt->size_and_pos.h = 100;
    txt->size_and_pos.w = 1000;

    auto kiwi = create_entity(0, 0);
    //auto shared = std::make_shared<Animation>(Animation(Spritesheet("res/img/kiwi/Kiwi_Megaman_Battle_Network.png")));
    add_component_to_entity<SpriteRenderer>(SpriteRenderer("idle", Animation(Spritesheet("res/img/kiwi/Kiwi_Megaman_Battle_Network.png"))), kiwi);
    SpriteRenderer* kiwi_sprite = std::any_cast<SpriteRenderer>(&kiwi->component_list.at(0));
    kiwi_sprite->do_clip = true;

    kiwi_sprite->pos = {100, 700, 200, 200};
    kiwi_sprite->switch_animation("idle");

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            for (int k = 0; k < 2; k++)
            {
                add_frame_to_animation(kiwi_sprite->animations.at("idle").get(), {480 * j, 480 * i, 480, 480});
            }
        }
    }

    add_component_to_entity<AnimatedTextRenderer>(AnimatedTextRenderer("Hi there, this is a test of the animated scrolling text!\n"
                                                                        "Hopefully, it's also multiline as well!\n"
                                                                        "Thank you Asher for making the poggers art! :PogU:", Fonts::SMALL_ARIAL, 3), kiwi);
    
    AnimatedTextRenderer* kiwi_text = std::any_cast<AnimatedTextRenderer>(&kiwi->component_list.at(1));
    kiwi_text->size_and_pos.x = 305;
    kiwi_text->size_and_pos.y = 700;


    /*
    Whale Mom Sprite
    */

    auto whale_mom = create_entity(0, 0);
    add_component_to_entity<SpriteRenderer>(SpriteRenderer("idle", Animation(Spritesheet("res/img/whale_mom/Whale_Mom_Megaman_Battle_Network_New.png"))), whale_mom);
    SpriteRenderer* whale_mom_sprite = std::any_cast<SpriteRenderer>(&whale_mom->component_list.at(0));
    whale_mom_sprite->do_clip = true;
    whale_mom_sprite->pos = {100, 400, 200, 200};
    whale_mom_sprite->switch_animation("idle");

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            for (int k = 0; k < 2; k++)
            {
                add_frame_to_animation(whale_mom_sprite->animations.at("idle").get(), {480 * j, 480 * i, 480, 480});
            }
        }
    }
}